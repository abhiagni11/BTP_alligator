import serial
import syslog
import time
import datetime
import calendar
import sys

k=1
f = open("data.txt", "w")
ttt = time.time()
f.write( "TIME START : "  ) 
f.write( str(ttt)  ) 
f.write( "\n"  ) 
#The following line is for serial over GPIO
port = '/dev/ttyUSB1'

ard = serial.Serial(port,9600,timeout=5)
while(1):
	try:
		k=k+1
    		print ("TIME NOW")	
    		ttt = time.time()
		ttt=ttt
    		print (ttt)
    		msg = ard.readline()
    		print ("Message from arduino: ")
    		print (msg)
		if k >= 5:
			f.write("t 	") 
			f.write(str(ttt))
			f.write("	c 	"+str(msg))
		else: 
			print("")	   

	except KeyboardInterrupt:
		f.close()
		sys.exit()
