void kondisiPakan()
{
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);

    distanceCm = (duration / 2) / 27.6;

    lcd.setCursor(0, 0);
    sprintf(buffer, "Pakan:"); 
    lcd.print(buffer);
//    String distanceStr = String(distanceCm, 2);
//    sprintf(buffer, "%s", distanceStr.c_str()); 
    pakan = ((1 - distanceCm/20)*100);
    String pakanStr = String(pakan);
    sprintf(buffer, "%s", pakanStr.c_str());     
    lcd.setCursor(7, 0);
    lcd.print(pakan);

    lcd.setCursor(10, 0);
    lcd.print("%");

    Serial.print("Pakan :");
    Serial.print(pakan);
    Serial.println("%");
    if (pakan > 75)
    {
       lcd.setCursor(0, 1);
       sprintf(buffer,"Aman"); 
       lcd.print(buffer); 
    }
    else if (pakan > 25 && pakan < 75)
    {
       lcd.setCursor(0, 1);
       sprintf(buffer,"Sedang"); 
       lcd.print(buffer); 
    }
    else 
    {
      lcd.setCursor(0, 1);
      sprintf(buffer,"Hampir Habis"); 
      lcd.print(buffer);
    }
}
