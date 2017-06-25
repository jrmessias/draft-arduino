const int ledRed = 12;
const int ledGreen = 10;
const int ledYellow = 8;
const int buttonRed = 6;
const int buttonGreen = 5;
const int buttonYellow = 4;
int stateRed = 0;
int stateGreen = 0;
int stateYellow = 0;

void setup() {
  pinMode(ledRed, OUTPUT);
  pinMode(buttonRed, INPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(buttonGreen, INPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(buttonYellow, INPUT);
}

void loop() {
  stateRed = digitalRead(buttonRed);
  stateGreen = digitalRead(buttonGreen);
  stateYellow = digitalRead(buttonYellow);

  if (stateRed == HIGH) {
    digitalWrite(ledRed, HIGH);
  }
  else {
    digitalWrite(ledRed, LOW);
  }

  if (stateGreen == HIGH) {
    digitalWrite(ledGreen, HIGH);
  }
  else {
    digitalWrite(ledGreen, LOW);
  }

  if (stateYellow == HIGH) {
    digitalWrite(ledYellow, HIGH);
  }
  else {
    digitalWrite(ledYellow, LOW);
  }
}
