void sensorPH(){
//  for(int i=0;i<50;i++)
//  {
//    buf[i] = analogRead(phtPin);
//    delay(10);
//  }
//  for (int i=0;i<49;i++)
//  {
//    for(int j=i+1;j<50;j++)
//    {
//      if(buf[i]>buf[j])
//      {
//      temp = buf[i];
//      buf[i]= buf[j];
//      buf[j]= temp;
//      }
//    }  
//   }
//   totalValue=0;
//   for (int i=2; i<48; i++ )
//   {
//    totalValue +=buf[i]; 
//   }
//  value = totalValue/46;
//  
//  voltage = value * (3.3 / 4095.0); 
//  Serial.print("Voltage: "); 
//  Serial.println(voltage); 
//  ph_step = (ph4 - ph7)/3;
//  
//  ph = 7.00 + ((ph7-voltage)/ph_step);
//  Serial.print("PH : ");
//  Serial.println(ph);
//  delay(500); 
  //Kondisi 
  
  nilai_analog_PH = analogRead(ph_Pin);
//  Serial.print("Nilai ADC Ph: ");
//  Serial.print(nilai_analog_PH);
  TeganganPh = 3.3 / 4095 * nilai_analog_PH;
//  Serial.print("TeganganPh: ");
//  Serial.println(TeganganPh, 3);

  PH_step = (PH4 - PH7) / 3;
  ph = 7.00 + ((PH7 - TeganganPh) / PH_step);
  Serial.print("Nilai PH cairan: ");
  Serial.println(ph, 2);
  delay(1000);
  if (ph >= 6 && ph <= 8){  
    isgoodPh = true;
  }
}
  
