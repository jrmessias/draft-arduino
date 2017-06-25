/*
This program blink led with SOS in Morse Code
*/

// Variables
int s = 300;
int o = 800;

// Setup function
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

// Blink caracter
void character(int speed) {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(speed);
  digitalWrite(LED_BUILTIN, LOW);
  delay(300);
}

void loop() {
  // Blink S
  for (int x = 1; x <= 3; x++) {
    character(s);
  }
  delay(100);

  // Blink O
  for (int x = 1; x <= 3; x++) {
    character(o);
  }
  delay(100);

  // Blink S
  for (int x = 1; x <= 3; x++) {
    character(s);
  }

  // Delay
  delay(2000);
}
