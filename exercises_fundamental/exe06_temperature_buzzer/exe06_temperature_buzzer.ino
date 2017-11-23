const int sensor = 0;
float temperature = 0;
int ADCread = 0;
int tempAverage = 23;
const int buzzer = 12;

void setup() {
  Serial.begin(9600);
  analogReference(INTERNAL);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  ADCread = analogRead(sensor);
  temperature = ADCread * 0.1075268817;
  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println("*C");

  if (temperature > tempAverage) {
    delay(1000);
    if (temperature > tempAverage) {
      tone(buzzer, 2000);
    }
  }
  else {
    noTone(buzzer);
  }
  delay(1000);
}
