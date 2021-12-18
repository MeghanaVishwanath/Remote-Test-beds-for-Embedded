# Sharing Remote Testbeds for Embedded Education

### Motivation
To design an embedded system integrated with different input and output devices and use software algorithms to interface and isolate input/output devices for sharing between multiple users. Also, to explore more about how the embedded system works when accessed remotely.

### Design Goals
Given a test device for embedded systems, enable remote access for multiple users, isolate software and hardware resources (GPIO pins in particular) for these users. Enable sharing of input resources like clock and sensors, and also output devices like radios interfaced with the device. Restrict access to the output pins for each user.

### Hardware/Software Requirements
BeagleBone Black, Light Sensor, Microphones, RGB Sensor, Logic Analyzer, IMU, Bluetooth Module, WiFi radio, Linux PC

### Methodology
- The sensors are interfaced with the Beaglebone Black.
- We launch the server on cloud9 through BeagleBone Black
- Student users will be provided with a configuration file which will give details about the pin configuration and wiring on the BeagleBone Black controller.
- The config file can be a txt file or a bin file.
- We take the user codes and then allocate resources to each user.
- We use multithreading to allocate our resources for each user in case same resources are being accessed.
- We create an output file for each user and send this output file via email to the user.
- The same process is used to let the users use the PWM output

### Team Members Responsibilities
- Aditi Dixit: Hardware Implementation (Interfacing the GPIO Pins, distinguish between input/output pins, and programming the controller)
- Kalyani Patle: Beagle Bone Black booting up and doing the interfacing of the sensors.
- Meghana Vishwanath: Research about the system design and the implementation of the same.

### References
- EmbedInsight: Automated Grading of Embedded Systems Assignments
- MoteLab: A Wireless Sensor Network Testbed
