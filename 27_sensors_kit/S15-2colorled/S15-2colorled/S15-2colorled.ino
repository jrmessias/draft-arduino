int redPin = 11; // red LED
int greenPin = 10; // green LED (S)
int value;
long randNumber;

void setup () {
  Serial.begin(9600);
  pinMode (redPin, OUTPUT);
  pinMode (greenPin, OUTPUT);
  randomSeed(analogRead(0));
}

// To green
void loop () {
  randNumber = random(1, 3);
  if (randNumber == 1) {
    analogWrite (redPin, 255);
    analogWrite (greenPin, 0);

  }
  else {
    analogWrite (redPin, 0);
    analogWrite (greenPin, 255);
  }
  delay (100);
  Serial.println(randNumber);
}
