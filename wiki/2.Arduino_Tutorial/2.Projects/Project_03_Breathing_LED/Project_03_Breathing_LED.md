# Project 03：Breathing LED
![Img](/media/img-20230213173746.png)

## 3.1.Introduction：
A “breathing LED” is a phenomenon where an LED's brightness smoothly changes from dark to bright and back to dark, continuing to do so and giving the illusion of an LED“breathing. However, how to control LED’s brightness? We need to take advantage of PWM of the 328 PLUS board.

## 3.2. Working Principle：                                                                  
![Img](/media/img-20230213173933.png)

PWM(Pulse Width Modulation) is a technology used to control LED brightness, DC motor and servo speed. 

Arduino digital pins generate 5V (high) or 0V (low). However, the PWM outputs a square wave signal. Thus if we want to dim the LED, we can't get a voltage between 0 and 5V from a digital pin, but we can change the ON and OFF time of the signal to change the brightness of the led. 

Output voltage = (on time/pulse time) * maximum voltage value.
![Img](/media/img-20230213173952.png)

PWM can be used to control brightness of lights, control speed of motors and make sound. The following are the three basic parameters of PMW.
![Img](/media/img-20230222152003.jpg)

1. Duty cycle：The percentage of time when the signal is at a high level for a certain period of time
2. Pulse period(The reciprocal of the pulse frequency in 1s)
3. There are six ports on Arduino: pin (3,5,6,9,10,11)

## 3.3. Components Needed：                                                                   
- 328 PLUS Control Board×1 
- Red LED×1
- 220Ω Resistor×1
- Breadboard×1
- Jumper Wire×2
- USB Cable×1
- Multimeter×1


## 3.4. Wiring Diagram 1：                                                                     
Here we use the digital pin 10. We need to connect the LED to a 220 Ω resistor to avoid damage to the LED due to high current.

**Schematic Diagram：**
![Img](/media/img-20230216140946.png)

**Wiring Diagram：**
![Img](/media/img-20230214112139.png)


## 3.5. Test Code：

```c
//**********************************************************************
int ledPin = 10; // Define digital port 10

void setup()
{
  pinMode(ledPin, OUTPUT);// Set ledPin to output
}

void loop()
{
  for (int a=0; a<=255;a++)// Set to gratually lighten the led
  {
    analogWrite(ledPin,a); // Light led up, adjust the brightness within the range of 0-255, led is the brightest at 255
    delay(10); // Delay 0.01S
  }
  for (int a=255; a>=0;a--) // Set to gratually darken the led
  {
    analogWrite(ledPin,a); // Light led up, adjust the brightness within the range of 0-255, led is the brightest at 255
    delay(10); // Delay 0.01s
  }
  delay(1000);// Delay 1s
}
//**********************************************************************

```
## 3.6. Test Result 1：                                                                   
After uploading the code successfully, wrie according to the wiring diagram, then power up with a USB cable. 

It shows the effect of the breathing led when IO port is connected to LED, and the LED gradually brightens first, and then gradually dims.

## 3.7. Wiring Diagram and Test Result 2：
When the breathing LED is working, we can use a multimeter to measure its voltage at both ends.
![Img](/media/img-20230322114556.png)
When the breathing LED is brightest, the voltage measured by the multimeter at both ends of the LED is 2.41V.
![Img](/media/img-20230322114608.png)
When it is darkest, the voltage at both ends of the LED is 0.45V.

<span style="color: rgb(255, 76, 65);">Note:</span> When the breathing LED becomes brighter, the voltage at both ends will increase, conversely, it will decrease.
