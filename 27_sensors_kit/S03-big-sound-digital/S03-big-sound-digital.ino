int sensorInput = 3;
int value = 0;

void setup ()
{
  pinMode (LED_BUILTIN, OUTPUT);
  pinMode (sensorInput, INPUT);
  Serial.begin(9600);
}

void loop ()
{
  value = digitalRead(sensorInput);
  Serial.println(value);
 
  if (value == HIGH)
  {
    digitalWrite (LED_BUILTIN, HIGH);
  }
  else
  {
    digitalWrite (LED_BUILTIN, LOW);
  }
  delay(500);
}
