
function get_calibration_params(pathProject,nameModelSimulink)
%pathProject = '/home/ae-grvc/Documentos/Workspace/AutoPilot/contAerobi/calibration/';
file_params = strcat([pathProject,'/calibration/'],'paramsST.params');
fid  = fopen(file_params,'r');

text = textscan(fid,'%s','Delimiter','','endofline','');
text = text{1}{1};

%cal_params = extractBetween(text,'BAT_V_SCALE_IO','CBRK_AIRSPD_CHK');

%ACCELEROMETER
CAL_ACC0_XOFF = extractBetween(extractBetween(text,'CAL_ACC0_XOFF',newline),char(9),char(9));
CAL_ACC0_XSCALE = extractBetween(extractBetween(text,'CAL_ACC0_XSCALE',newline),char(9),char(9));
CAL_ACC0_YOFF = extractBetween(extractBetween(text,'CAL_ACC0_YOFF',newline),char(9),char(9));
CAL_ACC0_YSCALE = extractBetween(extractBetween(text,'CAL_ACC0_YSCALE',newline),char(9),char(9));
CAL_ACC0_ZOFF = extractBetween(extractBetween(text,'CAL_ACC0_ZOFF',newline),char(9),char(9));
CAL_ACC0_ZSCALE = extractBetween(extractBetween(text,'CAL_ACC0_ZSCALE',newline),char(9),char(9));
% CAL_ACC1_XOFF = extractBetween(extractBetween(text,'CAL_ACC1_XOFF',char(10)),char(9),char(9));
% CAL_ACC1_XSCALE = extractBetween(extractBetween(text,'CAL_ACC1_XSCALE',char(10)),char(9),char(9));
% CAL_ACC1_YOFF = extractBetween(extractBetween(text,'CAL_ACC1_YOFF',char(10)),char(9),char(9));
% CAL_ACC1_YSCALE = extractBetween(extractBetween(text,'CAL_ACC1_YSCALE',char(10)),char(9),char(9));
% CAL_ACC1_ZOFF = extractBetween(extractBetween(text,'CAL_ACC1_ZOFF',char(10)),char(9),char(9));
% CAL_ACC1_ZSCALE = extractBetween(extractBetween(text,'CAL_ACC1_ZSCALE',char(10)),char(9),char(9));
% CAL_ACC2_XOFF = extractBetween(extractBetween(text,'CAL_ACC2_XOFF',char(10)),char(9),char(9));
% CAL_ACC2_XSCALE = extractBetween(extractBetween(text,'CAL_ACC2_XSCALE',char(10)),char(9),char(9));
% CAL_ACC2_YOFF = extractBetween(extractBetween(text,'CAL_ACC2_YOFF',char(10)),char(9),char(9));
% CAL_ACC2_YSCALE = extractBetween(extractBetween(text,'CAL_ACC2_YSCALE',char(10)),char(9),char(9));
% CAL_ACC2_ZOFF = extractBetween(extractBetween(text,'CAL_ACC2_ZOFF',char(10)),char(9),char(9));
% CAL_ACC2_ZSCALE = extractBetween(extractBetween(text,'CAL_ACC2_ZSCALE',char(10)),char(9),char(9));

%GYROSCOPE
CAL_GYRO0_XOFF = extractBetween(extractBetween(text,'CAL_GYRO0_XOFF',newline),char(9),char(9));
CAL_GYRO0_XSCALE = extractBetween(extractBetween(text,'CAL_GYRO0_XSCALE',newline),char(9),char(9));
CAL_GYRO0_YOFF = extractBetween(extractBetween(text,'CAL_GYRO0_YOFF',newline),char(9),char(9));
CAL_GYRO0_YSCALE = extractBetween(extractBetween(text,'CAL_GYRO0_YSCALE',newline),char(9),char(9));
CAL_GYRO0_ZOFF = extractBetween(extractBetween(text,'CAL_GYRO0_ZOFF',newline),char(9),char(9));
CAL_GYRO0_ZSCALE = extractBetween(extractBetween(text,'CAL_GYRO0_ZSCALE',newline),char(9),char(9));
% CAL_GYRO1_XOFF = extractBetween(extractBetween(text,'CAL_GYRO1_XOFF',char(10)),char(9),char(9));
% CAL_GYRO1_XSCALE = extractBetween(extractBetween(text,'CAL_GYRO1_XSCALE',char(10)),char(9),char(9));
% CAL_GYRO1_YOFF = extractBetween(extractBetween(text,'CAL_GYRO1_YOFF',char(10)),char(9),char(9));
% CAL_GYRO1_YSCALE = extractBetween(extractBetween(text,'CAL_GYRO1_YSCALE',char(10)),char(9),char(9));
% CAL_GYRO1_ZOFF = extractBetween(extractBetween(text,'CAL_GYRO1_ZOFF',char(10)),char(9),char(9));
% CAL_GYRO1_ZSCALE = extractBetween(extractBetween(text,'CAL_GYRO1_ZSCALE',char(10)),char(9),char(9));
% CAL_GYRO2_XOFF = extractBetween(extractBetween(text,'CAL_GYRO2_XOFF',char(10)),char(9),char(9));
% CAL_GYRO2_XSCALE = extractBetween(extractBetween(text,'CAL_GYRO2_XSCALE',char(10)),char(9),char(9));
% CAL_GYRO2_YOFF = extractBetween(extractBetween(text,'CAL_GYRO2_YOFF',char(10)),char(9),char(9));
% CAL_GYRO2_YSCALE = extractBetween(extractBetween(text,'CAL_GYRO2_YSCALE',char(10)),char(9),char(9));
% CAL_GYRO2_ZOFF = extractBetween(extractBetween(text,'CAL_GYRO2_ZOFF',char(10)),char(9),char(9));
% CAL_GYRO2_ZSCALE = extractBetween(extractBetween(text,'CAL_GYRO2_ZSCALE',char(10)),char(9),char(9));

%MAGNETOMETER
%CAL_MAG0_ROT = extractBetween(extractBetween(text,'CAL_MAG0_ROT',char(10)),char(9),char(9));
CAL_MAG0_XOFF = extractBetween(extractBetween(text,'CAL_MAG0_XOFF',newline),char(9),char(9));
CAL_MAG0_XSCALE = extractBetween(extractBetween(text,'CAL_MAG0_XSCALE',newline),char(9),char(9));
CAL_MAG0_YOFF = extractBetween(extractBetween(text,'CAL_MAG0_YOFF',newline),char(9),char(9));
CAL_MAG0_YSCALE = extractBetween(extractBetween(text,'CAL_MAG0_YSCALE',newline),char(9),char(9));
CAL_MAG0_ZOFF = extractBetween(extractBetween(text,'CAL_MAG0_ZOFF',newline),char(9),char(9));
CAL_MAG0_ZSCALE = extractBetween(extractBetween(text,'CAL_MAG0_ZSCALE',newline),char(9),char(9));
% CAL_MAG1_ROT = extractBetween(extractBetween(text,'CAL_MAG1_ROT',char(10)),char(9),char(9));
% CAL_MAG1_XOFF = extractBetween(extractBetween(text,'CAL_MAG1_XOFF',char(10)),char(9),char(9));
% CAL_MAG1_XSCALE = extractBetween(extractBetween(text,'CAL_MAG1_XSCALE',char(10)),char(9),char(9));
% CAL_MAG1_YOFF = extractBetween(extractBetween(text,'CAL_MAG1_YOFF',char(10)),char(9),char(9));
% CAL_MAG1_YSCALE = extractBetween(extractBetween(text,'CAL_MAG1_YSCALE',char(10)),char(9),char(9));
% CAL_MAG1_ZOFF = extractBetween(extractBetween(text,'CAL_MAG1_ZOFF',char(10)),char(9),char(9));
% CAL_MAG1_ZSCALE = extractBetween(extractBetween(text,'CAL_MAG1_ZSCALE',char(10)),char(9),char(9));
% CAL_MAG2_ROT = extractBetween(extractBetween(text,'CAL_MAG2_ROT',char(10)),char(9),char(9));
% CAL_MAG2_XOFF = extractBetween(extractBetween(text,'CAL_MAG2_XOFF',char(10)),char(9),char(9));
% CAL_MAG2_XSCALE = extractBetween(extractBetween(text,'CAL_MAG2_XSCALE',char(10)),char(9),char(9));
% CAL_MAG2_YOFF = extractBetween(extractBetween(text,'CAL_MAG2_YOFF',char(10)),char(9),char(9));
% CAL_MAG2_YSCALE = extractBetween(extractBetween(text,'CAL_MAG2_YSCALE',char(10)),char(9),char(9));
% CAL_MAG2_ZOFF = extractBetween(extractBetween(text,'CAL_MAG2_ZOFF',char(10)),char(9),char(9));
% CAL_MAG2_ZSCALE = extractBetween(extractBetween(text,'CAL_MAG2_ZSCALE',char(10)),char(9),char(9));
fclose(fid);

%UPADTE PARAMETERS
set_param([nameModelSimulink,'/Sensors/attitude/AttitudeEstimator/calib_accel_lsm/Bias_accel'],'Value',strcat('[',CAL_ACC0_XOFF,';',CAL_ACC0_YOFF,';',CAL_ACC0_ZOFF,']'));
set_param([nameModelSimulink,'/Sensors/attitude/AttitudeEstimator/calib_accel_lsm/M_accel'],'Value',strcat('[',CAL_ACC0_XSCALE,',0,0;0,',CAL_ACC0_YSCALE,',0;0,0,',CAL_ACC0_ZSCALE,']'));

set_param([nameModelSimulink,'/Sensors/attitude/AttitudeEstimator/calib_gyro_lsm/Bias_gyro'],'Value',strcat('[',CAL_GYRO0_XOFF,';',CAL_GYRO0_YOFF,';',CAL_GYRO0_ZOFF,']'));
set_param([nameModelSimulink,'/Sensors/attitude/AttitudeEstimator/calib_gyro_lsm/M_gyro'],'Value',strcat('[',CAL_GYRO0_XSCALE,',0,0;0,',CAL_GYRO0_YSCALE,',0;0,0,-',CAL_GYRO0_ZSCALE,']'));

set_param([nameModelSimulink,'/Sensors/attitude/AttitudeEstimator/calib_magnet_lsm/Bias_magnet'],'Value',strcat('[',CAL_MAG0_XOFF,';',CAL_MAG0_YOFF,';',CAL_MAG0_ZOFF,']'));
set_param([nameModelSimulink,'/Sensors/attitude/AttitudeEstimator/calib_magnet_lsm/M_magnet'],'Value',strcat('[',CAL_MAG0_XSCALE,',0,0;0,',CAL_MAG0_YSCALE,',0;0,0,',CAL_MAG0_ZSCALE,']'));

end