//**********************************************************************************
int flamepin=A0;// Initialize analog pin A0
int val=0;// Define val as an initial vallue of 0

void setup()
{
Serial.begin(9600);// Set baud rate to 9600
pinMode(flamepin, INPUT); //Set analog pin A0 to"input"”
}

void loop()
{
val=analogRead(flamepin);// Read the analog value of the analog pin A0, assign it to val
Serial.println(val);// Print the value val
delay(200);// Wait for 0.2s
}
//**********************************************************************************
