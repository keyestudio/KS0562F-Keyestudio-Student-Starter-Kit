# Project 18：Light-controlled Lights

![Img](/media/img-20230215144944.png)

## 18.1. Introduction：                                                                 
Some public street lights automatically turn on at night and turn off during the day. In fact, these are subject to photosensitive elements, which can sense the intensity of external ambient light.

In this project, we will use a mainboard to control the LED to achieve the effect of the street lights.

## 18.2. Components Needed：                                                                   
- 328 PLUS Control Board×1
- Photoresistor*1
- Red LED*1
- 10KΩ Resistor*1
- 220Ω Resistor*1
- Breadboard*1
- Jumper Wires
- USB Cable*1

## 18.3. Component Knowledge：                                                                    
**Photoresistor：** Its principle is that the brightness (light) received on the surface of the photoresistor decreases the resistance, and the resistance value changes with the intensity of the detected ambient light. With this feature, we can use a photoresistor to detect light intensity. 

The photoresistor and its electronic symbol are as follows:

![Img](/media/img-20230215145119.png)

The following circuit is used to detect the change of the resistance value:

![Img](/media/img-20230215145337.png)

In the above circuit, when the resistance changes with the light intensity, the voltage between the photoresistor and R2 resistor will also change. Therefore, by measuring this voltage, the intensity of light can be obtained.

## 18.4. Wiring Diagram 1：

**Schematic Diagram：**

![Img](/media/img-20230216173141.png)

**Wiring Diagram：**

![Img](/media/img-20230215150720.png)

## 18.5. Test Code 1：                                                                    
Code to read the photoresistor： 

```c
//**********************************************************************************
int photocellpin=A0;// Initialize the analog pin A0 of photoresistor
int val=0;// Initialize the variable val as 0

void setup()
{
Serial.begin(9600);// Set baud rate to 9600
pinMode(photocellpin, INPUT); //Set analog pin A0 to "input"
}

void loop()
{
val=analogRead(photocellpin);// Read the value of photoresistor, assign it to val
Serial.println(val);// Print the value of val
delay(200);// Delay 0.2s
}
//**********************************************************************************
```
## 18.6. Test Result 1：                                                                      
After uploading the code successfully, wire according to the wiring diagram and power on, tap ![Img](/media/img-20230215142037.png) and set the baud rate to 9600, then the light intensity around the photoresistor can be changed.

When the light intensity of the photoresistor gradually weakens, the analog value displayed by the serial monitor increases; otherwise, the analog value decreases gradually.

![Img](/media/img-20230215152825.png)

## 18.7. Wiring Diagram 2：

**Schematic Diagram：**

![Img](/media/img-20230216172943.png)

**Wiring Diagram：**

![Img](/media/img-20230215150938.png)

## 18.8. Test Code 2：                                                                    
Code for the photoresistor controls LED：

```c
//**********************************************************************************
int photocellpin=A0;// Initialize the analog pin A0 of photoresistor
int ledpin=11;// Initialize the digital pin 11
int val=0;// Initialize the variable val as 0

void setup()
{
Serial.begin(9600);// Set baud rate to 9600
pinMode(ledpin,OUTPUT);// Set digital pin 11 to "output"
pinMode(photocellpin,INPUT); // Set analog pin A0 to "input"
}

void loop()
{
val=analogRead(photocellpin);//Read the analog value of photoresistor, assign it to val
Serial.println(val);// Print the value of val
analogWrite(ledpin,val/4);// Set brightness(maximum 255)
delay(10);// Delay 0.01s
}
//**********************************************************************************
```
## 18.9. Test Result 2：                                                                      
After uploading the code successfully, wire according to the wiring diagram and power on, then the light intensity around the photoresistor can be changed.

When the light intensity of the photoresistor reduces, the LED becomes brighter, otherwise, it becomes darker.
