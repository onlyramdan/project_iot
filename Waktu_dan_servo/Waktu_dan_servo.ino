#include <Arduino_JSON.h>
#include <ESP32Servo.h>
#include <WiFi.h>
#include "time.h"
//motor Dc

#define pwmR 2
#define pwmL 4

#define servoPin 26

Servo myservo;
int pos =0;
int jamPakan = 16;
int menPakan = 21;
int detik = 0;
int waktuPakan = jamPakan*60*60 + menPakan*60 + detik;

unsigned long startMillis;
bool isFeeding = false;

const char* ssid       = "Tifa";
const char* password   = "12345678";

const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 21600;
const int   daylightOffset_sec = 3600;

void printLocalTime()
{
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time");
    return;
  }
}

void setup()
{
  Serial.begin(115200);
  myservo.attach(26);
  pinMode(pwmR, OUTPUT);
  pinMode(pwmL, OUTPUT);
  //connect to WiFi
  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
  }
  Serial.println(" CONNECTED");
  
  //init and get the time
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  printLocalTime();

  //disconnect WiFi as it's no longer needed
  WiFi.disconnect(true);
  WiFi.mode(WIFI_OFF);
}

void loop()
{
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time");
    return;
  }
//Waktu Pakan pertama
  if (waktuPakan == timeinfo.tm_hour * 60 * 60 + timeinfo.tm_min*60 + timeinfo.tm_sec && !isFeeding) {
  Serial.print("Waktu Kasih Pakan :");
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
  startMillis = millis();
  isFeeding = true;
  myservo.write(180);
  digitalWrite(pwmR, 100);
  digitalWrite(pwmL, LOW);
  delay(1000);
  Serial.println("Pakan Terbuka");
  } else if (isFeeding && millis() - startMillis >= 30000){
  isFeeding = false;
  myservo.write(0);
  delay(1000);
  digitalWrite(pwmR, LOW);
  digitalWrite(pwmL, LOW);
  Serial.println("Pakan Tertutup");
  }
}
