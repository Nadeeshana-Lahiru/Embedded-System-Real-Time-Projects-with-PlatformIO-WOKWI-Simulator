#include <Arduino.h>
#include "DHT.h"
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define DHTPIN 13   
#define DHTTYPE DHT22   

#define LED_RED 12
#define LED_GREEN 11
#define BUZZER 10

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  dht.begin();
  lcd.init();
  lcd.backlight();
  lcd.clear();

  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop() {

  delay(2000);

  float t = dht.readTemperature();

  lcd.clear();
  lcd.setCursor(0, 0); 
  lcd.print(F("Temp: "));
  lcd.setCursor(7, 0); 
  lcd.print(t);
  lcd.setCursor(12, 0); 
  lcd.print(F(" C "));

  if(t>=45){
    tone(BUZZER,1400);
    digitalWrite(LED_RED,HIGH);
    digitalWrite(LED_GREEN,LOW);
    lcd.setCursor(0, 1); 
    lcd.print("Fire Alert!");
  }
  else{
    noTone(BUZZER);
    digitalWrite(LED_RED,LOW);
    digitalWrite(LED_GREEN,HIGH);
    lcd.setCursor(0, 1); 
    lcd.print("Normal Temp");
  }
}