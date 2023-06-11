void Post_monitoring(){
  if((millis()- lastTime) > timerDelay ){
    // cek WiFi connection status
    if(WiFi.status()== WL_CONNECTED){
      Serial.println("========== POST MONITORING ==========");
      const char* serverName ="http://afeesh.my.id/api/api-post.php";
      WiFiClient client;
      HTTPClient http;  
      //memulai HTTP
      http.begin(client, serverName);
      http.addHeader("Content-Type", "application/x-www-form-urlencoded");
      // Data to send with HTTP POST
      // Mengirim HTTP POST Data     
      String httpRequestData = "beratPakan="+ String(pakan) + "&suhu="+ String(suhu)+ "&ph="+ String(ph);           
      // Send HTTP POST request
      int httpResponseCode = http.POST(httpRequestData);
      
      // If you need an HTTP request with a content type: application/json, use the following:
      //http.addHeader("Content-Type", "application/json");
      //int httpResponseCode = http.POST("{\"api_key\":\"tPmAT5Ab3j7F9\",\"sensor\":\"BME280\",\"value1\":\"24.25\",\"value2\":\"49.54\",\"value3\":\"1005.14\"}");

      // If you need an HTTP request with a content type: text/plain
      //http.addHeader("Content-Type", "text/plain");
      //int httpResponseCode = http.POST("Hello, World!");
        
        Serial.print("PAKAN :");
        Serial.println(pakan);
        Serial.print("SUHU :");
        Serial.println(suhu);
        Serial.print("PH :");
        Serial.println(ph);
        Serial.println("HTTP Response code: ");
        Serial.println(httpResponseCode);
        Serial.println("================================");
       // free resources
       http.end();     
    }else{
      Serial.println("WiFi Disconnected");
      }   
      lastTime = millis();
    }
  
  }
