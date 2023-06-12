void kasihPakan()
{
  Serial.println("========== RESPONSE GET ==========");
  String url = "http://afeesh.my.id/api/api.php";
  HTTPClient http;
  int httpCode;
  String response;
  
  http.begin(url);
  httpCode = http.GET();
  response = http.getString();
  delay(5000);
  Serial.print("Response GET :");
  Serial.println("JSON :");
  Serial.println(response);
  DynamicJsonDocument doc(1024);
  deserializeJson(doc, response);
  deserializeJson(doc,response);
  // #1
  JsonObject obj1 = doc["data"][0];
  
 
  jam1 = obj1["jam"];
  menit1 = obj1["menit"];
  gramPakan1 = obj1["bobotPakan"];
  kecepatan1 = obj1["kecepatan"];
  
//  lamaPakan1 = (gramPakan1/4.4);
  lamaPakan1 = gramPakan1*228;
  
  waktuPakan1 = jam1*60*60 + menit1*60;
  // #2
  JsonObject obj2 = doc["data"][1];
 
  jam2 = obj2["jam"];
  menit2 = obj2["menit"];
  gramPakan2 = obj2["bobotPakan"];
  kecepatan2 = obj2["kecepatan"];

//  lamaPakan2 = (gramPakan2/4.4);
  lamaPakan2 = gramPakan2*228;
  waktuPakan2 = jam2*60*60 + menit2*60;
  // #3
  JsonObject obj3 = doc["data"][2];
 
  jam3 = obj3["jam"];
  menit3 = obj3["menit"];
  gramPakan3 = obj3["bobotPakan"];
  kecepatan3 = obj3["kecepatan"];
  
//  lamaPakan3 = (gramPakan3/4.4);
  lamaPakan3 = gramPakan3*228;
  waktuPakan3 = jam3*60*60 + menit3*60;
  // #4
  JsonObject obj4 = doc["data"][3];
 
  jam4 = obj4["jam"];
  menit4 = obj4["menit"];
  lamaPakan4 = obj4["bobotPakan"];
  kecepatan4 = obj4["kecepatan"];

//  lamaPakan4 = (gramPakan4/4.4);
  lamaPakan4 = gramPakan4*228;
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
  Serial.println("================================");
  if (waktuPakan1 == timeinfo.tm_hour * 60 * 60 + timeinfo.tm_min*60 && kondisiAir){
      if(!isFeeding){
      Serial.println("========== Kondisi Makan =========="); 
      Serial.println("Pakan Terbuka");
      //Motor DC nyala
      ledcWrite(Channel_14,kecepatan1);    
      ledcWrite(Channel_15,0);
      for (int i = 0; i<(lamaPakan1/114) ;i++){
        myservo.write(60);
        delay(114);
        myservo.write(90);
        delay(114);
      }
      delay(lamaPakan1 + 5000);
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
      Serial.println("Pakan Terbuka");
      //Motor DC nyala
      ledcWrite(Channel_14,kecepatan2);    
      ledcWrite(Channel_15,0);
       for (int i = 0; i<(lamaPakan2/114) ;i++){
        myservo.write(60);
        delay(114);
        myservo.write(90);
        delay(114);
      }
      delay(lamaPakan2 + 5000);
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
      Serial.println("Pakan Terbuka");
      //Motor DC nyala
      ledcWrite(Channel_14,kecepatan3);    
      ledcWrite(Channel_15,0);
      for (int i = 0; i<(lamaPakan3/114); i++){
        myservo.write(60);
        delay(114);
        myservo.write(90);
        delay(114);
      }
      delay(lamaPakan3 + 5000);
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
      Serial.println("Pakan Terbuka");
      //Motor DC nyala
      ledcWrite(Channel_14,kecepatan4);    
      ledcWrite(Channel_15,0);
      for (int i = 0; i<(lamaPakan4/114);  i++){
        myservo.write(60);
        delay(114);
        myservo.write(90);
        delay(114);
      }
      delay(lamaPakan4 + 5000);
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
