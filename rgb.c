#include<stdio.h>
#include<stdlib.h>
#include<linux/i2c-dev.h>
#include<sys/ioctl.h>
#include<fcntl.h>
#include<unistd.h>

void main(){
	//Creating a bus
	int file;
	char* bus = "/dev/i2c-2";
	file = open(bus, O_RDWR);
	if(file < 0){
		printf("Failed to open the bus.\n");
		exit(1);
	}
	//I2C device address can be obtained using 
	//i2cdetect -y -r 2
	ioctl(file, I2C_SLAVE, 0x29);
	char config[2];
	config[0] = 0x80;
	config[1] = 0x03;
	write(file, config, 2);
	config[0] = 0x81;
	config[1] = 0x00;
	write(file, config, 2);
	config[0] = 0x83;
	config[1] = 0xFF;
	write(file, config, 2);
	sleep(1);
	char reg[1] = {0x94};
	write(file, reg, 1);
	char data[8] = {0};
	for(int i=0; i<10; i++){
	if(read(file, data, 8) != 8){
		printf("Error\n");
	}
	else{
		int cData = (data[1]*256 + data[0]);
		int red = (data[3]*256 + data[2]);
		int green = (data[5]*256 + data[4]);
		int blue = (data[7]*256 + data[6]);
		
		float luminance = (-0.32466)*(red) + (1.57837)*(green) + (-0.73191)*(blue);
		if(luminance < 0){
			luminance = 0;
		}

		printf("Red color luminance: %d\n", red);
		printf("Green color luminance: %d\n", green);
		printf("Blue color luminance: %d\n", blue);
		printf("IR luminance: %d\n", cData);
		printf("Luminance: %.2f\n", luminance);
	}
	sleep(1);
}
} 

