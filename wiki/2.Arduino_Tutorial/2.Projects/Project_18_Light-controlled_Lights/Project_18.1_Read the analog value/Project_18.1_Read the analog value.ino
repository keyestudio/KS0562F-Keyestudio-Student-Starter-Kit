//**********************************************************************************
int photocellpin=A0;//Initialize the analog pin A0 of photoresistor
int val=0;// Initialize the variable val as 0

void setup()
{
Serial.begin(9600);// Set baud rate to 9600
pinMode(photocellpin, INPUT); //Set analog pin A0 to "input"
}

void loop()
{
val=analogRead(photocellpin);// ead the value of photoresistor, assign it to val
Serial.println(val);// Print the value of val
delay(200);// Delay 0.2s
}
//**********************************************************************************
