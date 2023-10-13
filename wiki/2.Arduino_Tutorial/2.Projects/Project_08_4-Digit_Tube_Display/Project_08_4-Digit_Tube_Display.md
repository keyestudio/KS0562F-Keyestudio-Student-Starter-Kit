 # Project 08：4-Digit Tube Display
![Img](/media/img-20230214162047.png)

## 8.1. Introduction：                                                                 
The 4-digit tube display is a very practical display device that can be used for devices such as electronic clocks, score counters and the number of people in the park. 

Bearing low price and easy to use, more and more projects will use the 4 digit tube display. In this project, we will use a control board to control it to display digits.

## 8.2. Components Needed：                                                                 
- 328 PLUS Control Board*1
- 4-Digit Tube Display*1
- 220Ω Resistor*8
- Breadboard*1
- Jumper Wires
- USB Cable*1

## 8.3. Component Knowledge：                                                                 
**4-Digit Tube Display：** It is a device with a common cathode and anode, its display principle is similar to the 1-Digit tube display. 

Both of them have eight GPIO ports to control the digital tube display, that is 8 leds. However, here is 4-digit, so it needs four GPIO ports to control the selection end. Our 4 - digit tube display is common cathode. 

The following figure shows the pinout of the 4-digit tube display. G1, G2, G3 and G4 are the control pins. 

![Img](/media/img-20230214162256.png)

Schematic Diagram：

![Img](/media/img-20230214162305.png)

![Img](/media/img-20230214162312.png)

## 8.4. Wiring Diagram：                                                                                                                                      

**Schematic Diagram：**

![Img](/media/img-20230216150159.png)

**Wiring Diagram：**

![Img](/media/img-20230215092535.png)

## 8.5. Test Code：                                                                  

```c
//**********************************************************************
int d_a = 1;   //Define digital tube part a as pin 1
int d_b = 2;
int d_c = 3;
int d_d = 4;
int d_e = 5;
int d_f = 6;
int d_g = 7;
int d_dp = 8;

int G1 = 12;   //Define digital tube Group One G1 to pin 21
int G2 = 11;
int G3 = 10;
int G4 = 9;

//Digital tube 0-F code value
unsigned char num[17][8] =
{
//a  b  c  d  e  f  g  dp 
  {1, 1, 1, 1, 1, 1, 0, 0},     //0
  {0, 1, 1, 0, 0, 0, 0, 0},     //1
  {1, 1, 0, 1, 1, 0, 1, 0},     //2
  {1, 1, 1, 1, 0, 0, 1, 0},     //3
  {0, 1, 1, 0, 0, 1, 1, 0},     //4
  {1, 0, 1, 1, 0, 1, 1, 0},     //5
  {1, 0, 1, 1, 1, 1, 1, 0},     //6
  {1, 1, 1, 0, 0, 0, 0, 0},     //7
  {1, 1, 1, 1, 1, 1, 1, 0},     //8
  {1, 1, 1, 1, 0, 1, 1, 0},     //9
  {1, 1, 1, 0, 1, 1, 1, 1},     //A
  {1, 1, 1, 1, 1, 1, 1, 1},     //B
  {1, 0, 0, 1, 1, 1, 0, 1},     //C
  {1, 1, 1, 1, 1, 1, 0, 1},     //D
  {1, 0, 0, 1, 1, 1, 1, 1},     //E
  {1, 0, 0, 0, 1, 1, 1, 1},     //F
  {0, 0, 0, 0, 0, 0, 0, 1},     //.
};

void setup()
{
  pinMode(d_a,OUTPUT);    //Set pin d_a to output pin
  pinMode(d_b,OUTPUT);
  pinMode(d_c,OUTPUT);
  pinMode(d_d,OUTPUT);
  pinMode(d_e,OUTPUT);
  pinMode(d_f,OUTPUT);
  pinMode(d_g,OUTPUT);
  pinMode(d_dp,OUTPUT);

  pinMode(G1,OUTPUT);
  pinMode(G2,OUTPUT);
  pinMode(G3,OUTPUT);
  pinMode(G4,OUTPUT);
}

void loop()
{

  //Count from 0, add 1 gratually to 9999, repeat this.
  for(int l = 0;l < 10;l++ )
  {
    for(int k = 0; k < 10;k++)
    {
      for(int j = 0; j < 10; j++)
      {
        for(int i = 0;i < 10;i++)
        {
          //Blinking 125 times per second equals 1s.
          //1000/8=125
          for(int q = 0;q<125;q++)
          {
            Display(1,l);//The first digitL tube displays the value of l.
            delay(2);
            Display(2,k);
            delay(2);
            Display(3,j);
            delay(2);
            Display(4,i);
            delay(2);
          }

        }
      }
    }
  }
  

}

//Display: the range of g is 1 ~ 4, the range of num is 0 ~ 9
void Display(unsigned char g,unsigned char n) 
{
  digitalWrite(d_a,LOW);      //
  digitalWrite(d_b,LOW);
  digitalWrite(d_c,LOW);
  digitalWrite(d_d,LOW);
  digitalWrite(d_e,LOW);
  digitalWrite(d_f,LOW);
  digitalWrite(d_g,LOW);
  digitalWrite(d_dp,LOW);

  switch(g)           //Make selection
  {
    case 1:
      digitalWrite(G1,LOW);   //Select Group One
      digitalWrite(G2,HIGH);
      digitalWrite(G3,HIGH);
      digitalWrite(G4,HIGH);
      break;
    case 2:
      digitalWrite(G1,HIGH);
      digitalWrite(G2,LOW);   //Select Group Two
      digitalWrite(G3,HIGH);
      digitalWrite(G4,HIGH);
      break;
    case 3:
      digitalWrite(G1,HIGH);
      digitalWrite(G2,HIGH);
      digitalWrite(G3,LOW);   //Select Group Three
      digitalWrite(G4,HIGH);
      break;
    case 4:
      digitalWrite(G1,HIGH);
      digitalWrite(G2,HIGH);
      digitalWrite(G3,HIGH);
      digitalWrite(G4,LOW);   //Select Group Four
      break;
    default:break;
  }

  digitalWrite(d_a,num[n][0]);      //a query code value table
  digitalWrite(d_b,num[n][1]);
  digitalWrite(d_c,num[n][2]);
  digitalWrite(d_d,num[n][3]);
  digitalWrite(d_e,num[n][4]);
  digitalWrite(d_f,num[n][5]);
  digitalWrite(d_g,num[n][6]);
  digitalWrite(d_dp,num[n][7]);
}
//**********************************************************************
```

## 8.6. Test Result：                                                                      
After uploading the code successfully, wrie according to the wiring diagram and power up, then the 4-Digit Tube Display will display 0000-9999 and repeat these actions in an infinite loop.
