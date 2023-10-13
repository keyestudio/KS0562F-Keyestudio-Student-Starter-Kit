//**********************************************************************
int ledPin = 10; // Define digital port 10

void setup()
{
  pinMode(ledPin, OUTPUT);// Set ledPin to output
}

void loop()
{
  for (int a=0; a<=255;a++)// Set to gratually lighten the led
  {
    analogWrite(ledPin,a); // Light led up, adjust the brightness within the range of 0-255, led is the brightest at 255
    delay(10); // Delay 0.01S
  }
  for (int a=255; a>=0;a--) // Set to gratually darken the led
  {
    analogWrite(ledPin,a); // Light led up, adjust the brightness within the range of 0-255, led is the brightest at 255
    delay(10); // Delay 0.01s
  }
  delay(1000);// Delay 1s
}
//**********************************************************************
