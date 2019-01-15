function shutDownRaspi()
    [~,~,~,~,~,nameRaspi] = generatePathandNames();
    r=raspberrypi(nameRaspi,'pi','raspberry');  
    system(r,'sudo shutdown -h now +1');
    % Shut down
    %r.execute('sudo shutdown -r now'); % Reboot 
 end