const int button = 2;
int buttonState = 0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  buttonState = digitalRead(button);

  if (buttonState == HIGH) { //Se botão estiver pressionado (HIGH)
    digitalWrite(LED_BUILTIN, HIGH); // acende o led do pino 13.
  }
  else { //se não estiver pressionado
    digitalWrite(LED_BUILTIN, LOW); //deixa o led do pino 13 apagado
  }
}
