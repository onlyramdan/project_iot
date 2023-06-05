#include <ESP32Servo.h>

#define SERVO_PIN 26 // ESP32 pin GIOP26 connected to servo motor

Servo servoMotor;

void setup() {
  servoMotor.attach(SERVO_PIN);  // attaches the servo on ESP32 pin
  servoMotor.write(90);
  delay(1000);
  servoMotor.write(45);
  delay(1000);
  servoMotor.write(90);
}
void loop() {
}
