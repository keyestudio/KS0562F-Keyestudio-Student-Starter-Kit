# Project 16：Servo

![Img](/media/img-20230215134507.png)

## 16.1. Introduction：                                                                 
Servo is a position control rotary actuator. It mainly consists of a housing, a circuit board, a core-less motor, a gear and a position sensor. 

## 16.2. Components Needed：                                                                 
- 328 PLUS Control Board×1
- Servo*1
- Jumper Wire*3
- USB Cable*1

## 16.3. Component Knowledge：                                                                 
Servo is a position control rotary actuator. It mainly consists of a housing, a circuit board, a core-less motor, a gear and a position detector. Its working principle is that the servo receives the signal sent by MCU or receiver, and produces a reference signal with a period of 20ms and width of 1.5ms, then compares the acquired DC bias voltage to the voltage of the potentiometer and obtains the voltage difference output.

The IC on the circuit board judges the direction of rotation and drives the core-less motor to start to rotate, then the reduction gear transfers power to the swing arm, at the same time, the position detector sends back signals to judge the location. It is suitable for those control systems that require constant change of angle and can be maintained. When the motor speed is fixed, the potentiometer will driven by the reduction gear to rotate, so that the voltage difference is 0 and the motor stops rotating. The general rotation angle range of the servo is 0˚~180˚.

For the servo used in this project, the brown wire is GND, the red one is the power positive pole, and the orange one is the signal wire.

![Img](/media/img-20230215131901.png)

Pulse period of controlling the servo is 20ms(50Hz). The pulse width is 1ms ~ 2ms, and the corresponding position is 0°~ 90°. 

![Img](/media/img-20230215131924.png)

## 16.4. Wiring Diagram： 

**Schematic Diagram：**

![Img](/media/img-20230216170610.png)

**Wiring Diagram：**

![Img](/media/img-20230215132357.png)

## 16.5. Test Code：                                                                  

```c
//*********************************************************************************
int servoPin = 9;//Define the Servo pin

void setup() {
  pinMode(servoPin, OUTPUT);//Set the servo pin to output
}

void loop() {
  servopulse(servoPin, 0);//Rotate servo to 0 degree
  delay(1000);//Delay 1s
  servopulse(servoPin, 45);//Rotate servo to 45 degree
  delay(1000);
  servopulse(servoPin, 90);//Rotate servo to 90 degree
  delay(1000);
}

void servopulse(int pin, int myangle) { //Impulse function
  int pulsewidth = map(myangle, 0, 180, 500, 2500); //Map the angle to pulse width
  for (int i = 0; i < 10; i++) { //Output the pulse for times
    digitalWrite(pin, HIGH);//Put servo pin at a high level
    delayMicroseconds(pulsewidth);//Delay the microseconds of pulse width
    digitalWrite(pin, LOW);//Put servo pin at a low level
    delay(20 - pulsewidth / 1000);
  }
}
//*********************************************************************************
```
## 16.6. Test Result：                                                                      
After uploading the code successfully, wire according to the wiring diagram and power on, the servo rotates 0°, 45° and 90°.
