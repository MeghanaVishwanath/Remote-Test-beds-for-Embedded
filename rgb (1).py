import Adafruit_BBIO.PWM as PWM
import time
import smbus

PWM.start("P8_19", 50, 1000)
bus = smbus.SMBus(2)
deviceAddr = 0x29
bus.write_byte(deviceAddr,0x80|0x12)
val = bus.read_byte(deviceAddr)
if val == 0x44:
	print("Device found\n")
	bus.write_byte(deviceAddr, 0x80|0x00)
	bus.write_byte(deviceAddr, 0x01|0x02)
	bus.write_byte(deviceAddr, 0x80|0x14)
	n=10
	for i in range(0,n):
		data=bus.read_i2c_block_data(deviceAddr,0)
		clear = data[1] << 8 | data[0]
		red = data[3] << 8 | data[2]
		green = data[5] << 8 | data[4]
		blue = data[7] << 8 | data[6]
		crgb = "C: %s, R: %s, G: %s, B: %s\n" %(clear, red, green, blue)
		print(crgb)
		if (red|green|blue>512 && clear>1028):
			PWM.set_duty_cycle("P8_19",1)
			print("RGB_Output=HIGH")
		else:
			PWM.set_duty_cycle("P8_19",0)
			print("RGB_Output=LOW")
			time.sleep(1)

else:
	print("Device not found.\n")

PWM.stop("P8_19")
PWM.cleanup()