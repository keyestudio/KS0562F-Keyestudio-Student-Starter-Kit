# Project 19：Flame Alarm

![Img](/media/img-20230215155136.png)

## 19.1. Introduction：                                                                 
Fire is a terrible disaster and fire alarm systems are very useful in houses、commercial buildings and factories. In this project, we will leverage a control board to control a flame sensor, a buzzer and a LED to simulate fire alarm devices. 

## 19.2. Components Needed：                                                                   
- 328 PLUS Control Board×1
- Flame Sensor*1
- Red LED*1
- Active Buzzer*1
- NPN Transistor(S8050)×1
- 10KΩ Resistor*1
- 1KΩ Resistor*1
- 220Ω Resistor×1
- Breadboard*1
- Jumper Wires
- USB Cable*1

## 19.3. Component Knowledge：                                                                    
Flame sensor boasts a specially designed infrared receiver tube to detect the flame and then convert the flame brightness into a fluctuating level signal. 

The short pin of the receiving triode is negative pole and the other long pin is positive pole. We should connect the short pin (negative) to 5V and the long pin (positive) to the analog pin, the resistor and GND. 

As shown in the figure below：

![Img](/media/img-20230215155347.png)

<span style="color: rgb(255, 76, 65);">Note: Since vulnerable to radio frequency radiation and temperature changes, the flame sensor should be kept away from heat sources like radiators, heaters and air conditioners, as well as direct irradiation of sunlight, headlights and incandescent light.</span>

## 19.4. Wiring Diagram 1：

**Schematic Diagram：**

![Img](/media/img-20230216175515.png)

**Wiring Diagram：**

![Img](/media/img-20230215162237.png)

## 19.5. Test Code 1：                                                                    
Code to read the flame sensor： 

```c
//**********************************************************************************
int flamepin=A0;// Initialize analog pin A0
int val=0;// Define val as an initial vallue of 0

void setup()
{
Serial.begin(9600);// Set baud rate to 9600
pinMode(flamepin, INPUT); //Set analog pin A0 to"input"
}

void loop()
{
val=analogRead(flamepin);// Read the analog value of the analog pin A0, assign it to val
Serial.println(val);// Print the value val
delay(200);// Wait for 0.2s
}
//**********************************************************************************
```
## 19.6. Test Result 1：                                                                      
After uploading the code successfully, wire according to the wiring diagram and power on, then tap ![Img](/media/img-20230215142037.png) and set the baud rate to 9600.

The serial monitor will print out the analog value read by the flame sensor. When the sensor is closed to fire, the analog value increases, otherwise it will decrease.

![Img](/media/img-20230215152825.png)

## 19.7. Wiring Diagram 2：

**Schematic Diagram：**

![Img](/media/img-20230216175716.png)

**Wiring Diagram：**

![Img](/media/img-20230215164420.png)

## 19.8. Test Code 2：                                                                    
<span style="color: rgb(255, 76, 65);">Note：The threshold of 300 in the code can be changed as required.</span>
<br>
<br>

Code for the flame sensor controls LED and buzzer： 

```c
//**********************************************************************************
const int ledpin = 10;
const int buzzerpin = 12;
const int flamepin = A0;
const int thereshold = 300;

void setup() {
  // Put the setup code here, run it once:
  Serial.begin(9600);
  pinMode(ledpin, OUTPUT);
  pinMode(buzzerpin, OUTPUT);
  pinMode(flamepin, INPUT);
}

void loop() {
  // Put the main code here, run in loop:
  int flamesenseval = analogRead(flamepin);
  Serial.println(flamesenseval);
  if (flamesenseval >= thereshold) {
    digitalWrite (buzzerpin, HIGH); //Turn on the buzzer
    digitalWrite(ledpin, HIGH); // Light LED up
    delay(500); // Delay 0.5s
    digitalWrite (buzzerpin, LOW); //Turn off the buzzer
    digitalWrite(ledpin, LOW); // Light LED off
    delay(500); 
  }
  else
  {
    digitalWrite (buzzerpin, LOW); 
    digitalWrite(ledpin, LOW); 
  }
}
//**********************************************************************************
```
## 19.9. Test Result 2：                                                                      
After uploading the code successfully, wire according to the wiring diagram and power on.

When the flame sensor detects the flame, and the analog value is greater than or equal to 300, then the LED will flash and the buzzer will alarm, otherwise, the LED does not light up and the buzzer does not sound.
