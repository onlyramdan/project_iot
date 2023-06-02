#include <ArduinoJson.h>
#include <ESP32Servo.h>
#include <WiFi.h>
#include "time.h"
#include <HTTPClient.h>
#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include <DallasTemperature.h>

//Sensor Suhu Pin
#define sensorSuhu_pin 27 

OneWire oneWire(sensorSuhu_pin);
DallasTemperature DS18B20(&oneWire); 

float suhu;

//Sensor PH pin
const int potPin = A0;
unsigned long int totalValue; 
int buf[50],temp;
float value; 
float voltage;
float ph;
float ph_step;

float ph4 = 3.11;
float ph7 = 2.39;

//ULTRASONIK DAN LCD
// Ultrasonic Pin
const int trigPin = 5;
const int echoPin = 18;

char buffer[16];

// LCD row
int lcdColumns = 16;
int lcdRows = 2;



long duration;
float distanceCm;

LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);

//motor Dc Pin
#define BTS_RPwm 2
#define BTS_LPwm 4

//servoPin
#define servoPin 26

// channel assignments 
const int  Channel_15 = 15 ;// & PWM channel 0, for BTS pin L_PWM 
const int  Channel_14 = 14 ;// & PWM channel 1, for BTS pin R_PWM 

// Channel Variables 
const int freq = 1000;//  Set up PWM Frequency
const int  res = 8;//  Set up PWM Resolution 

//inisiasi Servo
Servo myservo;

//variable untuk motor dan servo
int pos =0;
// Varialble Untuk yang 1
int jam1 ;
int menit1;
int lamaPakan1;
int kecepatan1;
int waktuPakan1; 
// Varialble Untuk yang 2
int jam2;
int menit2;
int lamaPakan2;
int kecepatan2;
int waktuPakan2; 
// Varialble Untuk yang 3
int jam3;
int menit3;
int lamaPakan3;
int kecepatan3;
int waktuPakan3; 
// Varialble Untuk yang 4
int jam4 ;
int menit4;
int lamaPakan4;
int kecepatan4;
int waktuPakan4; 

//Varible Waktu dan kondisi kasih pakan
unsigned long startMillis;

bool isFeeding = false;

//Wifi
const char* ssid       = "Ghazi";
const char* password   = "Sarimiisi8";

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

//Kondisi Pakan
String pakan;
unsigned long lastTime = 0;
unsigned long timerDelay = 20000;

//Kondisi Air
bool isgoodPh = false;
bool isgoodSuhu = false;
bool kondisiAir = false;

//isiasi fungsi
  void kondisiPakan();
  void kasihPakan();
  void sensorSuhu();
  void sensorPH();
  void Post_monitoring();

void setup()
{
  Serial.begin(115200);
  //Suhu
  DS18B20.begin();  // insiasi Suhu
  //PH
  pinMode(potPin, INPUT);
  //Ulrasonik dan LCD 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  lcd.begin();
  lcd.backlight();
  
  ledcSetup(Channel_15, freq,res) ; // setup PWM channel for BST L_PWM
  ledcSetup(Channel_14, freq,res) ; // setup PWM channel for BST R_PWM
  ledcAttachPin( BTS_LPwm , Channel_15) ; // Attach BST L_PWM
  ledcAttachPin( BTS_RPwm , Channel_14) ; // Attach BST R_PWM
  myservo.attach(26);
  //connect to WiFi
  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
  }
  Serial.println(" CONNECTED");
  Serial.println(WiFi.localIP());

  //init and get the time
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  
  //Cek NTP Waktu
  printLocalTime();  
  
  //disconnect WiFi as it's no longer needed
  //  WiFi.disconnect(true);
  //  WiFi.mode(WIFI_OFF);
}
void loop()
{
  if(WiFi.status() != WL_CONNECTED) {
    Serial.println("WiFi not connected");
    Serial.printf("Connecting to %s ", ssid);
    WiFi.begin(ssid, password);
    Serial.println(" CONNECTED"); 
  }
  kondisiPakan();
  sensorSuhu();
  sensorPH();
  // Fuzzy Logic
  if(isgoodPh && isgoodSuhu){
    kondisiAir = true;
    }
  Post_monitoring();
  kasihPakan();
  lcd.clear();
}
