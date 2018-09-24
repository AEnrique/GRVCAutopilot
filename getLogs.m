function getLogs()
    [pathWorkspace,nameModelSimulink,nameProjectFolder,nameLogs,numRotors,nameRaspi] = generatePathandNames();
    r=raspberrypi(nameRaspi,'pi','raspberry');
    if contains(system(r,'ps -aux'),'posix_rpi_native/px4') %First: kill PX4
       system(r,'sudo pkill -9 px4');
    end
    name = ['/home/pi/',nameModelSimulink,'_1_'];
    num = length(strfind(system(r,['ls ',name,'*']),name));
    log = strings(1,num);
    if num ~= 0
        for i=1:num
            log(i) = strcat(strcat(name, num2str(i)),'.mat');    
            getFile(r,log{i})
        end
        system(r,['rm ',name,'*']);
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        a = cell(22);
        f = cell(22);
        Data = [];
        for i=1:num
            a{i}=load([nameModelSimulink,'_1_',num2str(i),'.mat']);
            f{i}=fieldnames(a{i});
            Data = [Data;a{i}.(f{i}{1})];
        end

        logs_generated=dir([pathWorkspace,nameProjectFolder,'Logs/*.mat']);
        num_logs_generated=size(logs_generated,1);
        name_new = [nameModelSimulink,'_',num2str(num_logs_generated+1)];
        save(name_new, 'Data');
        movefile( [name_new,'.mat'] ,[pathWorkspace,nameProjectFolder,'Logs/']);
        delete *.mat
    end
    
end
