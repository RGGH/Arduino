/*
              _                 _                                            _    
             | |               | |                                          | |   
 _ __ ___  __| | __ _ _ __   __| | __ _ _ __ ___  ___ _ __    ___ ___  _   _| | __
| '__/ _ \/ _` |/ _` | '_ \ / _` |/ _` | '__/ _ \/ _ \ '_ \  / __/ _ \| | | | |/ /
| | |  __/ (_| | (_| | | | | (_| | (_| | | |  __/  __/ | | || (_| (_) | |_| |   < 
|_|  \___|\__,_|\__,_|_| |_|\__,_|\__, |_|  \___|\___|_| |_(_)___\___(_)__,_|_|\_\
                                   __/ |                                          
                                  |___/                                           
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

// variables will change:
int ledState = LOW;     // the current state of LED
int lastButtonState;    // the previous state of button
int currentButtonState; // the current state of button
#define code1 3772793023

void setup() 
{
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(irSendPin, OUTPUT); 
}

void loop() {

if (irrecv.decode(&results)) {
  lcd.setCursor(0,0);
  lcd.clear();
  lcd.setCursor(0,1);
  //
  if (results.value == code1) {
    ledState = !ledState;
    lcd.print(ledState);
  }
  irrecv.resume(); // Receive the next value
  }
  delay(100);
}
