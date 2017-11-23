#include <Ultrasonic.h>

#define trigger 4
#define echo 5

const int ledGreen = 2;
const int ledYellow = 7;
const int ledRed = 8;

Ultrasonic ultrasonic(trigger, echo);

void setup()
{
  pinMode(ledGreen, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Lendo dados do sensor...");
}

void loop()
{
  float cm, inches;
  cm = ultrasonic.distanceRead(CM);
  inches = ultrasonic.distanceRead(INC);

  Serial.print("Distancia em cm: ");
  Serial.print(cm);

  
  Serial.print(" - Distancia em polegadas: ");
  Serial.println(inches);

  digitalWrite(LED_BUILTIN, (cm > 10) ? HIGH : LOW);
  digitalWrite(ledGreen, (cm > 20) ? HIGH : LOW);
  digitalWrite(ledYellow, (cm > 30) ? HIGH : LOW);
  digitalWrite(ledRed, (cm > 40) ? HIGH : LOW);
  
  delay(1000);
}
