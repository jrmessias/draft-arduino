const int potenciometro = A0;
const int led = 11;
int potenciometroValor = 0;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  potenciometroValor = analogRead(potenciometro);
  digitalWrite(led, HIGH);
  delay(potenciometroValor);
  digitalWrite(led, LOW);
  delay(potenciometroValor);
}
