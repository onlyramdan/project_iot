const int potPin = A0;
double value; 
double voltage;
double ph;
 
void setup() 
{ 
  Serial.begin(9600);
  pinMode(potPin, INPUT); 
} 
 
void loop() 
{ 
  value = analogRead(potPin); 
  voltage = value * (3.3 / 4095.0); 
  Serial.println(voltage); 
  ph= (3.3*voltage);
  delay(500); 
}
