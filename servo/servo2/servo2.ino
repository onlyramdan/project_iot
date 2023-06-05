#include <ESP32Servo.h>
Servo servo;
//servoPin
#define servoPin 26
void setup() {
  servo.attach(servoPin);
  Serial.begin(9600);
}
void loop() {
  servo.write(90);
  Serial.println("Buka Servo");
  delay(1000);
  servo.write(45);
  Serial.println("Tutup Servo");
}
