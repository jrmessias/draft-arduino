int axisX = A0; // x
int axisY = A1; // y
int button = 3; // key

void setup ()
{
  pinMode (axisX, INPUT);
  pinMode (axisY, INPUT);
  pinMode (button, INPUT_PULLUP);
  Serial.begin (9600);
}

void loop ()
{
  int x, y, z;
  x = analogRead (axisX);
  y = analogRead (axisY);
  z = digitalRead (button);
  Serial.print ("X: ");
  Serial.print (x, DEC);
  Serial.print (" Y: ");
  Serial.print (y, DEC);
  Serial.print (" Z: ");
  Serial.println (z, DEC);
  delay (500);
}
