function [pathWorkspace,nameModelSimulink,nameProjectFolder,nameLogs,numRotors,nameRaspi] = generatePathandNames()
pathWorkspace = '/home/ae-grvc/Documentos/Workspace/AutoPilot/';
nameModelSimulink = 'controlAerobi';
nameProjectFolder = 'GRVCAutopilot/';
nameLogs = 'controlAerobi*';
numRotors = 'quad'; %quad hexa octo
nameRaspi = 'navioAE-1.local'; %Model Configuration Parameters/ BoardParameters.DeviceAddress must be changed


% 10.0.0.200      aegrvc_ubi
% 192.168.0.122   aegrvc_GRVC
% 192.168.1.101   aegrvc_barad
% ############################
% 10.0.0.65       navioAE1_ubi
% 192.168.0.116   navioAE1_GRVC
% 192.168.1.100   navioAE1_barad
% ############################
% 10.0.0.65       navioAE2_ubi
% 192.168.0.130   navioAE2_GRVC
% 192.168.1.102   navioAE2_barad

%%sudo usermod -a -G dialout $USER
%%sudo apt-get remove modemmanager

end