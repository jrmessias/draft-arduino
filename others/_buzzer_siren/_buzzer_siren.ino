#define TIME 10
#define BUZ_PIN 3

int frequency = 0;

void setup()
{
  pinMode(BUZ_PIN ,OUTPUT); // buzzer
}

void loop()
{
  for (frequency = 150; frequency < 1800; frequency += 1) 
  {
    tone(BUZ_PIN, frequency, TIME); 
    delay(1);
  }
  for (frequency = 1800; frequency > 150; frequency -= 1) 
  {
    tone(BUZ_PIN, frequency, TIME); 
    delay(1);
  }
}
