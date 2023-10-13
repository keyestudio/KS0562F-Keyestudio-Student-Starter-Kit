# Project 12：Toggle Switch Controls LED

![Img](/media/img-20230214150326.png)

## 12.1. Introduction：                                                                   
In this project, we will use a toggle switch to control two LEDs.            

## 12.2. Components Needed：                                                                   
- 328 PLUS Control Board×1
- Toggle Switch×1 
- LED×2
- 220Ω Resistor×2
- 10KΩ Resistor×2
- Breadboard×1
- Jumper Wire×10
- USB Cable×1

## 12.3. Component Knowledge：

![Img](/media/img-20230214150336.png)

Toggle Switch can be used to switch the circuit, which is divided into unipolar double position, unipolar three position, bipolar double position and bipolar three position.

It is generally used in low-voltage circuit, featuring flexible slider action, stable and reliable performance.

However, it is mainly applied in multiple devices such as instruments equipment, electric toys, fax machines, audio equipment, medical equipment and beauty equipment.

## 12.4. Wiring Diagram：

**Schematic Diagram：**

![Img](/media/img-20230216163647.png)

**Wiring Diagram：**

![Img](/media/img-20230216161610.png)

## 12.5. Test Code：                                                                    

```c
//**********************************************************************************
int redled = 11;  //Define red LED as digital pin 11
int greenled = 12; //Define green LED as digital pin 12
int redpin = 2; //Define control red LED as digital pin 2
int greenpin = 4; //Define control green LED as digital pin 4

void setup() 
{
  pinMode(redled,OUTPUT);   
  pinMode(greenled, OUTPUT);   
  pinMode(redpin, INPUT);   
  pinMode(greenpin,INPUT);   
}

void loop()
{
  int val = digitalRead(redpin);
  if (val == HIGH)  
  { 
    digitalWrite(redled, HIGH);  
  }
  else 
  {
    digitalWrite(redled,LOW); 
  }
  int val1 = digitalRead(greenpin);
  if (val1 == HIGH) 
  { 
    digitalWrite(greenled, HIGH); 
  }
  else 
  {
    digitalWrite(greenled,LOW);  
  }
}
//**********************************************************************************
```
## 12.6. Test Result：                                                                      
After uploading the code successfully, wire according to the wiring diagram and power on, toggle the switch to the left, green LED will be on and red LED will be off, toggle it to the right, then the green LED will be off and the red LED will be on.

