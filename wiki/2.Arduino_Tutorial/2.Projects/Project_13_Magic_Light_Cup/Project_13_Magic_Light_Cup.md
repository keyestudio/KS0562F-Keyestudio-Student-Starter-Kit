# Project 13：Magic Light Cup

![Img](/media/img-20230216090106.png)

## 13.1. Introduction：                                                                 
Tilt switch, also called ball switch, can be used to control the circuit by connecting the guide post to the rolling ball.

In this project, we will seek to leverage it to read the state of the tilt switch so as to control the LED.

## 13.2. Working Principle：                                                                 
When one end of the tilt switch is lower than the horizontal position, the switch is closed. The analog port voltage is about 5V (binary 1023)，and the LED lights up. When the other end is lower than the horizontal position, the switch is opened. The analog port voltage is about 0V (binary 0), and the LED lights off. 

In the program, we determine the switch state according to whether the voltage value of the analog port is higher than 2.5V (binary 512).

Internal Structure of the Tilt Switch:

![Img](/media/img-20230216085840.png)

## 13.3. Components Needed：                                                                  
- 328 PLUS Control Board×1 
- Tilt Switch*1
- LED *4 
- 220Ω Resistor*4
- 10KΩ Resistor*1
- Breadboard*1
- Jumper Wires
- USB Cable*1

## 13.4. Wiring Diagram： 

**Schematic Diagram：**

![Img](/media/img-20230216103758.png)

**Wiring Diagram：**

![Img](/media/img-20230216104612.png)

## 13.5. Test Code：                                                                  

```c
//**********************************************************************************
const byte SWITCH_PIN = 4; // Connect tilt switch to D4
int led1 = 8;  //Define led1 as digital port 8
int led2 = 9; 
int led3 = 10; 
int led4 = 11; 

byte switch_state = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(SWITCH_PIN, INPUT);
  for(int i=8;i<12;i++)
  {
    pinMode(i, OUTPUT);
  } 
  for(int i=8;i<12;i++)
  {
    digitalWrite(i,0);
  } 
}

void loop()
{
  switch_state = digitalRead(SWITCH_PIN); 
  Serial.println(switch_state);
  if (switch_state == 0) 
  {
    for(int i=8;i<12;i++)
    {
      digitalWrite(i,1);
      delay(500);
    } 
  }
  if (switch_state == 1) 
  {
    for(int i=11;i>7;i--)
    {
      digitalWrite(i,0);
      delay(500);
    }
  }
}
//**********************************************************************************
```
## 13.6. Test Result：                                                                   
After uploading the code successfully, wire according to the wiring diagram and power on, tilt the breadboard to an angle, the LEDs will light up one by one. When you turn the breadboard to the original angle, the LEDs will turn off one by one. Like the hourglass, the sand will leak out over time. 
