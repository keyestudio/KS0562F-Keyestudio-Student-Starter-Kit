//**********************************************************************
int buzzerPin = 8;   //Define buzzer pin

void setup ()
{
  pinMode (buzzerPin, OUTPUT);
}

void loop ()
{
  digitalWrite (buzzerPin, HIGH);
  delay (500);
  digitalWrite (buzzerPin, LOW);
  delay (500);
}
//**********************************************************************************
