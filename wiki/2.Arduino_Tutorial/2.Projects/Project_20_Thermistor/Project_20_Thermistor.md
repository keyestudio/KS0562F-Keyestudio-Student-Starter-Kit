# Project 20：Thermistor
![Img](/media/img-20230316092026.png)

## 20.1. Introduction：                                                                 
Thermistor is a type of resistor whose resistance depends on the temperature and is widely used in gardening and home alarm systems.

## 20.2. Components Needed：                                                                   
- 328 PLUS Control Board×1
- Thermistor*1
- 10KΩ Resistor*1
- Breadboard*1
- Jumper Wires
- USB Cable*1
- Multimeter×1

## 20.3. Component Knowledge：                                                                    
**Thermistor：** Thermistor is a temperature sensitive resistor. When the thermistor senses a change in temperature, its resistance changes. We can use this characteristic of the thermistor to detect temperature intensity. 

Thermistors and its electrical symbols are shown below:
![Img](/media/img-20230316092045.png)
![Img](/media/img-20230316092142.png)

The relationship between the resistance value of the thermistor and temperature is:
![Img](/media/img-20230215173446.png)

In the formula：
**Rt** is the resistance of the thermistor at T2 temperature;
**R** is the nominal resistance of the thermistor at T1 temperature;
**EXP[n]** is the nth power of e;
**B** is the temperature index;
**T1**, **T2** are Kelvin temperature (absolute temperature), Kelvin temperature = 273.15 + Celsius temperature. For the parameters of the thermistor, we use: B=3950, R=10KΩ, T1=25℃. The circuit connection method of the thermistor is similar to that of a photoresistor, as follows:
![Img](/media/img-20230215174025.png)

We can use the value measured by the ADC converter to get the resistance value of the thermistor, and then use the formula to get the temperature value. Therefore, the temperature formula can be derived as:
![Img](/media/img-20230215174252.png)

## 20.4. Wiring Diagram 1：

**Schematic Diagram：**
![Img](/media/img-20230216180119.png)

**Wiring Diagram：**
![Img](/media/img-20230215175434.png)

## 20.5. Test Code：                                                                    
Code to read the thermistor： 

```c
//**********************************************************************************
#include<math.h>

const float voltagePower=5.0;
const float Rs=10;//Sample resisitor is of 10k Ohm
const int B=3950;
const double T1=273.15+25;//Normal temperature
const double R1=10;//Resistance under normal temperature, with unit of "kΩ"

void setup() {
  Serial.begin(9600);
}
void loop() { 
  //Aquire the voltage of analog pin A0
  double digitalValue=analogRead(A0);
  double voltageValue=(digitalValue/1023)*voltagePower;
  Serial.print("Voltage value=");
  Serial.println(voltageValue);
  
  //Aquire the resistance of thermistor via voltage division ratio
  double Rt=Rs*voltageValue/(voltagePower-voltageValue);
  Serial.print("Thermistor value=");
  Serial.println(Rt);

  //Auire temperature value through conversion
  double tempK = 1 / (1 / (273.15 + 25) + log(Rt / 10) / 3950.0); // Calculate temperature (degree kelvin)
  double tempC = tempK - 273.15;  //Calculate temperature (degree centigrade)
  Serial.print("Temperature value=");
  Serial.println(tempC);
  Serial.println();
    
  //Output per second, alter the modification frequency here
  delay(1000); 
}
//**********************************************************************************
```
## 20.6. Test Result 1：                                                                      
After uploading the code successfully, wire according to the wiring diagram and power on, tap ![Img](/media/img-20230215142037.png)and set the baud rate to 9600.

The serial monitor will continuously display the current voltage, resistance and temperature of the thermistor. Try pinching the thermistor between your index finger and thumb (without touching the wires) for a short while and you will see the temperature value increase.
![Img](/media/img-20230216084521.png)

## 20.7. Wiring Diagram and Test Result 2：
![Img](/media/img-20230321170921.png)
At room temperature, the resistance value of the thermistor measured by a multimeter is 8.95KΩ.
![Img](/media/img-20230321170946.png)
If you touch the thermistor with your hand, the resistance value of the thermistor measured by a multimeter is 6.68KΩ.

<span style="color: rgb(255, 76, 65);">Note:</span> The temperature increases, the thermistor resistance value will decrease.




