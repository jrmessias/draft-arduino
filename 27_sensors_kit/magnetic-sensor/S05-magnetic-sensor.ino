int portAnalog = A5;
int sensorValue = 0;

void setup () {
  pinMode (LED_BUILTIN, OUTPUT);
  Serial.begin (9600);
}

void loop () {
  sensorValue = analogRead (portAnalog);
  digitalWrite (LED_BUILTIN, HIGH);
  delay (sensorValue);
  digitalWrite (LED_BUILTIN, LOW);
  delay (sensorValue);
  Serial.println (sensorValue, DEC);
}
