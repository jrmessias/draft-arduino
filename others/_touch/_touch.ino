int touch = 2;

void setup() {
  pinMode(touch, INPUT);
}

void loop() {
  int hasTouch = digitalRead(touch);
  if (hasTouch == 1) {
    digitalWrite(touch, HIGH);
  }
}
