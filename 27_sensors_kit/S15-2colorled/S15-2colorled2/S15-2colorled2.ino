int redPin = 11; // red LED
int greenPin = 10; // green LED (S)
int value;

void setup () {
  pinMode (redPin, OUTPUT);
  pinMode (greenPin, OUTPUT);
}

// To green
void loop () {
    analogWrite (greenPin, value);
    for (value = 255; value > 0; value--)
    {
    analogWrite (greenPin, value);
    analogWrite (redPin, 255 - value);
    delay (50);
    }
    //To red
    for (value = 0; value < 255; value++)
    {
    analogWrite (greenPin, value);
    analogWrite (redPin, 255 - value);
    delay (100);
    }
}
