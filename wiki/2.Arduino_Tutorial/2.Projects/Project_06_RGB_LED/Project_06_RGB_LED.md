# Project 06：RGB LED

![Img](/media/img-20230214103810.png)

## 6.1. Introduction：                                                                   
RGB is composed of three colors (red, green and blue), which can emit different colors by mixing these three colors.

In this project, we will use Arduino to to mix the three colors to produce a full-color LED.

## 6.2. Components Needed：                                                                   
- 328 PLUS Control Board×1 
- USB Cable*1  
- RGB LED *1 
- 220Ω Resistor*3 
- Breadboard*1
- Jumper Wire*5

## 6.3. Component Knowledge：                                                                   
Most monitors adopt the RGB color standard, and all colors on a computer screen are a mixture of red, green and blue in varying proportions. RGB includes common cathode RGB and common anode RGB.

![Img](/media/img-20230214103904.png)

We use the PWM to change the LED brightness.
 
## 6.4. Wiring Diagram：                                                                                                                                        

**Schematic Diagram：**

![Img](/media/img-20230216142154.png)

**Wiring Diagram：**

![Img](/media/img-20230214111232.png)

## 6.5. Test Code：                                                                   

```c
//**********************************************************************
int redpin = 11; //Select red LED pin 11.
int greenpin = 10; // Sekect green LED pin 10.
int bluepin = 9; // Select blue LED pin 9.

int val = 0;

void setup() {
  pinMode(redpin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  pinMode(bluepin, OUTPUT);

  digitalWrite(redpin,LOW);
  digitalWrite(greenpin,LOW);
  digitalWrite(bluepin,LOW);
}

void loop() {
  for(val=255; val>0; val--)
  {
    analogWrite(redpin,val);
    analogWrite(greenpin,(255 - val));
    analogWrite(bluepin,(128 - val));
    delay(0.001 * 1000);
  }
  for(val=0; val<255; val++)
  {
    analogWrite(redpin,val);
    analogWrite(greenpin,(255 - val));
    analogWrite(bluepin,(128 - val));
    delay(0.001 * 1000);
  }
}
//**********************************************************************
```

## 6.6. Test Result：                                                                   
After uploading the code successfully, wrie according to the wiring diagram and power up, then you will see a full-color LED.