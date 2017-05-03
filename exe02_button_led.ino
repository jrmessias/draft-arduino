// const int ledPin = 13 = LED_BUILTIN
const int button = 2;
int buttonStatus = 0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  buttonStatus = digitalRead(button);
  
  if(buttonStatus == HIGH) {
    digitalWrite(LED_BUILTIN, HIGH);
  }else{
    digitalWrite(LED_BUILTIN, LOW);
  }
}
