int sensorPin = A0;
int sensorValue = 0;

void setup ()
{
  pinMode (LED_BUILTIN, OUTPUT);
  Serial.begin (9600);
}

void loop ()
{
  sensorValue = analogRead (sensorPin);
  if (sensorValue > 25) {
    digitalWrite (LED_BUILTIN, HIGH);
  } else {
    digitalWrite (LED_BUILTIN, LOW);
  }
  delay (sensorValue);
  Serial.println (sensorValue, DEC);
}
