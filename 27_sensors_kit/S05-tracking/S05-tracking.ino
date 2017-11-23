#define PORT 2
int value;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  value = digitalRead(PORT);
  Serial.println(value);
  delay(500);
}
