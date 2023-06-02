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
    sprintf(buffer, "Jarak : "); 
    lcd.print(buffer);
    String distanceStr = String(distanceCm, 2);
    sprintf(buffer, "%s", distanceStr.c_str()); 
    lcd.setCursor(7, 0);
    
    lcd.print(distanceCm);

    if (distanceCm > 5)
    {
        pakan = "Hampir Habis";
        lcd.setCursor(0, 1);
        sprintf(buffer, "%s", pakan.c_str());     
        lcd.print(buffer); 
    }
    else
    {
       pakan = "Aman";
       lcd.setCursor(0, 1);
       sprintf(buffer, "%s", pakan.c_str()); 
       lcd.print(buffer); 
       
    }
}
