void kasihPakan()
{
  String url = "http://192.168.229.125/lelecuy/apiKasihPakan.php";
  HTTPClient http;
  int httpCode;
  String response;
  
  http.begin(url);
  httpCode = http.GET();
  response = http.getString();
  delay(5000);
  
  Serial.println(response);
  DynamicJsonDocument doc(1024);
  deserializeJson(doc, response);
  deserializeJson(doc,response);
  JsonObject obj = doc["data"][0];
 
  jam = obj["jam"];
  menit = obj["menit"];
  detik = obj["detik"];
  lamaPakan = obj["lamaPakan"];
  kecepatan = obj["kecepatan"];
  waktuPakan = jam*60*60 + menit*60;
  
  if(httpCode == HTTP_CODE_OK){
    Serial.println("Succes");
    } else {
    Serial.printf("HTTP request failed with error code %d\n", httpCode);
    }
    
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time");
    return;
  }
  if (waktuPakan == timeinfo.tm_hour * 60 * 60 + timeinfo.tm_min*60){
      if(!isFeeding){
      myservo.write(180);
      ledcWrite(Channel_14,kecepatan);    
      ledcWrite(Channel_15,0);
      Serial.println("Pakan Terbuka");
      delay(lamaPakan);
      myservo.write(0);
      ledcWrite(Channel_14,0);    
      ledcWrite(Channel_15,0);
      Serial.println("Pakan Tertutup");
      isFeeding = true;
      }
  } else{
    isFeeding = false;
  }
 }
