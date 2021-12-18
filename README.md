# Sharing Remote Testbeds for Embedded Education

### Motivation
To design an embedded system integrated with different input and output devices and use software algorithms to interface and isolate input/output devices for sharing between multiple users. Also, to explore more about how the embedded system works when accessed remotely.

### Design Goals
Given a test device for embedded systems, enable remote access for multiple users, isolate software and hardware resources (GPIO pins in particular) for these users. Enable sharing of input resources like clock and sensors, and also output devices like radios interfaced with the device. Restrict access to the output pins for each user.

### Block Diagram
![](RemoteTestbed(1).png)

### Deliverables
- Explore possible design choices with their pros and cons.
- What are limitations imposed on a given embedded system task like PWM generation due to device sharing?

### Hardware/Software Requirements
BeagleBone Black, Light Sensor, Microphones, RGB Sensor, Logic Analyzer, IMU, Bluetooth Module, WiFi radio, Linux PC

### Team Members Responsibilities
- Aditi Dixit: Hardware Implementation (Interfacing the GPIO Pins, distinguish between input/output pins, and programming the controller)
- Kalyani Patle: Beagle Bone Black booting up and doing the interfacing of the sensors.
- Meghana Vishwanath: Research about the system design and the implementation of the same.

### References
- EmbedInsight: Automated Grading of Embedded Systems Assignments
- MoteLab: A Wireless Sensor Network Testbed
