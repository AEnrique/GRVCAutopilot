function killPX4()
    [~,~,~,~,~,nameRaspi] = generatePathandNames();
    r=raspberrypi(nameRaspi,'pi','raspberry');
    if contains(system(r,'ps -aux'),'posix_rpi_native/px4') %First: kill PX4
       system(r,'sudo pkill -9 px4');
    end
end
