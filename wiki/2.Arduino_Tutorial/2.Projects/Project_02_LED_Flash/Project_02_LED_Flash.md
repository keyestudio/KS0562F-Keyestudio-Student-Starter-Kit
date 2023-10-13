# Project 02：LED Flash
![Img](/media/img-20230213165351.png)

## 2.1. Introduction：                                                                  
In this project, we will connect the LED to one of the digital pins not the LED13. Let's take a look at the components we need!

## 2.2. Components Needed：                                                                   
- 328 PLUS Control Board×1 
- Red LED×1
- 220Ω Resistor×1
- Breadboard×1
- Jumper Wire×2
- USB Cable×1
- Multimeter×1

## 2.3. Components Knowledge：                                                                    

**（1）LED**:
![Img](/media/img-20230213165550.png)

It is a kind of semiconductor called "light-emitting diode", which is an electronic device made of semiconductor materials (silicon, selenium, germanium, etc.). It has an anode and a cathode. 

The short lead (cathode) is connected to GND. The long lead (anode)is connected to 3.3V or 5V.
![Img](/media/img-20230213165602.png)

**（2）5-band Resistor**
A resistor is an electronic component in a circuit that restricts or regulates the flow current flow. On the left is the appearance of the resistor and on the right is the symbol for the resistance in the circuit. Its unit is(Ω). 1 mΩ= 1000 kΩ，1kΩ= 1000Ω.
![Img](/media/img-20230213165612.png)
  
We can use resistors to protect sensitive components, such as LEDs.

The strength of the resistance(The unit is Ω) is marked on the body of the resistor with a color band. Each color represents a number, and you can refer to it with a resistance card.

-Color 1 – 1st Digit.
-Color 2 – 2nd Digit.
-Color 3 – 3rd Digit.
-Color 4 – Multiplier.
-Color 5 – Tolerance.
![Img](/media/img-20230213165620.png)

In this kit, we provide three 5-band resistors with different resistance values. We take three 5-band resistors as an example：

**220Ω resistor*10**
![Img](/media/img-20230213165647.png)

**10KΩ resistor*10**
![Img](/media/img-20230213165705.png)

**1KΩ resistor*10**
![Img](/media/img-20230213165715.png)

In the same voltage, there will be less current and more resistance.The connection between current, voltage, and resistance can be expressed by the formula: I=U/R.

In the figure below, if the voltage is 3V, the current through R1 is: I = U / R = 3 V / 10 KΩ= 0.0003A= 0.3mA.
![Img](/media/img-20230213165731.png)
            
Do not directly connect resistors with very low resistance to the two poles of the power supply, as this will cause excessive current to damage the electronic components. Resistors do not have positive and negative poles.


**（3）Breadboard**
A breadboard is used to build and test circuits quickly before finalizing any circuit design. The breadboard has many holes for inserting circuit components such as integrated circuits and resistors. A typical breadboard is as follows.
![Img](/media/img-20230213165744.png)

The bread board has strips of metal , which run underneath the board and connect the holes on the top of the board. The metal strips are laid out as shown below. Note that the top and bottom rows of holes are connected horizontally while the remaining holes are connected vertically.
![Img](/media/img-20230213165753.png)

The first two rows (top) and the last two rows (bottom) of the breadboard are used for the positive (+) and negative (-) terminals of the power supply. The conductive layout of the breadboard is shown in the following diagram.
![Img](/media/img-20230213165803.png)

When we connect DIP (Dual In-line Packages) components such as integrated circuits, microcontrollers, chips and so on, we can see that a groove in the middle isolates the middle part, so the top and bottom of the groove is not connected. DIP components can be connected as shown in the figure below:
![Img](/media/img-20230213165816.png)
![Img](/media/img-20230213165822.png)

## 2.4. Wiring Diagram 1：                                 
 Here we use the digital pin 10. We need to connect the LED to a 220 Ω resistor to avoid damage to the LED due to high current.

**Schematic Diagram：**
![Img](/media/img-20230216140906.png)

**Wiring Diagram：**
![Img](/media/img-20230214112129.png)

## 2.5. Test Code：                                                                    

```c   
//**********************************************************************
int led = 10;  //Define digital port 10

void setup() {
  pinMode(led, OUTPUT);  //Set led to output
}

void loop() {
  digitalWrite(led, HIGH);  //Light led up
  delay(1000);              //Delay 1s
  digitalWrite(led, LOW);   //Trun led off
  delay(1000);              //Delay 1s
}
//**********************************************************************

```

## 2.6. Test Result 1：                                                                   
After uploading the code successfully, power up with a USB cable and the LED will start flashing.


## 2.7. Wiring Diagram and Test Result 2：
![Img](/media/img-20230322095910.png)
When the LED lights up, the voltage measured by the multimeter is 4.92V（about 5V）
![Img](/media/img-20230322101055.png)
When the LED is not bright, the voltage measured by the multimeter is 0V.