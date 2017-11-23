char Rdata;

void setup()
{
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  while (Serial.available())
  {
    Rdata = Serial.read();
    Serial.println(Rdata);
  }

  if (Rdata == 'A' | Rdata == 'a')
  {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
  }
  else if (Rdata == 'B' | Rdata == 'b')
  {
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
  }
  else  if (Rdata == 'C' | Rdata == 'c')
  {
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
  }
  else  if (Rdata == 'D' | Rdata == 'd')
  {
    digitalWrite(LED_BUILTIN, LOW);
    delay(250);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(250);
  }
  else  if (Rdata == 'E' | Rdata == 'e')
  {
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
  }
  else
  {
    digitalWrite(LED_BUILTIN, LOW);
  }

}

