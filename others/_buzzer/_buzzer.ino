#define BUZ_PIN 3

void setup()
{
  pinMode(BUZ_PIN, OUTPUT); // buzzer
}

void loop()
{
  delay(2000);
  tone(BUZ_PIN, 262, 200); //DO
  delay(200);
  tone(BUZ_PIN, 294, 300); //RE
  delay(200);
  tone(BUZ_PIN, 330, 300); //MI
  delay(200);
  tone(BUZ_PIN, 349, 300); //FA
  delay(300);
  tone(BUZ_PIN, 349, 300); //FA
  delay(300);
  tone(BUZ_PIN, 349, 300); //FA
  delay(300);
  tone(BUZ_PIN, 262, 100); //DO
  delay(200);
  tone(BUZ_PIN, 294, 300); //RE
  delay(200);
  tone(BUZ_PIN, 262, 100); //DO
  delay(200);
  tone(BUZ_PIN, 294, 300); //RE
  delay(300);
  tone(BUZ_PIN, 294, 300); //RE
  delay(300);
  tone(BUZ_PIN, 294, 300); //RE
  delay(300);
  tone(BUZ_PIN, 262, 200); //DO
  delay(200);
  tone(BUZ_PIN, 392, 200); //SOL
  delay(200);
  tone(BUZ_PIN, 349, 200); //FA
  delay(200);
  tone(BUZ_PIN, 330, 300); //MI
  delay(300);
  tone(BUZ_PIN, 330, 300); //MI
  delay(300);
  tone(BUZ_PIN, 330, 300); //MI
  delay(300);
  tone(BUZ_PIN, 262, 200); //DO
  delay(200);
  tone(BUZ_PIN, 294, 300); //RE
  delay(200);
  tone(BUZ_PIN, 330, 300); //MI
  delay(200);
  tone(BUZ_PIN, 349, 300); //FA
  delay(300);
  tone(BUZ_PIN, 349, 300); //FA
  delay(300);
  tone(BUZ_PIN, 349, 300); //FA
  delay(300);
}
