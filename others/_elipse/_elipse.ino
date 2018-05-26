#include <SimpleModbusSlave.h>

/*
  # Inputs (Const)
*/
const int inputLDR = A0;
const int inputPot = A1;

/*
  # Outputs (Const)
*/
const int outputLaser = 2;
const int outputLedR = 3;
const int outputLedG = 5;
const int outputLedB = 6;

/*
   Variables
*/
int inputPotValue, potScale, red, green, blue;

/*
   Send to Modbus
*/
enum
{
  VAL_LAZER,
  VAL_RED,
  VAL_GREEN,
  VAL_BLUE,
  VAL_POT,
  LED_BUILT_IN,
  HOLDING_REGS_SIZE
};

unsigned int holdingRegs[HOLDING_REGS_SIZE];

/*
   SETUP
*/
void setup() {
  /*
     Seed Random
  */
  randomSeed(analogRead(0));

  /*
    Serial
  */
  //Serial.begin (9600);

  /*
     Modbus
  */
  modbus_configure(&Serial, 9600, SERIAL_8N1, 1, LED_BUILTIN, HOLDING_REGS_SIZE, holdingRegs);
  modbus_update_comms(9600, SERIAL_8N1, 1);

  /*
     Outputs
  */
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(outputLaser, OUTPUT);
  pinMode(outputLedR, OUTPUT);
  pinMode(outputLedG, OUTPUT);
  pinMode(outputLedB, OUTPUT);

  /*
     Inputs
  */
  pinMode(inputPot, INPUT);
}

/*
   LOOP
*/
void loop() {
  /*
     Laser
  */
  digitalWrite(outputLaser, (random(0, 254) > 126) ? LOW : HIGH);
  /* Modbus */
  modbus_update();
  delay(100);
  
  /*
    Potenciometro
  */
  inputPotValue = analogRead(inputPot);
  //Serial.print("Potenciometro: ");
  //Serial.println(inputPotValue);

  /*
     RGB Led
  */
  potScale = map(inputPotValue, 0, 1023, 0, 254);

  analogWrite(outputLedR, potScale - random(0, 254));
  analogWrite(outputLedG, potScale - random(0, 254));
  analogWrite(outputLedB, potScale - random(0, 254));
  delay(100);

  /*
     LED13
  */
  digitalWrite(LED_BUILTIN, (random(0, 254) > 126) ? LOW : HIGH);
  /* Modbus */
  modbus_update();
  delay(100);

  /**/
  holdingRegs[VAL_LAZER] = digitalRead(outputLaser);
  holdingRegs[VAL_RED] = analogRead(outputLedR);
  holdingRegs[VAL_GREEN] = analogRead(outputLedG);
  holdingRegs[VAL_BLUE] = analogRead(outputLedB);
  holdingRegs[VAL_POT] = inputPotValue;
  holdingRegs[LED_BUILT_IN] = digitalRead(LED_BUILTIN);

  /* Modbus */
  modbus_update();
}
