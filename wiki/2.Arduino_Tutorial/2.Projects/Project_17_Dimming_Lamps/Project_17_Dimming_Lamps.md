# Project 17：Dimming Lamps

![Img](/media/img-20230215135759.png)

## 17.1. Introduction：                                                                 
In this project, we will learn how to simulate I/O ports. There are 8 analog ports on Arduino, which are A0 ~ A7.

The potentiometer used here is an analog value output element.

## 17.2. Components Needed：                                                                 
- 328 PLUS Control Board×1
- Potentiometer*1
- Red LED×1
- 220Ω Resistor×1
- Breadboard*1
- Jumper Wires
- USB Cable*1
- Multimeter×1

## 17.3. Component Knowledge：                                                                 
The potentiometer is a kind of resistor and an analog electronic component, which has two states of 0 and 1(high level and low level). The analog quantity is different, its data state presents a linear state such as 1 ~ 1024.

## 17.4. Wiring Diagram 1：                                                                    
Convert the resistance value of the potentiometer to an analog value and display it on the serial monitor.

**Schematic Diagram：**

![Img](/media/img-20230216172519.png)

**Wiring Diagram：**

![Img](/media/img-20230321165950.jpg)

## 17.5. Test Code 1：                                                                                                                                    
Code to read the analog value of the potentiometer:

```c
//**********************************************************************************
int potpin=A0;//Initialize the analog pin AO of adjustable potentiometer
int val=0;// Define val as an initial value of 0

void setup()
{
Serial.begin(9600);// Set the baud rate to 9600
pinMode(potpin, INPUT); //Set the analog pin AO to "input"
}

void loop()
{
val=analogRead(potpin);// Read the analog value of analog pin A0, assign it to val 
Serial.println(val);// Print the value of val
delay(200); //Delay 0.2s
}
//**********************************************************************************
```
## 17.6. Test Result 1：                                                                      
After uploading the code successfully, wire according to the wiring diagram and power on, then tap![Img](/media/img-20230215142037.png) and set the baud rate to 9600. As you rotate the potentiometer, the displayed value will change.

The figure below shows the analog value it reads:

![Img](/media/img-20230215141946.png)

## 17.7. Wiring Diagram 2 and Test Result 2：
After uploading the code successfully, wire according to the wiring diagram and power on, rotate the knob of the potentiometer and use a multimeter to detect voltage changes.

![Img](/media/img-20230322093532.png)

When the knob of the potentiometer is turned to one end, the multimeter measures 0V.

![Img](/media/img-20230322093744.png)

When the knob of the potentiometer is rotated to the middle, the multimeter measures 2.48V (about 2.5V).

![Img](/media/img-20230322094115.png)

When the knob of the potentiometer is turned to the other end, the multimeter measures the maximum voltage at this time is 4.92V (about 5V).

## 17.8. Wiring Diagram 3：

**Schematic Diagram：**

![Img](/media/img-20230216172356.png)

**Wiring Diagram：**

![Img](/media/img-20230321170006.jpg)

## 17.9. Test Code 3：                                                                                                                                    
Code for the potentiometer controls LED:

```c
//**********************************************************************************
int potpin=A0;// Initialize the analog pin AO of adjustable potentiometer
int ledpin=10;// Initialize the digital pin 10
int val=0;// Define val as an initial value of 0

void setup()
{
Serial.begin(9600);// Set baud rate to 9600
pinMode(ledpin,OUTPUT);// Set digital pin 10 to "output"
pinMode(potpin, INPUT); // Set analog pin A0 to "input"
}

void loop()
{
val=analogRead(potpin);// Read the analog value of analog pin A1, assign it to val 
analogWrite(ledpin,val/4);
Serial.println(val);// Print the value of val
}
//**********************************************************************************
```
## 17.10. Test Result 3：                                                                      
After uploading the code successfully, wire according to the wiring diagram and power on, turn the potentiometer handle and the brightness of the LED will change accordingly. 

