//**********************************************************************************
const byte SWITCH_PIN = 4; // Connect tilt switch to D4
int led1 = 8;  //Define led1 as digital port 8
int led2 = 9; 
int led3 = 10; 
int led4 = 11; 

byte switch_state = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(SWITCH_PIN, INPUT);
  for(int i=8;i<12;i++)
  {
    pinMode(i, OUTPUT);
  } 
  for(int i=8;i<12;i++)
  {
    digitalWrite(i,0);
  } 
}

void loop()
{
  switch_state = digitalRead(SWITCH_PIN); 
  Serial.println(switch_state);
  if (switch_state == 0) 
  {
    for(int i=8;i<12;i++)
    {
      digitalWrite(i,1);
      delay(500);
    } 
  }
  if (switch_state == 1) 
  {
    for(int i=11;i>7;i--)
    {
      digitalWrite(i,0);
      delay(500);
    }
  }
}
//**********************************************************************************
