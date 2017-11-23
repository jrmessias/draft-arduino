const int ledRed = 12;
const int ledGreen = 10;
const int ledYellow = 8;
const int buttonRed = 6;
const int buttonGreen = 5;
const int buttonYellow = 4;
int buzzer = 2;
int stateRed = 0;
int stateGreen = 0;
int stateYellow = 0;

void setup() {
  pinMode(buzzer, OUTPUT);
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

  if (stateRed && !stateGreen && !stateYellow) {
    digitalWrite(ledRed, HIGH);
    tone(buzzer, 100);
  }

  if (!stateRed && stateGreen && !stateYellow) {
    digitalWrite(ledGreen, HIGH);
    tone(buzzer, 500);
  }

  if (!stateRed && !stateGreen && stateYellow) {
    digitalWrite(ledYellow, HIGH);
    tone(buzzer, 1000);
  }
  
  digitalWrite(ledRed, LOW);
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledYellow, LOW);
  noTone(buzzer);
}
