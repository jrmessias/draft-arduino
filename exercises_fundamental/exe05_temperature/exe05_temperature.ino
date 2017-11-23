const int sensor = 0;
float temperature = 0;
int ADCread = 0;

void setup() {
  Serial.begin(9600);
  analogReference(INTERNAL);
}

void loop() {
  ADCread = analogRead(sensor);
  temperature = ADCread * 0.1075268817;
  
  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println(" *C");
  
  delay(1000);
}
