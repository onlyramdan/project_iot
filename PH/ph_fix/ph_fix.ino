const int potPin = A0;
unsigned long int totalValue; 
int buf[50],temp;
float value; 
float voltage;
float ph;
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
  for(int i=0;i<50;i++)
  {
    buf[i] = analogRead(potPin);
    delay(10);
  }
  for (int i=0;i<49;i++)
  {
    for(int j=i+1;j<50;j++)
    {
      if(buf[i]>buf[j])
      {
      temp = buf[i];
      buf[i]= buf[j];
      buf[j]= temp;
      }
    }  
   }
   totalValue=0;
   for (int i=2; i<48; i++ )
   {
    totalValue +=buf[i]; 
   }
  value = totalValue/46;
  
  voltage = value * (3.3 / 4095.0); 
  Serial.print("Voltage: "); 
  Serial.println(voltage); 
  ph_step = (ph4 - ph7)/3;
  
  ph = 7.00 + ((ph7-voltage)/ph_step);
  Serial.print("PH : ");
  Serial.println(ph);
  delay(500); 
}
