function getLogs()
    [pathWorkspace,nameModelSimulink,nameProjectFolder,~,~,nameRaspi] = generatePathandNames();
    r=raspberrypi(nameRaspi,'pi','raspberry');
    name = ['/home/pi/logs/',nameModelSimulink,'_'];
    text = system(r,['ls ',name,'*']);
    startNum = extractBetween(text,[nameModelSimulink,'_'],'.txt');
    numTotal = length(strfind(text,name));
    num_flight = str2double(startNum{1});
    while numTotal ~= 0       
        %name = ['/home/pi/',nameModelSimulink,'_',num2str(num_flight),'_'];
        name = ['/home/pi/logs/',nameModelSimulink,'_',num2str(num_flight)];
        num = length(strfind(system(r,['ls ',name,'*']),name));
        numTotal = numTotal - num;
        log = strings(1,num);
        if num ~= 0
            for i=1:num
                log(i) = strcat(name,'.txt');    
                getFile(r,log{i})
            end
            system(r,['rm ',name,'*']);
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            Data = dlmread([nameModelSimulink,'_',num2str(num_flight),'.txt']); %Use a better name that M
            logs_generated=dir([pathWorkspace,nameProjectFolder,'Logs/*.mat']);
            num_logs_generated=size(logs_generated,1);
            name_new = [nameModelSimulink,'_',num2str(num_logs_generated+1)];
            save(name_new, 'Data');
            movefile( [name_new,'.mat'] ,[pathWorkspace,nameProjectFolder,'Logs/']);
            delete *.txt
        end
        num_flight = num_flight + 1;
    end
    
end
