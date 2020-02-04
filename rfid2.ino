#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
 
MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class
MFRC522::MIFARE_Key key; 

// Init array that will store new NUID 
byte nuidPICC[4];
const byte a[4] = {0x09, 0x30,0xA1,0x59};

void setup() { 
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();

  for (byte i = 0; i < 6; i++) {
    key.keyByte[i] = 0xFF;
  }

  Serial.println(F("Reset OK."));
}
void printDec(byte*buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10? "0":"");
    Serial.print(buffer[i],DEC);
  }
}
void loop() {
  if ( ! rfid.PICC_IsNewCardPresent())
    return;

  // Verify if the NUID has been readed
  if ( ! rfid.PICC_ReadCardSerial())
    return;
  
  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);

 for (byte i = 0; i < 4; i++) {
      Serial.print(rfid.uid.uidByte[i],HEX);
      Serial.print(" ");
 }
 Serial.println();

  int i;
 for(i=0;i<4;i++)
 {
  if(rfid.uid.uidByte[i]!=a[i])break;
 }
 if(i==4)
 {
  Serial.println(F("It is plastic"));
 }
//  
//  if (rfid.uid.uidByte[10] = 48){
//    Serial.println(F("It is plastic"));
//  }
//
//  if (rfid.uid.uidByte[10] = 165){
//    Serial.println(F("It is glass"));
//    }
  }
