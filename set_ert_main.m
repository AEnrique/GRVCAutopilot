%%TODO: 
%-hay que tratar de distinta manera los puertos de entrada y salida.
%-Tiene que ser gen�rico, para todo modelo, con todo tipo de entrada/salida de
%datos, utilizando ert_main original y modificandolo despu�s.


%--D:\Eclipse_Workspaces\workspace_rasp\AutoPilot\contAerobi\controlAerobi_ert\controlAerobi.h
%clear all
function set_ert_main(pathProject,nameProject,numRotors)

%fid  = fopen('D:\Eclipse_Workspaces\workspace_rasp\AutoPilot\contAerobi\controlAerobi_ert\controlAerobi.h','r');
%D:\Eclipse_Workspaces\workspace_rasp\AutoPilot\contAerobi\ert_main.cpp
%%%----Generate variables

file_h = strcat(pathProject,nameProject,'_ert_rtw/',nameProject,'.h');
file_main = strcat(pathProject,'/ert_main.cpp');
inputs_var = strcat('ExternalInputs_',nameProject,';');
outputs_var = strcat('ExternalOutputs_',nameProject,';');
N_inputs_var = strcat(nameProject,'_U');
N_outputs_var = strcat(nameProject,'_Y');
%%%%%%%%%%%%%%%%%%%%%%%%%
fid  = fopen(file_h,'r');%fid  = fopen('D:\Eclipse_Workspaces\workspace_rasp\AutoPilot\contAerobi\controlAerobi_ert\controlAerobi.h','r');
text = textscan(fid,'%s','Delimiter','','endofline','');
text = text{1}{1};


info_ext_inputs = extractBetween(text,'// External inputs (root inport signals with auto storage)',inputs_var);
info_ext_outputs = extractBetween(text,'// External outputs (root outports fed by signals with auto storage)',outputs_var);

load('Navio2_bus.mat');
interfaces = who('shm*');
N_input_ports = 0;
N_output_ports = 0;

for i=1:length(interfaces)
    if contains(info_ext_inputs,interfaces{i})
        num_in = length(strfind(info_ext_inputs,interfaces{i}));
    else
        num_in = 0;
    end
    if contains(info_ext_outputs,interfaces{i})
        num_out = length(strfind(info_ext_outputs,interfaces{i}));
    else
        num_out = 0;
    end
    if num_in > 0   
        N_input_ports = N_input_ports+num_in;
    end
    if num_out > 0
       N_output_ports = N_output_ports+num_out;
    end
end

port_name = cell(N_input_ports+N_output_ports,1);
port_type = cell(N_input_ports+N_output_ports,1);
k = 0;
for i=1:length(interfaces)
    name = extractBetween(info_ext_inputs,[interfaces{i},' '],';');
    for j=1:length(name)
        k = k+1;
        port_name{k} = name{j};
        port_type{k} = interfaces{i};
    end
    name = extractBetween(info_ext_outputs,[interfaces{i},' '],';');
    for j=1:length(name)
        k = k+1;
        port_name{k} = name{j};
        port_type{k} = interfaces{i};
    end
end
ports=[port_name,port_type];
fclose(fid);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%----CHECK PORTS MODIFIED---------------------%%
 %fidmain  = fopen('D:\Eclipse_Workspaces\workspace_rasp\AutoPilot\contAerobi\ert_main.cpp','r');
 fidmain  = fopen(file_main,'r');
 text = textscan(fidmain,'%s','Delimiter','','endofline','');
 text = text{1}{1};
 changed = false;
 %N_input=length(strfind(text,'controlAerobi_U'));
 N_input=length(strfind(text,N_inputs_var));
 
 %N_output=length(strfind(text,'controlAerobi_Y'));
 N_output=length(strfind(text,N_outputs_var));
 
 if N_input_ports~=N_input || N_output_ports~=N_output
     changed=true;
     disp('1.Input and/or output external ports have been changed.');
 else
     for i=1:length(ports) 
         if isempty(strfind(text,ports(i,1)))
             changed=true;
             disp('2.Input and/or output external ports have been changed.');
             break;
         end
     end
 end
 ports(strcmp('',ports)) = [];%Remove empty elements 
 fclose(fidmain);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%----MODIFY ERT_MAIN WITH NAVIO INTERFACES---%%
if changed == true 
    %buffer = fileread('D:\Eclipse_Workspaces\workspace_rasp\AutoPilot\contAerobi\ert_main.cpp');
    buffer = fileread(file_main);
    shared_memory_global=string();
    input_shared_memory=string();
    output_shared_memory=string();
    create_shared_memory=string();
    launch_drivers='\n        execl("/home/pi/remote/driversNavio2","driversNavio2"';
    for i=1:length(ports)
        if i==1
            shared_memory_global=strcat(shared_memory_global,'\n');
            input_shared_memory=strcat(input_shared_memory,'\n');
            output_shared_memory=strcat(output_shared_memory,'\n');
            create_shared_memory=strcat(create_shared_memory,'\n');   
        end
        
        switch ports{i,2}
            case 'shm_imu'
                %disp('1.exist');
                if ~isempty(strfind(ports{i,1},'mpu'))
                    shared_memory_global=strcat(shared_memory_global,'static struct shm_str<shm_imu> imu_mpu9250;');
                    input_shared_memory=strcat(input_shared_memory,'memcpy(&',N_inputs_var,'.',ports{i,1},', get_shm<shm_imu>(&imu_mpu9250),sizeof(shm_imu));');
                    output_shared_memory=strcat(output_shared_memory,'');
                    create_shared_memory=strcat(create_shared_memory,'create_shm<shm_imu>(&imu_mpu9250,SHM_MPU9250,SEM_MPU9250);');
                    launch_drivers=strcat(launch_drivers,',"mpu"');
                elseif ~isempty(strfind(ports{i,1},'lsm'))
                    shared_memory_global=strcat(shared_memory_global,'static struct shm_str<shm_imu> imu_lsm9ds1;');
                    input_shared_memory=strcat(input_shared_memory,'memcpy(&',N_inputs_var,'.',ports{i,1},', get_shm<shm_imu>(&imu_lsm9ds1),sizeof(shm_imu));');
                    output_shared_memory=strcat(output_shared_memory,'');
                    create_shared_memory=strcat(create_shared_memory,'create_shm<shm_imu>(&imu_lsm9ds1,SHM_LSM9DS1,SEM_LSM9DS1);');
                    launch_drivers=strcat(launch_drivers,',"lsm"');                
                end

            case 'shm_RCin'
                %disp('2.exist');
                shared_memory_global=strcat(shared_memory_global,'static struct shm_str<shm_RCin> rcin;');
                input_shared_memory=strcat(input_shared_memory,'memcpy(&',N_inputs_var,'.',ports(i,1),', get_shm<shm_RCin>(&rcin),sizeof(shm_RCin));');
                output_shared_memory=strcat(output_shared_memory,'');
                create_shared_memory=strcat(create_shared_memory,'create_shm<shm_RCin>(&rcin,SHM_RCIN,SEM_RCIN);');
                launch_drivers=strcat(launch_drivers,',"rcio"');     
                %break;
            case 'shm_ahrs'
                %disp('3.exist');
                shared_memory_global=strcat(shared_memory_global,'static struct shm_str<shm_ahrs> ahrs;');
                input_shared_memory=strcat(input_shared_memory,'memcpy(&',N_inputs_var,'.',ports(i,1),', get_shm<shm_ahrs>(&ahrs),sizeof(shm_ahrs));');
                output_shared_memory=strcat(output_shared_memory,'');
                create_shared_memory=strcat(create_shared_memory,'create_shm<shm_ahrs>(&ahrs,SHM_AHRS,SEM_AHRS);');
                launch_drivers=strcat(launch_drivers,',"ahrs"');     
                %break;
            case 'shm_lightware'
                %disp('4.exist');
                shared_memory_global=strcat(shared_memory_global,'static struct shm_str<shm_lightware> sf11c;');
                input_shared_memory=strcat(input_shared_memory,'memcpy(&',N_inputs_var,'.',ports(i,1),', get_shm<shm_lightware>(&sf11c),sizeof(shm_lightware));');
                output_shared_memory=strcat(output_shared_memory,'');
                create_shared_memory=strcat(create_shared_memory,'create_shm<shm_lightware>(&sf11c,SHM_SF11C,SEM_SF11C);');
                launch_drivers=strcat(launch_drivers,',"sf11c"');     
                %break;
            case 'shm_adc'
                %disp('5.exist');
                shared_memory_global=strcat(shared_memory_global,'static struct shm_str<shm_adc> adc;');
                input_shared_memory=strcat(input_shared_memory,'memcpy(&',N_inputs_var,'.',ports(i,1),', get_shm<shm_adc>(&adc),sizeof(shm_adc));');
                output_shared_memory=strcat(output_shared_memory,'');
                create_shared_memory=strcat(create_shared_memory,'create_shm<shm_adc>(&adc,SHM_ADC,SEM_ADC);');
                launch_drivers=strcat(launch_drivers,',"adc"');     
                %break;
            case 'shm_barometer'
                %disp('6.exist');
                shared_memory_global=strcat(shared_memory_global,'static struct shm_str<shm_barometer> baro;');
                input_shared_memory=strcat(input_shared_memory,'memcpy(&',N_inputs_var,'.',ports(i,1),', get_shm<shm_barometer>(&baro),sizeof(shm_barometer));');
                output_shared_memory=strcat(output_shared_memory,'');
                create_shared_memory=strcat(create_shared_memory,'create_shm<shm_barometer>(&baro,SHM_MS5611,SEM_MS5611);');
                launch_drivers=strcat(launch_drivers,',"baro"');     
                %break;
            case 'shm_totalStation'
                %disp('7.exist');
                shared_memory_global=strcat(shared_memory_global,'static struct shm_str<shm_totalStation> totalstation;');
                input_shared_memory=strcat(input_shared_memory,'memcpy(&',N_inputs_var,'.',ports(i,1),', get_shm<shm_totalStation>(&totalstation),sizeof(shm_totalStation));');
                output_shared_memory=strcat(output_shared_memory,'');
                create_shared_memory=strcat(create_shared_memory,'create_shm<shm_totalStation>(&totalstation,SHM_TOTALSTATION,SEM_TOTALSTATION);');
                launch_drivers=strcat(launch_drivers,',"totalstation"');     
                %break;
            case 'shm_gps'
                %disp('7.exist');
                shared_memory_global=strcat(shared_memory_global,'static struct shm_str<shm_gps> gps;');
                input_shared_memory=strcat(input_shared_memory,'memcpy(&',N_inputs_var,'.',ports(i,1),', get_shm<shm_gps>(&gps),sizeof(shm_gps));');
                output_shared_memory=strcat(output_shared_memory,'');
                create_shared_memory=strcat(create_shared_memory,'create_shm<shm_gps>(&gps,SHM_GPS,SEM_GPS);');
                launch_drivers=strcat(launch_drivers,',"gps"');     
                %break;    
            case 'shm_px4flow'
                %disp('7.exist');
                shared_memory_global=strcat(shared_memory_global,'static struct shm_str<shm_px4flow> px4flow;');
                input_shared_memory=strcat(input_shared_memory,'memcpy(&',N_inputs_var,'.',ports(i,1),', get_shm<shm_px4flow>(&px4flow),sizeof(shm_px4flow));');
                output_shared_memory=strcat(output_shared_memory,'');
                create_shared_memory=strcat(create_shared_memory,'create_shm<shm_px4flow>(&px4flow,SHM_PX4FLOW,SEM_PX4FLOW);');
                launch_drivers=strcat(launch_drivers,',"px4flow"');     
                %break;    
            case 'shm_RCou'
                %disp('8.exist');
                shared_memory_global=strcat(shared_memory_global,'static struct shm_str<shm_RCou> rcout;');
                input_shared_memory=strcat(input_shared_memory,'');
                output_shared_memory=strcat(output_shared_memory,'    if (set_shm<shm_RCou>(&rcout, ',N_outputs_var,'.',ports(i,1),') == 0)printf("Error to write in shared memory direction.");\n');
                create_shared_memory=strcat(create_shared_memory,'create_shm<shm_RCou>(&rcout,SHM_RCOUT,SEM_RCOUT);');
                launch_drivers=strcat(launch_drivers,'');     
                %break;
        end
        shared_memory_global=strcat(shared_memory_global,'\n');
        input_shared_memory=strcat(input_shared_memory,'\n');
        output_shared_memory=strcat(output_shared_memory,'');
        create_shared_memory=strcat(create_shared_memory,'\n');   
    end

    launch_drivers=strcat(launch_drivers,[',"',numRotors,'");\n']);     
    buffer = replaceBetween(buffer,'//----------Shared memory global variables--------//','//----------End shared memory global variables--------//',compose(shared_memory_global));
    buffer = replaceBetween(buffer,'//------------Input from the shared memory------------------///','//------------End input from the shared memory------------------///',compose(input_shared_memory));
    buffer = replaceBetween(buffer,'//------------Output from the shared memory------------------///','//------------End output from the shared memory------------------///',compose(output_shared_memory));
    buffer = replaceBetween(buffer,'/////////-------------Create shared memory-------------////////////////////////','/////////------------End create shared memory-------------//////////////////////',compose(create_shared_memory));
    buffer = replaceBetween(buffer,'printf("**starting the drivers**\n");','exit(1)',compose(launch_drivers));
    %tline = fgets(fileID);
    %while ischar(tline)
    %    if ~isempty(strfind(tline,'//----------Shared memory global variables--------//'))
    %        disp(tline);
    %    end
    %    tline = fgets(fileID);
    %end
    
    %fileID = fopen('D:\Eclipse_Workspaces\workspace_rasp\AutoPilot\contAerobi\ert_main.cpp','w');
    fileID = fopen(file_main,'w');
    fwrite(fileID, buffer) ;
    fclose(fileID);
else
    disp('Input and/or output external ports have NOT been changed.');
end

