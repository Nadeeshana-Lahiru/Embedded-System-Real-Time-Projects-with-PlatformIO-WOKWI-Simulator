#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int RED_LED_PIN = 13;
int BUZZER_PIN = 12;
int PIR_PIN = 2;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();

  pinMode(RED_LED_PIN,OUTPUT);
  pinMode(BUZZER_PIN,OUTPUT);
  pinMode(PIR_PIN,INPUT);
}

void loop() {
  int pir_value = digitalRead(PIR_PIN);

  if (pir_value == HIGH){
    digitalWrite(RED_LED_PIN,HIGH);
    tone(BUZZER_PIN,1200);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Motion Detected");
  }
  else {
    digitalWrite(RED_LED_PIN,LOW);
    noTone(BUZZER_PIN);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Area Secure");
  }
  delay(1000);
}
