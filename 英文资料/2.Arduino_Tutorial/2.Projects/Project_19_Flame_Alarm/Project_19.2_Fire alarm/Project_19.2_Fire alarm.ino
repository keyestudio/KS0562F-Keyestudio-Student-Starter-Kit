//**********************************************************************************
const int ledpin = 10;
const int buzzerpin = 12;
const int flamepin = A0;
const int thereshold = 300;

void setup() {
  // Put the setup code here, run it once:
  Serial.begin(9600);
  pinMode(ledpin, OUTPUT);
  pinMode(buzzerpin, OUTPUT);
  pinMode(flamepin, INPUT);
}
 
void loop() {
  // Put the main code here, run in loop:
  int flamesenseval = analogRead(flamepin);
  Serial.println(flamesenseval);
  if (flamesenseval >= thereshold) {
    digitalWrite (buzzerpin, HIGH); //Turn on the buzzer
    digitalWrite(ledpin, HIGH); // Light LED up
    delay(500); // Delay 0.5s
    digitalWrite (buzzerpin, LOW); //Turn off the buzzer
    digitalWrite(ledpin, LOW); // Light LED off
    delay(500); 
  }
  else
  {
    digitalWrite (buzzerpin, LOW); 
    digitalWrite(ledpin, LOW); 
  }
}
//**********************************************************************************
