const int potPin = A0;
float ph;
float value = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(potPin, INPUT);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  value = analogRead(potPin);
  Serial.print(value);
  Serial.print("| PH : ");
  float voltage = value*(3.3/4095.0);
  ph= (3.3*voltage);
  Serial.println(ph);
  delay(500);
}
