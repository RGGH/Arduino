/*
www.redandgreen.co.uk
*/
#include <IRremote.h>
#include <LiquidCrystal_I2C.h>

/*************************************************
 */
LiquidCrystal_I2C lcd(0x27, 16, 2);
int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
#define irSendPin 3
IRsend irsend;
decode_results results;

// Power ON/OFF - RAW Samsung Code
const unsigned int S_pwr[68]={4600,4350,700,1550,650,1550,650,1600,650,450,650,450,650,450,650,450,700,400,700,1550,650,1550,650,1600,650,450,650,450,650,450,700,450,650,450,650,450,650,1550,700,450,650,450,650,450,650,450,650,450,700,400,650,1600,650,450,650,1550,650,1600,650,1550,650,1550,700,1550,650,1550,650};

void setup() 
{
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(irSendPin, OUTPUT);  
}

void loop() {

    lcd.setCursor(0, 0);
    lcd.print("......");

    if (irrecv.decode(&results))  {
      irsend.sendRaw(S_pwr,68,38);
      lcd.setCursor(0, 0);
      lcd.print("SUBSCRIBE yeah?");
      delay(10000);
    
    }
    
}
