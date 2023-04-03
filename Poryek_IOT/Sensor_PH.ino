void sensorPH(){
  value = analogRead(potPin);
  Serial.print("PH :");
  float voltage = value*(3.3/4095.0);
  ph= (3.3*voltage);
  Serial.println(ph);
  if (ph >= 6 && ph <= 8){  
    isgoodPh = true;
    }
  }
