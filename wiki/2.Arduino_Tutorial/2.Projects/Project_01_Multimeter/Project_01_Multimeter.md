# Project 01：Multimeter
<span style="color: rgb(255, 76, 65);">Note：For the details of the XL-830L multimeter, please refer to the manual.
</span>

![Img](/media/img-20230224115722.png)

## 1. Introduction：
In this project, we will show you how to use the XL-830L series digital multimeter(DMM). To be specific, it is a tool used to measure DC and AC voltage, current, resistance and diode. More importantly, it is useful for some basic checking and troubleshooting such as circuits and swtiches.

Next, we are going to learn how to measure DC voltage, resistance, DC current, and continuity.

## 2. Components of the Multimeter：
![Img](/media/img-20230224115807.png)

①LCD    ②Hold Button    ③Range Switch    ④“COM” Jack 

⑤“10A” Jack    ⑥“V Ω mA” Jack      ⑦Backlit Button

**LCD：** It can display ![Img](/media/img-20230301091301.png)bits numbers(include negative numbers). Press the Backlit Button![Img](/media/img-20230224120012.png), then the LCD can be lighted up for better reading.

**Range Switch：** It can be used to set the multimeter to read different objects, such as current (mA), voltage (V) and resistance (Ω).

**Test Leads and Jacks：** The plugs of the two test leads are inserted into the jacks on the front of the multimeter.

**COM Jack：** It is usually connected to the “-” of a circuit or GND.

**COM Test Lead：** It is usually black, but there is no other difference between the black and red test leads except the color.

**10A Jack：** It is a special interface used to measure a large amount of current(generally greater than 200mA).

**VΩmA Jack：** It is usually connected to the red test lead, which can measure current (less than 200mA), voltage (V) and resistance (Ω). One end of the test lead has a plug that can be inserted into the jack of the multimeter.

![Img](/media/img-20230224120129.png)

## 3. Voltage Measurement：
Turn the range switch to the corresponding range of the DC voltage block. When measuring voltage, it is necessary to connect the multimeter in parallel to the circuit under test, and pay attention to the positive and negative poles.

If you do not know the polarity and approximate value of the measured voltage, turn the range switch to the highest range of the DC voltage block for measurement, then adjust the polarity and the range. Pay attention to where the test leads are inserted, the black test lead is inserted into the COM jack, and the red one is inserted into the VΩmA jack. As shown in the picture:
![Img](/media/img-20230224120225.png)

For instance, let's try to measure the voltage of a 9V battery:insert the black test lead into the COM jack, and the red one into the VΩmA jack, then set the voltage of the multimeter to DC 20V.

Connect the tip of the black test lead to the battery ground or "-", connect the tip of the red one to the power supply or "+", and squeeze the positive and negative terminals of the 9V battery. If it is a new battery, the LCD shows about 9V, and the reading value of a new battery may be slightly higher than 9V, which is 9.19 here.
![Img](/media/img-20230224120305.png)

If the detected voltage is a DC voltage, such as a battery or connected to an Arduino mainboard, the range switch needs to be rotated to the V- position. AC voltage (like a wall outlet) is dangerous, so it is rarely necessary to use the AC voltage setting (V~). If AC power is accidentally applied, we recommend using a non-contact tester rather than a digital multimeter.
![Img](/media/img-20230224120312.png)
Measure the DC voltage at V- 
![Img](/media/img-20230224120333.png)
Measure the AC voltage at V~

If the red and black test leads are reversed, the reading on the multimeter will show a negative number. 
When measuring voltage with a multimeter, if the tip of the red test lead touches the "+" pole of the battery and the tip of the black one touches the "-" pole, the multimeter will display a voltage of about 9V, otherwise, it displays a voltage of about -9V.

![Img](/media/img-20230224120346.png)
<span style="color: rgb(255, 76, 65);">Note：When measuring voltage with a multimeter, do not connect the two test leads reversely.</span>

Now, we will construct a simple circuit to demonstrate how to measure voltage in our life. The circuit components contain a 220Ω resistor and a red LED, which are powered by a 328PLUS mainboard.

First, confirm that the circuit can be powered on normally. If the voltage of the circuit that should be 5V is detected lower than 4.5V or higher than 5.5V, it indicates that the connection is wrong. Please check the power supply and circuit immediately. The following figure shows the voltage of the 328PLUS board:
![Img](/media/img-20230224120426.png)
<span style="color: rgb(255, 76, 65);">Note：The tips of the two test leads need to touch the jumper wires, the resistor or the metal part of the LED (the same below), otherwise, the multimeter will not have a reading.

Set the range switch to 20V DC voltage. The multimeter usually can not change the range automatically, so it needs to be manually set to the detectable range.

For example, 2V measures voltages up to 2V and 20V measures voltages up to 20V. Therefore, to measure a 9V battery, you need to set the range switch to 20V, and 5V is also suitable for 20V. If it is not set correctly, you may see the multimeter screen change and the read value may be "1".
![Img](/media/img-20230224120516.png)

By measuring the voltage flowing through the circuit, we can know the voltage required by each component. First measure the overall voltage of the circuit, then measure the resistor and the position where the LED is grounded, we can see the complete voltage of the circuit, which is expected to be around 5V.
![Img](/media/img-20230224120533.png)
![Img](/media/img-20230224120555.png)

At this time, the voltage across the LED is 1.93V, thus, we can analyze the whole circuit by measuring different parts of the circuit.
![Img](/media/img-20230224120602.png)

### Load
If the selected voltage setting is lower than the measured voltage, the multimeter will show "1", indicating overload or out of range. Please turn the range switch to the next highest value for reading.
![Img](/media/img-20230224120651.png)
The 5V read in this circuit is higher than the 2V on the multimeter.

<span style="color: rgb(255, 76, 65);">Select the appropriate DC voltage according to the measured voltage, so that the precision of the measured voltage value is higher and more accurate. For example: to measure the actual voltage of a 1.5V battery, you need to adjust the switch to 2V. The higher the selected voltage, the lower the accuracy.</span>

### Range Switch 
![Img](/media/img-20230224120812.png)

Why is the switch turned to 20V instead of 10V when the voltage of the battery under test is 9V? If you measure a voltage less than 20V and greater than 2V, turn the switch to 20V, and the reading range includes 2.00 to 19.99. Many multimeters can only show "1" for the first digit, so the range is limited to 19.99 instead of 99.99, so 20V is the max range instead of 99V.

<span style="color: rgb(255, 76, 65);">Note：The access must be DC voltage circuit (V-). Many multimeters can be used to detect AC voltage, but its circuit is dangerous. Please be cautious for detecting AC power. 
If you want to check whether the socket is "open", then use the AC tester. 
In fact, only when the socket's performance is abnormal (whether it is a local standard AC voltage value) or the control needs of the heater (such as an electric heating board), the AC electricity needs to be measured. </span>

## 4. Resistance Measurement
We can use a calculator to obtain the resistance value of the resistors according to the color bands or use a multimeter to measure it. The resistance without positive and negative poles.
![Img](/media/img-20230224120917.png)

Select a resistor at random, set the multimeter to the 20kΩ position, and lightly press the tip of the test lead on the two pins of the resistor.
![Img](/media/img-20230224120925.png)

The multimeter will read one of three values：**0.00**，**1**，or **actual resistance**.

The value of the multimeter in the figure above is 0.99, which means that the resistance of the resistor is 990Ω or close to 1kΩ (currently in 20kΩ mode).

If the multimeter reads **1**, it means load. At this time, it is only need to increase the range of the test resistance value to 200kΩ or 2MΩ.

If the the multimeter reads **0.00** or close to 0, you need to lower the range of the test resistance to 2kΩ or 200Ω.

Many resistors boast a 5% tolerance, meaning that the color band represents a value of 10kΩ, but due to variations in manufacturing, a 10kΩ resistor can be as low as 9.5kΩ or as high as 10.5kΩ.

Now lower the measuring range of the multimeter to 2KΩ:
![Img](/media/img-20230224131145.png)

It will not change much since the resistor value (1KΩ) is lower than 2KΩ and the LCD can still show the value. However, the read value will have one more decimal place, and the resolution is higher. If you turn down one more range, the LCD shows the number "1".
![Img](/media/img-20230224131151.png)

Since 1kΩ is higher than 200Ω, it is beyond the reading range and we need to increase the measurement range.

## 5. Current Measurement
The multimeter must be correctly connected in series in the circuit according to the polarity of the circuit, and the switch should be turned on the corresponding range of "mA" or "A".

If you do not know the polarity and value of the measured current, turn the switch to the highest range of the current block for measurement, and then adjust the polarity and the appropriate range.

The measurement of current is the same as that of voltage and resistance, and the measurement range needs to be set. Set the switch to 20mA, as most breadboards draw less than 20mA.

Make sure the plug of the red test lead is connected to the VΩmA jack, the jack corresponding to 20mA is the same as the voltage and resistance reading jack (the jack is marked VΩmA), which means that the red test lead can share the same jack to measure current, voltage or resistance. But if the circuit current is close to or higher than 20mA, you can adjust the range switch to 200mA to ensure safety. If it is not enough to choose 200mA, adjust the switch to 10A. A current load will cause the fuse inside the multimeter to blow instead of displaying a load reading.
![Img](/media/img-20230224131223.png)
The circuit is only 4.86mA when measured. The average reading is close to 4.85mA.

If we change the position of the red and black test leads, the current reading will show a negative number.

![Img](/media/img-20230224131313.png)
The current still flows through the circuit, it just changes direction, making the current reading negative.
<span style="color: rgb(255, 76, 65);">Generally, when the multimeter measures the current, it is not recommended to connect the two test leads reversely.</span>

<span style="color: rgb(255, 76, 65);">Note：When the multimeter is used up, reset the switch to OFF.</span>

![Img](/media/img-20230224131536.png)

## 6. Diode Measurement
It is a kind of semiconductor called "light-emitting diode", which is an electronic device made of semiconductor materials (silicon, selenium, germanium, etc.). It has an anode and a cathode. 

The short lead is the negative pole, the long lead is the positive pole.

Set the switch to ![Img](/media/img-20230224131639.png)，then connect the tip of the red test lead to the long lead of the LED, and the black one to the short lead. Next, let's observe whether the LED is on. If the LED is on, it means that the diode inside the LED is good; otherwise it is bad.
![Img](/media/img-20230224131704.png)

## 7. Continuity Measurement
Multimeters can be used to test the continuity of the circuit. It also helps you to check if there is a short between two points of the circuit if there is a wire fault.

To use this function, please select the speaker icon mode, then turn the range switch to it.
![Img](/media/img-20230224131734.png)

**How Continuity Works?**

If the resistance between the two points is low and the circuit is conducting, then you will hear an alarm. If you can't hear anything, it means the two points you're testing are disconnected or not connected.

<span style="color: rgb(255, 76, 65);">Note：Before checking continuity, turn off the multimeter and the power.</span>
<br>
<br>
Touch the tips of the two test leads together and you will hear an alarm sound when they connect.
![Img](/media/img-20230224131846.png)

To test for continuity in the leads, you just need to connect the tip of each test lead to the tip of the leads.
![Img](/media/img-20230224131854.png)

When the tip of the test leads are not in contact, the LCD shows "1".
![Img](/media/img-20230224131905.png)
