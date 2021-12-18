import Adafruit_BBIO.GPIO as GPIO
import Adafruit_BBIO.PWM as PWM
import time

PWM.start("P8_13", 50, 1000)
GPIO.setup("P9_12", GPIO.IN)
n=10
for i in range(0,n):
	if GPIO.input("P9_12"):
		PWM.set_duty_cycle("P8_13",1)
		print("HIGH")
	else:
		PWM.set_duty_cycle("P8_13",0)
		print("LOW")
	time.sleep(1)
PWM.stop("P8_13")
PWM.cleanup()