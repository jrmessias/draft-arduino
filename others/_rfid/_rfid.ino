//Model: RFID-RC522

#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>

#define SS_PIN 10
#define RST_PIN 9
#define BUZ_PIN 3
#define LED_PIN 2
MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance.
int access = 1;

void setup()
{
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init(); // Initialize MFRC522
  pinMode(BUZ_PIN, OUTPUT); // Buzzer
  pinMode(LED_PIN, OUTPUT); // Led
  initialMessage();
}

void loop()
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }

  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial())
  {
    return;
  }

  digitalWrite(LED_PIN, LOW);

  showUUID();

  showMessage();

  delay(2000);
  access = (access == 1) ? 0 : 1;

  initialMessage();
}

// Initial Message
void initialMessage()
{
  Serial.println();
  Serial.println("Show your ID...");
  digitalWrite(LED_PIN, HIGH);
}

// Message
void showMessage() {
  Serial.println();
  Serial.println();
  Serial.println("Message: ");

  if (access == 1)
  {
    Serial.println("OK: Unlocked!");
    tone(BUZ_PIN, 349, 200); //DO
  }
  else
  {
    Serial.println("Error: Locked!");
    tone(BUZ_PIN, 392, 300);
  }
}

// UUID
void showUUID() {
  
  //Show UID at serial
  Serial.print("UID da tag :");

  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
  }
}
