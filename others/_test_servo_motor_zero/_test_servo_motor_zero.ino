#include <Servo.h>

#define SERVO 6 // Digital Port 6 (PWM)

Servo _servo; // Variable of Servo Motor
int _position = 0; // Position

void setup ()
{
  _s.attach(SERVO);
  Serial.begin(9600);
  _s.write(_position);
}

void loop()
{
  _s.write(_position);
  delay(1000);
}
