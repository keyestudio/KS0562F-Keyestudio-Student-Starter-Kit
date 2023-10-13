//**********************************************************************
int redled =10; // Initialize digital pin 10.
int yellowled =7; // Initialize digital pin 7.
int greenled =4; //Initialize digital pin 4.
void setup()
{
  pinMode(redled, OUTPUT); // Set red LED pin to “output”.
  pinMode(yellowled, OUTPUT); // Set yellow LED pin to “output”.
  pinMode(greenled, OUTPUT); // Set green LED pin to “output”.
}
void loop()
{
  digitalWrite(greenled, HIGH);// Light green LED up
  delay(5000);// Delay 5s
  digitalWrite(greenled, LOW); // Turn green LED off
  for(int i=0;i<3;i++)// Blink for 3 times
  {
    delay(500);// Delay 0.5s
    digitalWrite(yellowled, HIGH);// Light yellow LED up
    delay(500);// Delay 0.5s
    digitalWrite(yellowled, LOW);// Turn yellow LED off
  } 
  delay(500);// Delay 0.5s
  digitalWrite(redled, HIGH);// Light red LED up
  delay(5000);// Delay 0.5s
  digitalWrite(redled, LOW);// Turn red LED off
}
//**********************************************************************
