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
  double tempK = 1 / (1 / (273.15 + 25) + log(Rt / 10) / 3950.0); //Calculate temperature (degree kelvin)
  double tempC = tempK - 273.15;  //Calculate temperature (degree centigrade)
  Serial.print("Temperature value=");
  Serial.println(tempC);
  Serial.println();
    
  //Output per second, alter the modification frequency here
  delay(1000); 
}
//**********************************************************************************
