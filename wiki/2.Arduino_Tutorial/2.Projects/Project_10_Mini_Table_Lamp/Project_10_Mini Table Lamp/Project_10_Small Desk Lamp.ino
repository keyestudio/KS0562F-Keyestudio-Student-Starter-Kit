//**********************************************************************************
int buttonPin = 7;             //Connect button to digital pin 7
int ledPin = 11;               //Connect LED to digital pin 11
int ledState = LOW;            // ledState records the state of LED
int buttonState;               // buttonState records the state of button
int lastButtonState = LOW;     // lastbuttonState records the last state of button
long lastDebounceTime = 0;
long debounceDelay = 50;       //Remove jitter time

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, ledState);
}

void loop() {   
  int reading = digitalRead(buttonPin);  //reading records the data of buttonPin

  // Record the present time as soon as a change in data is detected.
  if (reading != lastButtonState) {
      lastDebounceTime= millis();
  }

 // Wait for 50ms, check again whether the button state is the same as that of the current button. If it is not, change the button state. Yet if the button is at high(being pressed), change the led state.
  if ((millis() - lastDebounceTime) >debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == HIGH) {
          ledState= !ledState;
      }
    }
  }

  digitalWrite(ledPin, ledState);

  // Change the last state value of button
  lastButtonState = reading;
}
//**********************************************************************************
