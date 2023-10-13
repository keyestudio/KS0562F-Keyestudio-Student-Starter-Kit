//**********************************************************************************
int potpin=A0;// Initialize the analog pin AO of adjustable potentiometer
int ledpin=10;// Initialize the digital pin 10
int val=0;// Define val as an initial value of 0

void setup()
{
Serial.begin(9600);// Set baud rate to 9600
pinMode(ledpin,OUTPUT);// Set digital pin 10 to "output"
pinMode(potpin, INPUT); // Set analog pin A0 to "input"
}

void loop()
{
val=analogRead(potpin);// Read the analog value of analog pin A1, assign it to val 
analogWrite(ledpin,val/4);
Serial.println(val);// Print the value of val
}
//**********************************************************************************
