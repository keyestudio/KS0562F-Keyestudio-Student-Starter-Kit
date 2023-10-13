 # Project 11：Responder

## 11.1. Introduction：
Responder is a device used to accurately identify the answerer via the circuit design.

In knowledge contests, cultural and sports entertainment activities (quick answer contest activities), it empowers to accurately, fairly and intuitively judge the seat number of the answerer.

In this project, we look to leverage three PWM ports in a way that controls the RGB LED to display different colors to achieve the effect of a responder.

## 11.2. Components Needed：                                                                   
- 328 PLUS Control Board×1
- Button×4 
- RGB LED×1
- 220Ω Resistor×3
- 10KΩ Resistor×4
- Breadboard×1
- Jumper Wires
- USB Cable×1

## 11.4. Wiring Diagram：                                                                    

**Schematic Diagram：**
![Img](/media/img-20230217105020.png)

**Wiring Diagram：**
![Img](/media/img-20230217112739.png)

## 11.5. Test Code：

```c
//**********************************************************************************
int redled=11;     
int greenled=10; 
int blueled=9;  
int redpin=5;    
int greenpin=4; 
int bluepin=3;   
int restpin=2;   
int red;
int green;
int blue;

void setup()
{
pinMode(redled,OUTPUT);
pinMode(greenled,OUTPUT);
pinMode(blueled,OUTPUT);
pinMode(redpin,INPUT);
pinMode(greenpin,INPUT);
pinMode(bluepin,INPUT);
}

void loop() 
{
red=digitalRead(redpin);
green=digitalRead(greenpin);
blue=digitalRead(bluepin);
if(red==LOW)RED_YES();    
if(green==LOW)GREEN_YES();
if(blue==LOW)BLUE_YES();
}

void RED_YES() 
{
  while(digitalRead(restpin)==1)
  {
    color(255, 0, 0); 
}
  clear_led();
}

void GREEN_YES()
{
  while(digitalRead(restpin)==1)
  {
    color(0, 255, 0); 
  }
  clear_led();
}

void BLUE_YES()
{
  while(digitalRead(restpin)==1)
  {
    color(0, 0, 255); 

  }
  clear_led();
}

void clear_led()
{
  color(0, 0, 0); 
}

void color (unsigned char red, unsigned char green, unsigned char blue)  //Color-controled Function
{    
  analogWrite(redled, red);   
  analogWrite(greenled,green); 
  analogWrite(blueled, blue); 
} 
//**********************************************************************************
```
## 11.6. Test Result：                                                                      
After uploading the code successfully, wire according to the wiring diagram and power on, then we enable to judge who succeeded in answering the question according to the color displayed by the RGB Led. Press the reset button（<span style="color: rgb(255, 76, 65);">**it is connected to D2**</span>), then the RGB Led lights off.
