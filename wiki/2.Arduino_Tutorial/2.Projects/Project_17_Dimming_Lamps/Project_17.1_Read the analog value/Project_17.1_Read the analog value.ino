//**********************************************************************************
int potpin=A0;//Initialize the analog pin AO of adjustable potentiometer
int val=0;// Define val as an initial value of 0

void setup()
{
Serial.begin(9600);// Set the baud rate to 9600
pinMode(potpin, INPUT); //Set the analog pin AO to "input"
}

void loop()
{
val=analogRead(potpin);// Read the analog value of analog pin A0, assign it to val 
Serial.println(val);// Print the value of val
delay(200); //Delay 0.2s
}
//**********************************************************************************
