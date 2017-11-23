const int sensor = 0;
float temperature = 0;
int ADCread = 0;
const int buzzer = 12;
const int bargraph[] = {
  2, 3, 4, 5, 6, 7, 8, 9, 10, 11
};

void setup() {
  Serial.begin(9600);
  analogReference(INTERNAL);
  pinMode(buzzer, OUTPUT);
  for (int x = 0; x < 10; x++) {
    pinMode(bargraph[x], OUTPUT);
  }
}

void loop() {
  ADCread = analogRead(sensor);
  temperature = ADCread * 0.1075268817;

  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println(" *C");

  if (temperature > 23.10) {
    digitalWrite(bargraph[0], HIGH);
  }
  else {
    digitalWrite(bargraph[0], LOW);
  }
  if (temperature > 23.20) {
    digitalWrite(bargraph[1], HIGH);
  }
  else {
    digitalWrite(bargraph[1], LOW);
  }
  if (temperature > 23.30) {
    digitalWrite(bargraph[2], HIGH);
  }
  else {
    digitalWrite(bargraph[2], LOW);
  }
  if (temperature > 23.40) {
    digitalWrite(bargraph[3], HIGH);
  }
  else {
    digitalWrite(bargraph[3], LOW);
  }
  if (temperature > 23.50) {
    digitalWrite(bargraph[4], HIGH);
  }
  else {
    digitalWrite(bargraph[4], LOW);
  }
  if (temperature > 23.60) {
    digitalWrite(bargraph[5], HIGH);
  }
  else {
    digitalWrite(bargraph[5], LOW);
  }
  if (temperature > 23.70) {
    digitalWrite(bargraph[6], HIGH);
  }
  else {
    digitalWrite(bargraph[6], LOW);
  }
  if (temperature > 23.80) {
    digitalWrite(bargraph[7], HIGH);
  }
  else {
    digitalWrite(bargraph[7], LOW);
  }
  if (temperature > 23.90) {
    digitalWrite(bargraph[8], HIGH);
  }
  else {
    digitalWrite(bargraph[8], LOW);
  }
  if (temperature > 24.00) {
    digitalWrite(bargraph[9], HIGH);
    digitalWrite(buzzer, HIGH);
  }
  else {
    digitalWrite(bargraph[9], LOW);
    digitalWrite(buzzer, LOW);
  }
  
  delay(1000);
}
