#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

LiquidCrystal_I2C lcd(0x27,16,2);

#define PIN_TRIG 3
#define PIN_ECHO 2
#define RED_LED 12
#define GREEN_LED 11
#define BUZZER 10
#define DHTPIN 4

#define DHTTYPE DHT22 

DHT dht(DHTPIN, DHTTYPE);

void setup() {

  lcd.init();
  lcd.backlight();
  lcd.clear();

  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);

  pinMode(RED_LED,OUTPUT);
  pinMode(GREEN_LED,OUTPUT);
  pinMode(BUZZER,OUTPUT);

  dht.begin();

}

void loop() {

  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);

  int duration = pulseIn(PIN_ECHO, HIGH);
  int cm = duration / 58;

  float temp = dht.readTemperature();

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temp, 0);
  lcd.print("C ");

  if (temp > 35) {
    tone(BUZZER, 1300);
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    lcd.print("HIGH!");
  } else {
    noTone(BUZZER);
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    lcd.print("Normal");
  }

  lcd.setCursor(0, 1);
  lcd.print("Dist:");
  lcd.print(cm);
  lcd.print("cm ");

  if (cm <= 10) {
    tone(BUZZER, 1300);
    lcd.print("Obj!");
  } else {
    noTone(BUZZER);
    lcd.print("No Obj");
  }

  delay(1000);
}
