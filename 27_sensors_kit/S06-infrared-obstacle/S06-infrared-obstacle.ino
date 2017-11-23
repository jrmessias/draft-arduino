int sensorPort = 3;
int val;

void setup ()
{
  pinMode (LED_BUILTIN, OUTPUT);
  pinMode (sensorPort, INPUT);
  Serial.begin (9600);
}

void loop ()
{
  val = digitalRead (sensorPort) ;
  if (val == HIGH)
  {
    digitalWrite (LED_BUILTIN, HIGH);
  }
  else
  {
    digitalWrite (LED_BUILTIN, LOW);
  }
  Serial.println (val, DEC);
}
