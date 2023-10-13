# Project 05：Water Flowing Light

## 5.1. Introduction：
In our daily life, we can see many billboards composed of different colors of LED. They constantly change the light (like water) to attract customers' attention. 

In this project, we will use a control board to control 5 leds to achieve the effect of flowing water. 

## 5.2. Components Needed：                                                                   
- 328 PLUS Control Board×1 
- Red LED×5
- 220Ω Resistor×5
- Breadboard×1
- Jumper Wires
- USB Cable×1

## 5.3. Wiring Diagram：                                                                     
**Schematic Diagram：**
![Img](/media/img-20230217132639.png)

**Wiring Diagram：**
![Img](/media/img-20230217133543.png)

## 5.5. Test Code：
This project is designed to make a flowing water lamp. Actions: First turn  LED #1 on, then turn it off. Then turn LED #2 on, and then turn it off... and repeat the same to all LEDs until the last LED turns off. This process is repeated to achieve the“movements”of flowing water.

```c
//**********************************************************************
byte ledPins[] = {2, 3, 4, 5, 6};
int ledCounts;

void setup() {
  ledCounts = sizeof(ledPins);
  for (int i = 0; i < ledCounts; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < ledCounts; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(100);
    digitalWrite(ledPins[i], LOW);
  }
  for (int i = ledCounts - 1; i > -1; i--) {
    digitalWrite(ledPins[i], HIGH);
    delay(100);
    digitalWrite(ledPins[i], LOW);
  }
}
//**********************************************************************
```

## 5.6. Test Result：                                                                   
After uploading the code successfully, wrie according to the wiring diagram and power up, then you can see that five LEDs will light up from right to left and then back from left to right.

