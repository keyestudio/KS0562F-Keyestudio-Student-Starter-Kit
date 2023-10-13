//**********************************************************************
int led = 10;  //Define digital port 10

void setup() {
  pinMode(led, OUTPUT);  //Set led to output
}

void loop() {
  digitalWrite(led, HIGH);  //Light led up
  delay(1000);              //Delay 1s
  digitalWrite(led, LOW);   //Turn led off
  delay(1000);              //Delay 1s
}
//**********************************************************************
