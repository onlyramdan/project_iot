#include <OneWire.h>
#include <DallasTemperature.h>
#define sensorSuhu_pin 27 

OneWire oneWire(sensorSuhu_pin);
DallasTemperature DS18B20(&oneWire); 

float suhu;

void setup() {
 
Serial.begin(115200);
  //Suhu
  DS18B20.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  DS18B20.requestTemperatures();
  suhu = DS18B20.getTempCByIndex(0);
  Serial.print("SUHU :");
  Serial.println(suhu);
  delay(10000);
}
