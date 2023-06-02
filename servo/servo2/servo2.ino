#include <ESP32Servo.h>
Servo servo;
//servoPin
#define servoPin 26
void setup() {
  servo.attach(servoPin);
  Serial.begin(9600);
}
void loop() {
  servo.write(0);
  Serial.println("Buka Servo");
  delay(5000);
  servo.write(90);
  Serial.println("Tutup Servo");
}
