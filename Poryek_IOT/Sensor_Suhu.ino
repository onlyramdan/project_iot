void sensorSuhu(){
  DS18B20.requestTemperatures();
  suhu = DS18B20.getTempCByIndex(0);
  Serial.print("SUHU :");
  Serial.println(suhu);
  if (suhu >= 26 && suhu <= 30){  
    isgoodSuhu = true;
   }
  }
