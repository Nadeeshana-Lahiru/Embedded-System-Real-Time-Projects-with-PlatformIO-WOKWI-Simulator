#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

#define PIN_TRIG 3
#define PIN_ECHO 2
#define RED_LED 13
#define YELLOW_LED 12
#define BUZZER 11

void setup() {

  lcd.init();
  lcd.backlight();
  lcd.clear();

  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);

  pinMode(RED_LED,OUTPUT);
  pinMode(YELLOW_LED,OUTPUT);
  pinMode(BUZZER,OUTPUT);

}

void loop() {

  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);

  int duration = pulseIn(PIN_ECHO, HIGH);
  int cm = duration / 58;

  if (10<cm && cm<=20){
    digitalWrite(YELLOW_LED,HIGH);
    lcd.setCursor(0,0);
    lcd.clear();
    lcd.print("Object Nearby");
  }
  if (cm<=10){
    digitalWrite(RED_LED,HIGH);
    tone(BUZZER,1300);
    digitalWrite(YELLOW_LED,LOW);
    lcd.setCursor(0,0);
    lcd.clear();
    lcd.print("Object Very Close");
  }
  if (cm>20){
    digitalWrite(RED_LED,LOW);
    digitalWrite(YELLOW_LED,LOW);
    noTone(BUZZER);
    lcd.setCursor(0,0);
    lcd.clear();
    lcd.print("Safe Distance");
  }

  lcd.setCursor(0,1);
  lcd.print("Distance : ");
  lcd.setCursor(11,1);
  lcd.print(cm);
  lcd.setCursor(14,1);
  lcd.print("Cm");

  delay(1000);
}
