//**********************************************************************************
int photocellpin=A0;// Initialize the analog pin A0 of photoresistor
int ledpin=11;// Initialize the digital pin 11
int val=0;// Initialize the variable val as 0

void setup()
{
Serial.begin(9600);// Set baud rate to 9600
pinMode(ledpin,OUTPUT);// Set digital pin 11 to "output"
pinMode(photocellpin,INPUT); //Set analog pin A0 to "input"
}

void loop()
{
val=analogRead(photocellpin);//Read the analog value of photoresistor, assign it to val
Serial.println(val);//Print the value of val
analogWrite(ledpin,val/4);//Set brightness(maximum 255)
delay(10);// Delay 0.01s
}
//**********************************************************************************
