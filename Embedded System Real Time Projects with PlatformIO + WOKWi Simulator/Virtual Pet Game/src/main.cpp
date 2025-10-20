#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int startBtntPin = 13;
int feedbtnPin = 12;
int playbtnPin = 11;

int buzzerPin = 10;

int happyLEDGREEN = 9;
int okayLEDBLUE = 8;
int sadLEDRED = 7;

double healthState = 0.00;
double happinessState = 0.00;

void setup() {

  lcd.init();
  lcd.backlight();
  lcd.clear();

  pinMode(startBtntPin, INPUT_PULLUP);
  pinMode(feedbtnPin, INPUT_PULLUP);
  pinMode(playbtnPin, INPUT_PULLUP);

  pinMode(buzzerPin, OUTPUT);

  pinMode(happyLEDGREEN, OUTPUT);
  pinMode(okayLEDBLUE, OUTPUT);
  pinMode(sadLEDRED, OUTPUT);

  lcd.setCursor(0,0);
  lcd.print("Virtual Pet Game");

  lcd.setCursor(0,1);
  lcd.print("Press Start");

}

void loop() {

  int startBtnState = digitalRead(startBtntPin);
  int feedBtnState = digitalRead(feedbtnPin);
  int playBtnState = digitalRead(playbtnPin);

  if(startBtnState == LOW){
    lcd.clear();
    healthState = 0.70;
    digitalWrite(okayLEDBLUE, HIGH);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Pet is OK!");
  }

  if(healthState > 0){
    healthState = healthState - 0.01;

    if(healthState == 0){
      healthState = 0;
    }

    if(feedBtnState == LOW){
      healthState = healthState + 0.20;
    }

    if(playBtnState == LOW){
      happinessState = happinessState + 0.10;
      healthState = healthState - 0.05;
    }

    if(healthState>0.70 && happinessState>0.50){
      digitalWrite(happyLEDGREEN, HIGH);
      digitalWrite(okayLEDBLUE, LOW);
      digitalWrite(sadLEDRED, LOW);
      noTone(buzzerPin);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Pet is Happy!");
    }

    if(healthState<0.70 && healthState>0.30){
      digitalWrite(okayLEDBLUE, HIGH);
      digitalWrite(happyLEDGREEN, LOW);
      digitalWrite(sadLEDRED, LOW);
      noTone(buzzerPin);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Pet is Happy!");
    }
    
    if(healthState<=0.30){
      digitalWrite(sadLEDRED, HIGH);
      digitalWrite(happyLEDGREEN, LOW);
      digitalWrite(okayLEDBLUE, LOW);
      tone(buzzerPin,1400);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Pet is sad!");
      lcd.setCursor(0,1);
      lcd.print("Feed me");
    }

    lcd.setCursor(0,1);
    lcd.print("H:");
    lcd.print(int(healthState*100));
    lcd.print("% Ha:");
    lcd.print(int(happinessState*100));
    lcd.print("%");
  }

  delay(2000);
}
