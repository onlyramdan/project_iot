void sensorPH(){
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
  
