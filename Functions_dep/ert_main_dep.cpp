//
// File: ert_main.cpp
//
// Code generated for Simulink model 'controlAerobi'.
//
// Model version                  : 1.2632
// Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
// C/C++ source code generated on : Wed Sep 19 16:57:53 2018
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives:
//    1. Execution efficiency
//    2. ROM efficiency
//    3. RAM efficiency
// Validation result: Not run
//
#include <stdio.h>
#include <stdlib.h>
#include "controlAerobi.h"
#include "controlAerobi_private.h"
#include "rtwtypes.h"
#include "limits.h"
#include "rt_nonfinite.h"
#include "rt_logging.h"
#include "linuxinitialize.h"
#include <shm_util.h>
#include <shm_channels.h>
#define UNUSED(x)                      x = x
#define QUOTE1(name)                   #name
#define QUOTE(name)                    QUOTE1(name)              // need to expand name 
#ifndef SAVEFILE
# define MATFILE2(file)                #file ".mat"
# define MATFILE1(file)                MATFILE2(file)
# define MATFILE                       MATFILE1(MODEL)
#else
# define MATFILE                       QUOTE(SAVEFILE)
#endif

// Function prototype declaration
void exitFcn(int sig);
void *terminateTask(void *arg);
void *baseRateTask(void *arg);
void *subrateTask(void *arg);
volatile boolean_T stopRequested = false;
volatile boolean_T runModel = true;
sem_t stopSem;
sem_t baserateTaskSem;
pthread_t schedulerThread;
pthread_t baseRateThread;
pthread_t backgroundThread;
unsigned long threadJoinStatus[8];
int terminatingmodel = 0;
//pid_t PID;//Navio Drivers PID

//----------Shared memory global variables--------//
static struct shm_str<shm_RCin> rcin;
static struct shm_str<shm_RCou> rcout;
static struct shm_str<shm_attitudePX4EKF2> att_px4ekf2;
static struct shm_str<shm_imu> imu_lsm9ds1;
static struct shm_str<shm_lightware> sf11c;
static struct shm_str<shm_localPositionPX4EKF2> localposition_px4ekf2;
static struct shm_str<shm_px4flow> px4flow;
static struct shm_str<shm_status> status;
static struct shm_str<shm_svo> svo;
static struct shm_str<shm_totalStation> totalstation;
//----------End shared memory global variables--------//
void *baseRateTask(void *arg)
{
  runModel = (rtmGetErrorStatus(controlAerobi_M) == (NULL)) &&
    !rtmGetStopRequested(controlAerobi_M);
  while (runModel) {
      
      //------------Input from the shared memory------------------///
memcpy(&controlAerobi_U.I_RCinput, get_shm<shm_RCin>(&rcin),sizeof(shm_RCin));

memcpy(&controlAerobi_U.I_attitudePX4EKF2, get_shm<shm_attitudePX4EKF2>(&att_px4ekf2),sizeof(shm_attitudePX4EKF2));
memcpy(&controlAerobi_U.I_imu_lsm, get_shm<shm_imu>(&imu_lsm9ds1),sizeof(shm_imu));
memcpy(&controlAerobi_U.I_sf11c, get_shm<shm_lightware>(&sf11c),sizeof(shm_lightware));
memcpy(&controlAerobi_U.I_localPositionPX4EKF2, get_shm<shm_localPositionPX4EKF2>(&localposition_px4ekf2),sizeof(shm_localPositionPX4EKF2));
memcpy(&controlAerobi_U.I_px4flow, get_shm<shm_px4flow>(&px4flow),sizeof(shm_px4flow));

memcpy(&controlAerobi_U.I_svo, get_shm<shm_svo>(&svo),sizeof(shm_svo));
memcpy(&controlAerobi_U.I_totalStation, get_shm<shm_totalStation>(&totalstation),sizeof(shm_totalStation));
//------------End input from the shared memory------------------///
    sem_wait(&baserateTaskSem);

    // External mode
    {
      boolean_T rtmStopReq = false;
      rtExtModePauseIfNeeded(controlAerobi_M->extModeInfo, 1, &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(controlAerobi_M, true);
      }

      if (rtmGetStopRequested(controlAerobi_M) == true) {
        rtmSetErrorStatus(controlAerobi_M, "Simulation finished");
        break;
      }
    }

    controlAerobi_step();

    // Get model outputs here
    //------------Output from the shared memory------------------///
    if (set_shm<shm_RCou>(&rcout,controlAerobi_Y.O_servoOut) == 0)printf("Error to write in shared memory direction.");
    if (set_shm<shm_status>(&status,controlAerobi_Y.O_status) == 0)printf("Error to write in shared memory direction.");
//------------End output from the shared memory------------------///
    
    rtExtModeCheckEndTrigger();
    stopRequested = !((rtmGetErrorStatus(controlAerobi_M) == (NULL)) &&
                      !rtmGetStopRequested(controlAerobi_M));
    runModel = !stopRequested;
    rt_StopDataLogging(MATFILE, controlAerobi_M->rtwLogInfo);
  }

  runModel = 0;
  terminateTask(arg);
  pthread_exit((void *)0);
  return NULL;
}

void exitFcn(int sig)
{
  UNUSED(sig);
  rtmSetErrorStatus(controlAerobi_M, "stopping the model");
  runModel = 0;
}

void *terminateTask(void *arg)
{
  UNUSED(arg);
  terminatingmodel = 1;
  printf("**terminating the model**\n");
  //kill(PID, 15);
  fflush(stdout);
  
  {
    runModel = 0;

    // Wait for background task to complete
    CHECK_STATUS(pthread_join(backgroundThread,(void *)&threadJoinStatus), 0,
                 "pthread_join");
  }

  rtExtModeShutdown(1);

  // Disable rt_OneStep() here

  // Terminate model
  controlAerobi_terminate();
  sem_post(&stopSem);
  return NULL;
}

void backgroundTask(void *arg)
{
  while (runModel) {
    // External mode
    {
      boolean_T rtmStopReq = false;
      rtExtModeOneStep(controlAerobi_M->extModeInfo, 1, &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(controlAerobi_M, true);
      }
    }
  }
}

int main(int argc, char **argv)
{
  UNUSED(argc);
  UNUSED(argv);
  
  /////////-----------START DRIVERS----------///////////
  //PID = fork();
  //if(PID == 0) {
	    //printf("**starting the drivers**\n");
        //execl("/home/pi/remote/bridge_navio","bridge_navio","rcio","lsm","sf11c","px4flow","svo","totalstation","quad");
        //exit(1);
  //}
  //////////////////////////////////////////////////////
  
  printf("**starting the model**\n");
  fflush(stdout);
  rtmSetErrorStatus(controlAerobi_M, 0);
  rtExtModeParseArgs(argc, (const char_T **)argv, NULL);

  // Initialize model
   /////////-------------Create shared memory-------------////////////////////////
create_shm<shm_RCin>(&rcin,SHM_RCIN,SEM_RCIN);
create_shm<shm_RCou>(&rcout,SHM_RCOUT,SEM_RCOUT);
create_shm<shm_attitudePX4EKF2>(&att_px4ekf2,SHM_ATTPX4,SEM_ATTPX4);
create_shm<shm_imu>(&imu_lsm9ds1,SHM_LSM9DS1,SEM_LSM9DS1);
create_shm<shm_lightware>(&sf11c,SHM_SF11C,SEM_SF11C);
create_shm<shm_localPositionPX4EKF2>(&localposition_px4ekf2,SHM_LOCALPOSPX4,SEM_LOCALPOSPX4);
create_shm<shm_px4flow>(&px4flow,SHM_PX4FLOW,SEM_PX4FLOW);
create_shm<shm_status>(&status,SHM_STATUS,SEM_STATUS);
create_shm<shm_svo>(&svo,SHM_SVO,SEM_SVO);
create_shm<shm_totalStation>(&totalstation,SHM_TOTALSTATION,SEM_TOTALSTATION);
/////////------------End create shared memory-------------//////////////////////
  controlAerobi_initialize();

  // External mode
  rtSetTFinalForExtMode(&rtmGetTFinal(controlAerobi_M));
  rtExtModeCheckInit(1);

  {
    boolean_T rtmStopReq = false;
    rtExtModeWaitForStartPkt(controlAerobi_M->extModeInfo, 1, &rtmStopReq);
    if (rtmStopReq) {
      rtmSetStopRequested(controlAerobi_M, true);
    }
  }

  rtERTExtModeStartMsg();

  // Call RTOS Initialization function
  myRTOSInit(0.0025, 0);

  // Wait for stop semaphore
  sem_wait(&stopSem);
  return 0;
}

//
// File trailer for generated code.
//
// [EOF]
//
