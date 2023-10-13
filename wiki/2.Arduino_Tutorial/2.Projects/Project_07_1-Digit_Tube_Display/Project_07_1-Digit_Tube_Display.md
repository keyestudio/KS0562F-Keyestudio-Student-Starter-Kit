# Project 07：1-Digit Tube Display

![Img](/media/img-20230214152403.png)

## 7.1. Introduction：                                                                 
 The 1-Digit Tube Display is often used to display digital information, which is widely used in induction cookers, automatic washing machines, water temperature display as well as electronic clocks. 
 
## 7.2. Components Needed：                                                                 
- 328 PLUS Control Board*1
- 1-Digit Tube Display*1
- 220Ω Resistor*8
- Breadboard*1
- Jumper Wires
- USB Cable*1

## 7.3. Component Knowledge：                                                                 
**1-Digit Tube Display：** It is a semiconductor light emitting device, and its basic unit is a light-emitting diode (LED). The digital tube display can be divided into 7-segment display and 8-segment display according to the number of segments. 

The 8-segment display has one more LED unit than the 7-segment display (used for decimal point display). Each segment of the 7-segment display is a separate LED. According to the connection mode of the LED unit, the digital tube can be divided into a common anode digital tube and a common cathode digital tube.

In the common cathode 7-segment display, all the cathodes (or negative pole) of the segmented LEDs are connected together, so you should connect the common cathode to GND. If you are about to light up a segmented LED, you can set its associated pin to“HIGH”.

In the common anode 7-segment display, the LED anodes (positive pole) of all segments are connected together, so you should connect the common anode to“+5V”. If you are about to light up a segmented LED, you can set its associated pin to“LOW”.

![Img](/media/img-20230214152434.png)

Each part of the digital tube is composed of a LED. Thus when you use it, you also need to use a current limiting resistor. Otherwise, the LED will be damaged. In this experiment, we will use an ordinary common cathode one-digit digital tube. As we mentioned above, you should connect the common cathode to GND. If you are about to light up a segmented LED, you can set its associated pin to“HIGH”.


## 7.4. Wiring Diagram：                                                                                                                                   

**Schematic Diagram：**

![Img](/media/img-20230216150857.png)

**Wiring Diagram：**

![Img](/media/img-20230314105129.png)

## 7.5. Test Code：                                                                  
The digital display is divided into 7 segments, and the decimal point display is divided into 1 segment. When certain numbers are displayed, the corresponding segment will be lit. For example, when the number 1 is displayed, segments b and c will be turned on.

We have compiled a subroutine for each number and set the main program to display a number（ 0 to 9）every 2 s. The display time of each number is affected by the delay time. The longer the delay time, the longer the display time.

```c
//**********************************************************************************
// Set IO pin of each part
int a=7;// Set part a to digital pin 7
int b=6;// Set part b to digital pin 6
int c=5;// Set part c to digital pin 5
int d=10;// Set part d to digital pin 10
int e=11;// Set part e to digital pin 11
int f=8;// Set part f to digital pin 8
int g=9;// Set part g to digital pin 9
int dp=4;// Set part dp to digital pin 4

void digital_0(void) // Display 0
{
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,LOW);
  digitalWrite(dp,LOW);
}
void digital_1(void) // Display 1
{
  unsigned char j;
  digitalWrite(c,HIGH);// Set power level of pin 5 to “high”, light part c up
  digitalWrite(b,HIGH);// Light part b up
  for(j=7;j<=11;j++)// Turn off remaining parts
  digitalWrite(j,LOW);
  digitalWrite(dp,LOW);// Turn part dp off
}
void digital_2(void) // Display 2
{
  unsigned char j;
  digitalWrite(b,HIGH);
  digitalWrite(a,HIGH);
  for(j=9;j<=11;j++)
  digitalWrite(j,HIGH);
  digitalWrite(dp,LOW);
  digitalWrite(c,LOW);
  digitalWrite(f,LOW);
}
void digital_3(void) // Display 3
{
  digitalWrite(g,HIGH);
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(dp,LOW);
  digitalWrite(f,LOW);
  digitalWrite(e,LOW);
}
void digital_4(void) // Display 4
{
  digitalWrite(c,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
  digitalWrite(dp,LOW);
  digitalWrite(a,LOW);
  digitalWrite(e,LOW);
  digitalWrite(d,LOW);
}
void digital_5(void) // Display 5
{
  unsigned char j;
  digitalWrite(a,HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
  digitalWrite(dp,LOW);
}
void digital_6(void) // Display 6
{
  unsigned char j;
  for(j=7;j<=11;j++)
  digitalWrite(j,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(dp,LOW);
  digitalWrite(b,LOW);
}
void digital_7(void) // Display 7
{
  unsigned char j;
  for(j=5;j<=7;j++)
  digitalWrite(j,HIGH);
  digitalWrite(dp,LOW);
  for(j=8;j<=11;j++)
  digitalWrite(j,LOW);
}
void digital_8(void) // Display 8
{
  unsigned char j;
  for(j=5;j<=11;j++)
  digitalWrite(j,HIGH);
  digitalWrite(dp,LOW);
}
void digital_9(void) // Display 9
{
  unsigned char j;
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
  digitalWrite(dp,LOW);
}
void setup()
{
int i;// Set variable
for(i=4;i<=11;i++)
pinMode(i,OUTPUT);// Set pin 4-11 to “output”
}
void loop()
{
  while(1)
  {
    digital_0();// Display 0
    delay(1000);// Delay 1s
    digital_1();// Display 1
    delay(1000);// Delay 1s
    digital_2();// Display 2
    delay(1000); // Delay 1s
    digital_3();// Display 3
    delay(1000); // Delay 1s
    digital_4();// Display 4
    delay(1000); // Delay 1s
    digital_5();// Display 5
    delay(1000); // Delay 1s
    digital_6();// Display 6
    delay(1000); // Delay 1s
    digital_7();// Display 7
    delay(1000); // Delay 1s
    digital_8();// Display 8
    delay(1000); // Delay 1s
    digital_9();// Display 9
    delay(1000); // Delay 1s
  }
}
//**********************************************************************************
```
## 7.6. Test Result：                                                                  
After uploading the code successfully, wrie according to the wiring diagram and power up, then the 1-Digit Tube Display will display numbers from 0 to 9.