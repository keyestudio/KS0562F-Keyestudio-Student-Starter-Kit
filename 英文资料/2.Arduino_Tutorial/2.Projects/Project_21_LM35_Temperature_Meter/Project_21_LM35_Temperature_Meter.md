# Project 21：LM35 Temperature Meter
![Img](/media/img-20230216112542.png)

## 12.1. Introduction：                                                                 
LM35 is a common and easy to use temperature sensor. It just requires an analog port to work. The hard part is compiling the code to convert the analog value it reads into Celsius. 

In this project, we will use a LM35 temperature sensor and three LEDs to make a LM35 temperature meter. When the LM35 temperature sensor touches objects with different temperatures, LEDs of different colors will light up.

## 12.2. Working Principle：                                                                  
The LM35 is a widely used temperature sensor that comes in many different package types. At room temperature, an accuracy of ±1/4°C is achieved without additional calibration processing.
![Img](/media/img-20230216112552.png)
   
The LM35 temperature sensor can generate different voltages according to different temperatures. When the temperature is 0°C, it outputs 0V; for every increase of 1°C, the output voltage increases by 10 mv. 

The output temperature is 0°C~100°C, the conversion formula is as follows:
![Img](/media/img-20230216112604.png)

## 12.3. Components Needed：                                                                  
- 328 PLUS Control Board*1 
- LM35*1
- LED *4 
- 220Ω Resistor*4
- Breadboard*1
- Jumper Wires 
- USB Cable*1

## 12.4. Wiring Diagram 1：

**Schematic Diagram：**
![Img](/media/img-20230217083526.png)

**Wiring Diagram：**
![Img](/media/img-20230216121051.png)

## 12.5. Test Code 1：                                                                    
Read the value of LM35:

```c
//**********************************************************************************
#define sensorPin A0

void setup()
{
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
}

void loop()
{
  long reading = analogRead(sensorPin);
  float voltage = reading * 5.0;
  voltage /= 1024.0;
  float temperatureC = (500 * reading) /1024 ;
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
  Serial.print(voltage); Serial.print(" volts  -  ");
  Serial.print(temperatureC); Serial.print(" degrees C  -  ");
  Serial.print(temperatureF); Serial.println(" degrees F");
  delay(200);
}
//**********************************************************************************
```

## 12.6. Test Result 1：                                                                      
After uploading the code successfully, wire according to the wiring diagram and power on. Tap ![Img](/media/img-20230215142037.png) and set the baud rate to 9600.

The serial monitor will print the current temperature value detected by the LM35 temperature sensor.

![Img](/media/img-20230216120444.png)

## 12.7. Wiring Diagram 2：

**Schematic Diagram：**
![Img](/media/img-20230217083357.png)

**Wiring Diagram：**
![Img](/media/img-20230216134043.png)

## 12.8. Test Code 2：                                                                    
<span style="color: rgb(255, 76, 65);">Note：The temperatureF value in the code can be adjusted appropriately according to the ambient temperature value.</span>
<br>
<br>

LM35 controls three LED analog thermometers:

```c
//**********************************************************************************
#define sensorPin  A0
#define greenLED 5
#define yellowLED 9
#define redLED 12

void setup()
{
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
}

void loop()
{
  long reading = analogRead(sensorPin);
  float voltage = reading * 5.0;
  voltage /= 1024.0;
  float temperatureC = (500 * reading) /1024 ; 
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
  Serial.print(voltage); Serial.print(" volts  -  ");
  Serial.print(temperatureC); Serial.print(" degrees C  -  ");
  Serial.print(temperatureF); Serial.println(" degrees F");

  if (temperatureF >= 75) {
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, HIGH);
  }
  else if (temperatureF >= 70 && temperatureF < 75) {
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, LOW);
  }
  else {
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);
  }

  delay(1000);
}
//**********************************************************************************
```
## 12.9. Test Result 2：                                                                      
After uploading the code successfully, wire according to the wiring diagram and power on. Tap ![Img](/media/img-20230215142037.png) and set the baud rate to 9600.

Then the monitor shows the current temperature value. Different LEDs light up when the LM35 temperature sensor senses different temperatures.

