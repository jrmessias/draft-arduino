int pinopir = 7; //Pino ligado ao sensor PIR
int acionamento;

void setup()
{
  pinMode(pinopir, INPUT); //Define pino sensor como entrada
  Serial.begin(9600);
}

void loop()
{
  acionamento = digitalRead(pinopir); //Le o valor do sensor PIR

  if (acionamento == LOW) //Sem movimento, mantem rele desligado
  {
    Serial.println("Parado");
  }
  else //Caso seja detectado um movimento, aciona o rele
  {
    Serial.println("Movimento !!!");
  }
}
