import subprocess
import ipaddress
import socket
import thread
from subprocess import Popen, PIPE

# Define a function to check the device connection
def check_connection(hostName):
    IP = socket.gethostbyname(hostName)
    toping = Popen(['ping', '-c', '3', IP], stdout=PIPE)
    output = toping.communicate()[0]
    hostalive = toping.returncode
    if hostalive == 0:
        print "TRUE"
    else:
        print "FALSE"

# MAIN
try:
    thread.start_new_thread(check_connection,("navioAE-1.local",))
except:
    print "Error: unable to start thread"

while 1:
    pass

