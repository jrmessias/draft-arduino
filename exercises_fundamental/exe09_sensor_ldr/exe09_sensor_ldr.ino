const int ldr = 0;
const int led = 6;
int valueRead = 0;
int pwm = 0;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  valueRead = analogRead(ldr);
  if (valueRead < 155){
    analogWrite(led, pwm);
    pwm++;
    delay(50);
  }
  else{
    digitalWrite(led, LOW);
    pwm = 0;
  }
  if(pwm > 255){
    pwm=255;
  }
  Serial.print("Valor lido pelo LDR = ");
  Serial.println(valueRead);
  Serial.print("PWM = ");
  Serial.println(pwm);
}
