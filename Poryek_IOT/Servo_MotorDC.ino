void kasihPakan()
{
  String url = "http://192.168.255.125/lelecuy/apiKasihPakan.php";
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
  // #1
  JsonObject obj1 = doc["data"][0];
  Serial.println(obj1);
 
  jam1 = obj1["jam"];
  menit1 = obj1["menit"];
  lamaPakan1 = obj1["lamaPakan"];
  kecepatan1 = obj1["kecepatan"];
  
  waktuPakan1 = jam1*60*60 + menit1*60;
  // #2
  JsonObject obj2 = doc["data"][1];
  Serial.println(obj2);
 
  jam2 = obj2["jam"];
  menit2 = obj2["menit"];
  lamaPakan2 = obj2["lamaPakan"];
  kecepatan2 = obj2["kecepatan"];
  
  waktuPakan2 = jam2*60*60 + menit2*60;
  // #3
  JsonObject obj3 = doc["data"][2];
 
  jam3 = obj3["jam"];
  menit3 = obj3["menit"];
  lamaPakan3 = obj3["lamaPakan"];
  kecepatan3 = obj3["kecepatan"];
  
  waktuPakan3 = jam3*60*60 + menit3*60;
  // #4
  JsonObject obj4 = doc["data"][3];
 
  jam4 = obj4["jam"];
  menit4 = obj4["menit"];
  lamaPakan4 = obj4["lamaPakan"];
  kecepatan4 = obj4["kecepatan"];
  
  waktuPakan4 = jam4*60*60 + menit4*60;
  
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
  if (waktuPakan1 == timeinfo.tm_hour * 60 * 60 + timeinfo.tm_min*60 && kondisiAir){
      if(!isFeeding){
      Serial.println("========== Kondisi Makan =========="); 
      myservo.write(45);
      ledcWrite(Channel_14,kecepatan1);    
      ledcWrite(Channel_15,0);
      Serial.println("Pakan Terbuka");
      delay(lamaPakan1);
      myservo.write(0);
      ledcWrite(Channel_14,0);    
      ledcWrite(Channel_15,0);
      Serial.println("Pakan Tertutup");
      isFeeding = true;
      Serial.println("=================================="); 
      }
  } else if ((waktuPakan2 == timeinfo.tm_hour * 60 * 60 + timeinfo.tm_min*60) && kondisiAir )
  {
    if(!isFeeding){
      Serial.println("========== Kondisi Makan =========="); 
      myservo.write(45);
      ledcWrite(Channel_14,kecepatan2);    
      ledcWrite(Channel_15,0);
      Serial.println("Pakan Terbuka");
      delay(lamaPakan2);
      myservo.write(0);
      ledcWrite(Channel_14,0);    
      ledcWrite(Channel_15,0);
      Serial.println("Pakan Tertutup");
      isFeeding = true;
      Serial.println("=================================="); 
      }
  } else if ((waktuPakan3 == timeinfo.tm_hour * 60 * 60 + timeinfo.tm_min*60) && kondisiAir )
  {
    if(!isFeeding){
      Serial.println("========== Kondisi Makan =========="); 
      myservo.write(45);
      ledcWrite(Channel_14,kecepatan3);    
      ledcWrite(Channel_15,0);
      Serial.println("Pakan Terbuka");
      delay(lamaPakan3);
      myservo.write(0);
      ledcWrite(Channel_14,0);    
      ledcWrite(Channel_15,0);
      Serial.println("Pakan Tertutup");
      isFeeding = true;
      Serial.println("=================================="); 
       }
  } else if ((waktuPakan4 == timeinfo.tm_hour * 60 * 60 + timeinfo.tm_min*60)&& kondisiAir )
  {
    if(!isFeeding){
      Serial.println("========== Kondisi Makan =========="); 
      myservo.write(45);
      ledcWrite(Channel_14,kecepatan4);    
      ledcWrite(Channel_15,0);
      Serial.println("Pakan Terbuka");
      delay(lamaPakan4);
      myservo.write(0);
      ledcWrite(Channel_14,0);    
      ledcWrite(Channel_15,0);
      Serial.println("Pakan Tertutup");
      isFeeding = true;
      Serial.println("=================================="); 
       }
  } else{
    isFeeding = false;
  }
 }
