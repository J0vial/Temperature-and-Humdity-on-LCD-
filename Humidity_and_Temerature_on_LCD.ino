#include <SimpleDHT.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// for DHT11, 
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 2
int pinDHT11 = 2;
SimpleDHT11 dht11(pinDHT11);
LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  Serial.begin(9600);
  
}

void loop() {
  
  
  // read without samples.
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    delay(1000);
    return;
  }

  lcd.init();                      // initialize the lcd 
  lcd.init();
  lcd.backlight();
  lcd.setCursor(1,1);
  lcd.print("tempature  ");
  lcd.print((int)temperature); 
  lcd.print(" *C, "); 
  lcd.setCursor(1,0);
  lcd.print("humidity  ");
  lcd.print((int)humidity); 
  lcd.println(" H ");
  // DHT11 sampling rate is 1HZ.
  delay(1000);
}
