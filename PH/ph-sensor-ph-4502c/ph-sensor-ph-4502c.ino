float ph_step;

float ph4 = 3.11;
float ph7 = 2.39;
void setup() 
{ 
  Serial.begin(9600);
  pinMode(potPin, INPUT); 
} 
 
void loop() 
{ 

  value = analogRead(potPin); 
  voltage = value * (3.3 / 4095.0); 
  Serial.print("Voltage :"); 
  Serial.println(voltage); 
  ph_step = (ph4 - ph7)/3;
  
  ph = 7.00 + ((ph7-voltage)/ph_step);
  Serial.print("PH : ");
  Serial.println(ph);
  delay(500)

}
