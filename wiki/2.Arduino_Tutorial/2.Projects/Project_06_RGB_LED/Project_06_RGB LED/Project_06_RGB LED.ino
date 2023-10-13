//**********************************************************************
int redpin = 11; //Select red LED pin 11.
int greenpin = 10; //Sekect green LED pin 10.
int bluepin = 9; // Select blue LED pin 9.

int val = 0;

void setup() {
  pinMode(redpin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  pinMode(bluepin, OUTPUT);

  digitalWrite(redpin,LOW);
  digitalWrite(greenpin,LOW);
  digitalWrite(bluepin,LOW);
}

void loop() {
  for(val=255; val>0; val--)
  {
    analogWrite(redpin,val);
    analogWrite(greenpin,(255 - val));
    analogWrite(bluepin,(128 - val));
    delay(0.001 * 1000);
  }
  for(val=0; val<255; val++)
  {
    analogWrite(redpin,val);
    analogWrite(greenpin,(255 - val));
    analogWrite(bluepin,(128 - val));
    delay(0.001 * 1000);
  }
}
//**********************************************************************
