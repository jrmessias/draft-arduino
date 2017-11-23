//Model: MMA845X GY-45

#include <Wire.h>
#include <SFE_MMA8452Q.h>

//Initialize MMA8452 instance named accelerometer
//with address I2C 0x1C (pin SA0 at LOW/Off)
MMA8452Q accelerometer(0x1C);
int showTest = 1;

void setup()
{
  Serial.begin(9600);
  Serial.println("MMA845X Communication test");

  //Initialize accelerometer with default values +/-2g and out with 800 Hz
  accelerometer.init();

  //Use the line below to initialize the accelerometer with (default +/-2g)
  //+/-2g (SCALE_2G), 4g (SCALE_4G), or 8g (SCALE_8G)
  //accelerometer.init(SCALE_4G);

  //Use the line below to also determine the output frequency of the
  //accelerometer (default 800 Hz), use the second parameter like
  //ODR_800 (800 Hz), ODR_400 (400 Hz), ODR_200 (200 Hz),
  //ODR_100 (100 Hz), ODR_50 (50 Hz), ODR_12 (12.5 Hz),
  //ODR_6 (6.25 Hz) or ODR_1 (1.56 Hz)
  //accelerometer.init(SCALE_8G, ODR_6);
}

void loop()
{
  //The line below awaits the sending of new data by the accelerometer
  if (accelerometer.available())
  {
    // Show Communication Test
    if(showTest == 1){
      if (accelerometer.available()) {
        Serial.println("MMA845X Ok");
        showTest = 0;
      } else {
        Serial.println("MMA845X Error");
      }
    }
    
    //Read data from sensor
    accelerometer.read();
    //accelerometer.read() update two group of variables:
    //* int x, y and z store 12 bits values read from accelerometer
    //* float cx, cy and cz store 12 bits calc of acceleration
    //This variables are ate "g" units

    //Show read coordenates from sensor
    showCalculatedAccels();

    //Show digital values
    //showAccels();

    //Show orientation (portrait/landscape/flat)
    showOrientation();

    Serial.println();

    delay(1000);
  }

}

void showAccels()
{
  Serial.print(accelerometer.x, 3);
  Serial.print("\t");
  Serial.print(accelerometer.y, 3);
  Serial.print("\t");
  Serial.print(accelerometer.z, 3);
  Serial.print("\t");
}

void showCalculatedAccels()
{
  Serial.print(accelerometer.cx, 3);
  Serial.print("\t");
  Serial.print(accelerometer.cy, 3);
  Serial.print("\t");
  Serial.print(accelerometer.cz, 3);
  Serial.print("\t");
}

void showOrientation()
{
  //accelerometer.readPL() retorna um byte contendo informacoes sobre
  //a orientacao do sensor (retrato/paisagem)
  //PORTRAIT_U (Retrato Up/Para cima), PORTRAIT_D (Retrato Down/Para Baixo),
  //LANDSCAPE_R (Paisagem right/direita), LANDSCAPE_L (Paisagem left/esquerda)
  //e LOCKOUT (bloqueio)
  byte pl = accelerometer.readPL();
  switch (pl)
  {
    case PORTRAIT_U:
      Serial.print("Portrait Up");
      break;
    case PORTRAIT_D:
      Serial.print("Portrait Down");
      break;
    case LANDSCAPE_R:
      Serial.print("Landscape Right");
      break;
    case LANDSCAPE_L:
      Serial.print("Landscape Left");
      break;
    case LOCKOUT:
      Serial.print("Flat");
      break;
  }
}
