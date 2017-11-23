int led01 = 2;
int led02 = 3;
int led03 = 4;
int led04 = 5;
int led05 = 6;
int led06 = 7;
int led07 = 8;
int led08 = 9;
int led09 = 10;
int led10 = 11;
int _delay = 500;


void setup()
{
  pinMode(led01, OUTPUT);
  pinMode(led02, OUTPUT);
  pinMode(led03, OUTPUT);
  pinMode(led04, OUTPUT);
  pinMode(led05, OUTPUT);
  pinMode(led06, OUTPUT);
  pinMode(led07, OUTPUT);
  pinMode(led08, OUTPUT);
  pinMode(led09, OUTPUT);
  pinMode(led10, OUTPUT);
}

void loop()
{
  turnOff();
  digitalWrite(led01, HIGH);
  delay(_delay);
  turnOff();
  digitalWrite(led02, HIGH);
  delay(_delay);
  turnOff();
  digitalWrite(led03, HIGH);
  delay(_delay);
  turnOff();
  digitalWrite(led04, HIGH);
  delay(_delay);
  turnOff();
  digitalWrite(led05, HIGH);
  delay(_delay);
  turnOff();
  digitalWrite(led06, HIGH);
  delay(_delay);
  turnOff();
  digitalWrite(led07, HIGH);
  delay(_delay);
  turnOff();
  digitalWrite(led08, HIGH);
  delay(_delay);
  turnOff();
  digitalWrite(led09, HIGH);
  delay(_delay);
  turnOff();
  digitalWrite(led10, HIGH);
  delay(_delay);
}

void turnOff(){
  digitalWrite(led01, LOW);
  digitalWrite(led02, LOW);
  digitalWrite(led03, LOW);
  digitalWrite(led04, LOW);
  digitalWrite(led05, LOW);
  digitalWrite(led06, LOW);
  digitalWrite(led07, LOW);
  digitalWrite(led08, LOW);
  digitalWrite(led09, LOW);
  digitalWrite(led10, LOW);
}
