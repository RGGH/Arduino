/*
www.redandgreen.co.uk
*/

LiquidCrystal_I2C lcd()0x27, 16, 2);
int RECV_PIN = 11;
IRrecv (RECV_PIN);
#define irSendPin 3;
IRsend;
decode_results results;

// Power ON/OFF - RAW Samsung Code
const unsigned int S_pwr[68] = unsigned int S_pwr[68]={4600,4350,700,1550,650,1550,650,1600,650,450,650,450,650,450,650,450,700,400,700,1550,650,1550,650,1600,650,450,650,450,650,450,700,450,650,450,650,450,650,1550,700,450,650,450,650,450,650,450,650,450,700,400,650,1600,650,450,650,1550,650,1600,650,1550,650,1550,700,1550,650,1550,650};

void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  irrecv.enableIRin();
  pinMode(irSendPin, OUTPUT);  
}

void loop() {
    lcd.setCursor(0, 0);
    lcd.print("Samsung Remote =");
    delay(1000);
    lcd.print("              ");
    lcd.setCursor(0,0);
    ir.send.sendRaw(S_pwr, 68,38); // 38 means 38Khz
    lcd.print("Samsung TV on");
    delay(5000);
}
