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
