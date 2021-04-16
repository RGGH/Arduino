/********************************/

// include the library code

#include <boarddefs.h>

#include <IRremote.h>

#include <IRremoteInt.h>

#include <ir_Lego_PF_BitStreamEncoder.h>

#include <Wire.h>

#include <LiquidCrystal_I2C.h>

/**********************************************************/

LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

#define irSendPin 3

IRsend irsend; 

decode_results results;



// Power ON/OFF - RAW Samsung Code

const unsigned int S_pwr[68]={4600,4350,700,1550,650,1550,650,1600,650,450,650,450,650,450,650,450,700,400,700,1550,650,1550,650,1600,650,450,650,450,650,450,700,450,650,450,650,450,650,1550,700,450,650,450,650,450,650,450,650,450,700,400,650,1600,650,450,650,1550,650,1600,650,1550,650,1550,700,1550,650,1550,650};





/*********************************************************/

void setup()

{

  lcd.init();  //initialize the lcd

  lcd.backlight();  //open the backlight

  Serial.begin(9600); //use serial Monitor

  irrecv.enableIRIn(); //start the receiver

  pinMode(irSendPin, OUTPUT);

 

}

/*********************************************************/

void loop()

{

  lcd.setCursor(0, 0); // set the cursor to column 0, line 0

  lcd.print("Samsung Remote =");  // Print a message to the LCD

  delay(1000);

  lcd.setCursor(0, 0); // set the cursor to column 0, line 0

  lcd.print("                ");  // Print a message to the LCD

  lcd.setCursor(0, 0); // set the cursor to column 0, line 0

  irsend.sendRaw(S_pwr,68,38);  //38 means 38Khz

  lcd.print("Samsung TV on");  // Print a message to the LCD

  delay(50000);

  

  

  if (irrecv.decode(&results))

    {

     

   

     Serial.println(results.value, HEX);

     translateIR();

     irrecv.resume(); // Receive the next value

    }

}

/************************************************************/

/*----( Declare User-written Functions )----*/

void translateIR() //Print Button Pressed to LCD



// SAMSUNG IR codes 

{

  switch(results.value)

  {

  case 0xE0E036C9:  

    Serial.println(" RED BUTTON            "); 

    lcd.setCursor(2, 1); // set the cursor to column 2, line 1

    lcd.print("RED");

    delay(1000);

    lcd.setCursor(2, 1); // set the cursor to column 2, line 1

    lcd.print("      ");

    break;



  case 0xE0E028D7:  

    Serial.println(" GREEN BUTTON            "); 

    lcd.setCursor(2, 1); // set the cursor to column 2, line 1

    lcd.print("GREEN");

    delay(1000);

    lcd.setCursor(2, 1); // set the cursor to column 2, line 1

    lcd.print("      ");

    break;



  case 0xE0E0A857:  

    Serial.println(" YELLOW BUTTON            "); 

    lcd.setCursor(2, 1); // set the cursor to column 2, line 1

    lcd.print("YELLOW");

    delay(1000);

    lcd.setCursor(2, 1); // set the cursor to column 2, line 1

    lcd.print("      ");

    break;



  case 0xE0E06897:  

    Serial.println(" BLUE BUTTON            "); 

    lcd.setCursor(2, 1); // set the cursor to column 2, line 1

    lcd.print("BLUE");

    delay(1000);

    lcd.setCursor(2, 1); // set the cursor to column 2, line 1

    lcd.print("      ");

    break;



  case 0xFF02FD:  

    Serial.println(" SPARE           "); 

    break;



  default: 

    Serial.println(" other button   ");

  }

  delay(500);

} //END translateIR
