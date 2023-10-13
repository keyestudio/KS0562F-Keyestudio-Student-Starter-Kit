//**********************************************************************************
// Set IO pin of each part
int a=7;// Set part a to digital pin 7
int b=6;// Set part b to digital pin 6
int c=5;// Set part c to digital pin 5
int d=10;// Set part d to digital pin 10
int e=11;// Set part e to digital pin 11
int f=8;// Set part f to digital pin 8
int g=9;// Set part g to digital pin 9
int dp=4;// Set part dp to digital pin 4

void digital_0(void) // Display 0
{
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,LOW);
  digitalWrite(dp,LOW);
}
void digital_1(void) // Display 1
{
  unsigned char j;
  digitalWrite(c,HIGH);// Set power level of pin 5 to “high”, light part c up
  digitalWrite(b,HIGH);// Light part b up
  for(j=7;j<=11;j++)// Turn off remaining parts
  digitalWrite(j,LOW);
  digitalWrite(dp,LOW);// Turn part dp off
}
void digital_2(void) // Display 2
{
  unsigned char j;
  digitalWrite(b,HIGH);
  digitalWrite(a,HIGH);
  for(j=9;j<=11;j++)
  digitalWrite(j,HIGH);
  digitalWrite(dp,LOW);
  digitalWrite(c,LOW);
  digitalWrite(f,LOW);
}
void digital_3(void) // Display 3
{
  digitalWrite(g,HIGH);
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(dp,LOW);
  digitalWrite(f,LOW);
  digitalWrite(e,LOW);
}
void digital_4(void) // Display 4
{
  digitalWrite(c,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
  digitalWrite(dp,LOW);
  digitalWrite(a,LOW);
  digitalWrite(e,LOW);
  digitalWrite(d,LOW);
}
void digital_5(void) // Display 5
{
  unsigned char j;
  digitalWrite(a,HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
  digitalWrite(dp,LOW);
}
void digital_6(void) // Display 6
{
  unsigned char j;
  for(j=7;j<=11;j++)
  digitalWrite(j,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(dp,LOW);
  digitalWrite(b,LOW);
}
void digital_7(void) // Display 7
{
  unsigned char j;
  for(j=5;j<=7;j++)
  digitalWrite(j,HIGH);
  digitalWrite(dp,LOW);
  for(j=8;j<=11;j++)
  digitalWrite(j,LOW);
}
void digital_8(void) // Display 8
{
  unsigned char j;
  for(j=5;j<=11;j++)
  digitalWrite(j,HIGH);
  digitalWrite(dp,LOW);
}
void digital_9(void) // Display 9
{
  unsigned char j;
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
  digitalWrite(dp,LOW);
}
void setup()
{
int i;// Set variable
for(i=4;i<=11;i++)
pinMode(i,OUTPUT);// Set pin 4-11 to “output”
}
void loop()
{
  while(1)
  {
    digital_0();// Display 0
    delay(1000);// Delay 1s
    digital_1();// Display 1
    delay(1000);// Delay 1s
    digital_2();// Display 2
    delay(1000); // Delay 1s
    digital_3();// Display 3
    delay(1000); // Delay 1s
    digital_4();// Display 4
    delay(1000); // Delay 1s
    digital_5();// Display 5
    delay(1000); // Delay 1s
    digital_6();// Display 6
    delay(1000); // Delay 1s
    digital_7();// Display 7
    delay(1000); // Delay 1s
    digital_8();// Display 8
    delay(1000); // Delay 1s
    digital_9();// Display 9
    delay(1000); // Delay 1s
  }
}
//**********************************************************************************
