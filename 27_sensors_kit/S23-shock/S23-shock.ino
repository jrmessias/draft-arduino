int shock = 10;
int value;

void setup()
{
  pinMode (LED_BUILTIN, OUTPUT); // define LED as output interface
  pinMode (shock, INPUT);
  Serial.begin(9600);
}

void loop()
{
  value = digitalRead (shock);
  if (value == HIGH)
  {
    digitalWrite (LED_BUILTIN, HIGH);
  }
  else
  {
    digitalWrite (LED_BUILTIN, LOW);
  }
  Serial.println(shock);
}
