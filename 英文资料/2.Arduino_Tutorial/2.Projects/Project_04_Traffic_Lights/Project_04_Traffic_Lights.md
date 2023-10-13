# Project 04：Traffic Lights
![Img](/media/img-20230214083336.png)

## 4.1. Introduction：                                                                   
In this project, we will look to use three LEDs in different colors to simulate traffic lights.
                                    
## 4.2. Components Needed：                                                                   
- 328 PLUS Control Board×1
- USB Cable×1
- Red LED×1
- Yellow LED×1
- Green LED×1
- 220Ω Resistor×3
- Breadboard×1
- Jumper Wire×7

## 4.3. Wiring Diagram：                                                                     

**Schematic Diagram：**
![Img](/media/img-20230216141422.png)

**Wiring Diagram：**
![Img](/media/img-20230214090416.png)

## 4.4. Test Code：                                                                   
The blinking time of each LED should coincide with the blinking time of the real traffic light system.

```c
//**********************************************************************
int redled =10; // Initialize digital pin 10.
int yellowled =7; // Initialize digital pin 7.
int greenled =4; // Initialize digital pin 4.
void setup()
{
  pinMode(redled, OUTPUT); // Set red LED pin to “output”.
  pinMode(yellowled, OUTPUT); // Set yellow LED pin to “output”.
  pinMode(greenled, OUTPUT); // Set green LED pin to “output”.
}
void loop()
{
  digitalWrite(greenled, HIGH);// Light green LED up
  delay(5000);// Delay 5s
  digitalWrite(greenled, LOW); // Turn green LED off
  for(int i=0;i<3;i++)// Blink for 3 times
  {
    delay(500);// Delay 0.5s
    digitalWrite(yellowled, HIGH);// Light yellow LED up
    delay(500);// Delay 0.5s
    digitalWrite(yellowled, LOW);// Turn yellow LED off
  } 
  delay(500);// Delay 0.5s
  digitalWrite(redled, HIGH);// Light red LED up
  delay(5000);// Delay 0.5s
  digitalWrite(redled, LOW);// Turn red LED off
}
//**********************************************************************

```
## 4.5. Test Result：                                                                   
After uploading the code successfully, wrie according to the wiring diagram, then you can see the traffic lights you designed. Note that this circuit design is very similar to the chase effect of leds. 

The green led will be on for 5s then off, the yellow led will flash for 3s, then the red led will light up for 5s.

