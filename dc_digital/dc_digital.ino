#define pwmR 2
#define pwmL 4
void setup() {
  Serial.begin(9600);
   pinMode(pwmR, OUTPUT);
   pinMode(pwmL, OUTPUT);
}

void loop() {
   digitalWrite(pwmR, 50);
   digitalWrite(pwmL, 0);

}
