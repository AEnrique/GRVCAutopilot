function isrunning = isBridgeLaunched()
    [~,~,~,~,~,nameRaspi] = generatePathandNames();
    r=raspberrypi(nameRaspi,'pi','raspberry');
    if ~contains(system(r,'ps -aux'),'bridge_navio')
       isrunning = false;
    else
       isrunning = true;
    end
end