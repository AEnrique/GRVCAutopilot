function killALL()
    [~,nameModelSimulink,~,~,~,nameRaspi] = generatePathandNames();
    r=raspberrypi(nameRaspi,'pi','raspberry');
    if contains(system(r,'ps -aux'),'posix_rpi_native/px4')
       system(r,'sudo pkill -9 px4');
    end
    if contains(system(r,'ps -aux'),'bridge_navio')
       system(r,'sudo pkill -9 bridge_navio');
    end
     if contains(system(r,'ps -aux'),nameModelSimulink)
       system(r,['sudo pkill -9 ',nameModelSimulink]);
    end
end