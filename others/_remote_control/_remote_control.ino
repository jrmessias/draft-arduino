#include <IRremote.h>

int receiver = 11;
float readValue;
int out01 = 7;
int out02 = 5;
int out03 = 2;

IRrecv irrecv(receiver);
decode_results results;

void setup()
{
  pinMode(out01, OUTPUT);
  pinMode(out02, OUTPUT);
  pinMode(out03, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop()
{
  if (irrecv.decode(&results))
  {
    Serial.print("Read value: ");
    Serial.println(results.value, HEX);
    readValue = (results.value);
    if (readValue == 0xFF6897) // Key 1
    {
      digitalWrite(out01, HIGH);  //Turn on out01
    }
    if (readValue == 0xFF9867) // Key 2
    {
      digitalWrite(out01, HIGH);  //Turn on out01
    }
    if (readValue == 0xFFB04F) // Key 3
    {
      digitalWrite(out01, HIGH);  //Turn on out01
    }
    if (readValue == 0xFF30CF) // Key 4
    {
      digitalWrite(out02, HIGH);  //Turn on out02
    }
    if (readValue == 0xFF18E7) // Key 5
    {
      digitalWrite(out02, HIGH);  //Turn on out02
    }
    if (readValue == 0xFF7A85) // Key 6
    {
      digitalWrite(out02, HIGH);  //Turn on out02
    }
    if (readValue == 0xFF10EF) // Key 7
    {
      digitalWrite(out03, HIGH);  //Turn on out03
    }
    if (readValue == 0xFF38C7) // Key 8
    {
      digitalWrite(out03, HIGH);  //Turn on out03
    }
    if (readValue == 0xFF5AA5) // Key 9
    {
      digitalWrite(out03, HIGH);  //Turn on out03
    }
    if (readValue == 0xFF4AB5) //Key 0 - Turn off all
    {
      digitalWrite(out01, LOW);
      digitalWrite(out02, LOW);
      digitalWrite(out03, LOW);
    }
    if (readValue == 0xFF02FD) //Key OK - Turn on all
    {
      digitalWrite(out01, HIGH);
      digitalWrite(out02, HIGH);
      digitalWrite(out03, HIGH);
    }
    if (readValue == 0xFF42BD) //Key * - Blink 1 to 3
    {
      digitalWrite(out01, LOW);
      digitalWrite(out02, LOW);
      digitalWrite(out03, LOW);
      digitalWrite(out01, HIGH);
      digitalWrite(out02, LOW);
      digitalWrite(out03, LOW);
      delay(500);
      digitalWrite(out01, LOW);
      digitalWrite(out02, HIGH);
      digitalWrite(out03, LOW);
      delay(500);
      digitalWrite(out01, LOW);
      digitalWrite(out02, LOW);
      digitalWrite(out03, HIGH);
      delay(500);
      digitalWrite(out01, LOW);
      digitalWrite(out02, LOW);
      digitalWrite(out03, LOW);
    }
    if (readValue == 0xFF52AD) //Key # - Blink 3 to 1
    {
      digitalWrite(out01, LOW);
      digitalWrite(out02, LOW);
      digitalWrite(out03, LOW);
      digitalWrite(out01, LOW);
      digitalWrite(out02, LOW);
      digitalWrite(out03, HIGH);
      delay(500);
      digitalWrite(out01, LOW);
      digitalWrite(out02, HIGH);
      digitalWrite(out03, LOW);
      delay(500);
      digitalWrite(out01, HIGH);
      digitalWrite(out02, LOW);
      digitalWrite(out03, LOW);
      delay(500);
      digitalWrite(out01, LOW);
      digitalWrite(out02, LOW);
      digitalWrite(out03, LOW);
    }
    // Left - 0xFF22DD
    // Top - 0x511DBB
    // Right - 0xFFC23D
    // Down - 0xFFA857 
    irrecv.resume(); // Read next value
  }
}
