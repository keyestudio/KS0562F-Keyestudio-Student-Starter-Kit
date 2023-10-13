//*********************************************************************************
int servoPin = 9;//Define the Servo pin

void setup() {
  pinMode(servoPin, OUTPUT);//Set the servo pin to output
}

void loop() {
  servopulse(servoPin, 0);//Rotate servo to 0 degree
  delay(1000);//Delay 1s
  servopulse(servoPin, 45);//Rotate servo to 45 degree
  delay(1000);
  servopulse(servoPin, 90);//Rotate servo to 90 degree
  delay(1000);
}

void servopulse(int pin, int myangle) { //Impulse function
  int pulsewidth = map(myangle, 0, 180, 500, 2500); //Map the angle to pulse width
  for (int i = 0; i < 10; i++) { //Output the pulse for times
    digitalWrite(pin, HIGH);//Put servo pin at a high level
    delayMicroseconds(pulsewidth);//Delay the microseconds of pulse width
    digitalWrite(pin, LOW);//Put servo pin at a low level
    delay(20 - pulsewidth / 1000);
  }
}
//*********************************************************************************
