function [ip,check] = isConnected(ip_address)
    if isempty(ip_address)
        [~,~,~,~,~,nameRaspi] = generatePathandNames();
        ip = '';
        [~,result] = system(['ping -c 3 -W 1 ',nameRaspi]);
        packets = extractBetween(result,'packets transmitted, ',' received');
    else
        [~,result] = system(['ping -c 3 -W 1 ',ip_address]);
        ip = ip_address;
        packets = extractBetween(result,'packets transmitted, ',' received');
    end
    if ~isempty(packets)
        if str2double(packets{1}) > 0
            check = 1;
            ip = extractBetween(result,'64 bytes from ',': icmp_seq=1');
            if length(ip{1}) > 15
                ip = extractBetween(ip{1},'(',')');
            end
        else
            check = 0;
        end
    else
        check = 0;
    end
 end