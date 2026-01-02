#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Servos
Servo inServo;
Servo outServo;

// Led 
int ledPin = 12;

// Ir Pin
int irPin = A1;

// Ultrasonic pins
int trigIn = 5;
int echoIn = 4;
int trigOut = 3;
int echoOut = 2;

// Servo pins
int inServoPin = 9;
int outServoPin = 6;

// Parking slots
const int TOTAL_SLOTS = 4;
int Slot = TOTAL_SLOTS;

// Distance range (5-10 cm only)
const int MIN_DISTANCE = 5;
const int MAX_DISTANCE = 10;

// Gate timing
unsigned long gateOpenTime = 0;
const unsigned long GATE_OPEN_DURATION = 3000;
bool inGateOpen = false;
bool outGateOpen = false;

// IR Sensor timing
unsigned long ledOnTime = 0;
const unsigned long LED_ON_DURATION = 2000; // 2 seconds
bool ledActive = false;
bool irPreviouslyDetected = false;  // To track if IR was already detecting

// Car exit cooldown to prevent false triggers
unsigned long lastExitTime = 0;
const unsigned long EXIT_COOLDOWN = 5000; // 5 seconds cooldown after exit

// Function to measure distance
long getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000);
  if (duration == 0) return 999;

  long distance = duration * 0.034 / 2;
  if (distance < 2 || distance > 400) return 999;

  return distance;
}

// Function to check if distance is in valid range (5-10 cm)
bool isInDistanceRange(long distance) {
  return (distance >= MIN_DISTANCE && distance <= MAX_DISTANCE);
}

void setup() {
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();

  pinMode(trigIn, OUTPUT);
  pinMode(echoIn, INPUT);
  pinMode(trigOut, OUTPUT);
  pinMode(echoOut, INPUT);
  
  // IR Sensor and LED setup
  pinMode(irPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW); // Ensure LED is off initially

  inServo.attach(inServoPin);
  outServo.attach(outServoPin);

  inServo.write(90);
  outServo.write(90);

  lcd.setCursor(0, 0);
  lcd.print("  ARDUINO CAR  ");
  lcd.setCursor(0, 1);
  lcd.print(" PARKING SYS ");
  delay(2000);
  lcd.clear();
}

void loop() {
  unsigned long currentTime = millis();

  long distIn = getDistance(trigIn, echoIn);
  long distOut = getDistance(trigOut, echoOut);
  
  // -------- IR SENSOR DETECTION --------
  int irValue = digitalRead(irPin);
  
  // When IR sensor detects something (edge detection - only trigger on new detection)
  // Note: Adjust logic based on your IR sensor type
  if (irValue == LOW) {
    if (!irPreviouslyDetected && !ledActive) {
      // New detection - turn on LED
      ledActive = true;
      digitalWrite(ledPin, HIGH);  // Turn LED ON
      ledOnTime = currentTime;
    }
    irPreviouslyDetected = true;
  } else {
    irPreviouslyDetected = false;
  }

  // -------- LED TIMER CONTROL --------
  if (ledActive && (currentTime - ledOnTime >= LED_ON_DURATION)) {
    ledActive = false;
    digitalWrite(ledPin, LOW);   // Turn LED OFF
  }

  // -------- IN GATE --------
  // FIXED: Only detect if distance is between 5-10 cm
  if (isInDistanceRange(distIn) && !inGateOpen && Slot > 0 && !outGateOpen) {
    inGateOpen = true;
    inServo.write(0);
    Slot--;
    gateOpenTime = currentTime;

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("  Car Entering ");
    lcd.setCursor(0, 1);
    lcd.print("Please proceed");
  }

  // -------- OUT GATE --------
  // FIXED: Only detect if distance is between 5-10 cm
  if (isInDistanceRange(distOut) && !outGateOpen && !inGateOpen && 
      Slot < TOTAL_SLOTS && (currentTime - lastExitTime >= EXIT_COOLDOWN)) {
    outGateOpen = true;
    outServo.write(0);
    Slot++;
    gateOpenTime = currentTime;
    lastExitTime = currentTime; // Record exit time for cooldown

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("  Car Exiting  ");
    lcd.setCursor(0, 1);
    lcd.print("Have a nice day");
  }

  // -------- PARKING FULL --------
  // FIXED: Only detect if distance is between 5-10 cm
  if (isInDistanceRange(distIn) && Slot == 0 && !inGateOpen) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("   SORRY :(   ");
    lcd.setCursor(0, 1);
    lcd.print(" Parking Full ");
    delay(1500);
    lcd.clear();
  }

  // -------- PARKING EMPTY MESSAGE --------
  // FIXED: Only detect if distance is between 5-10 cm
  if (isInDistanceRange(distOut) && Slot == TOTAL_SLOTS && !outGateOpen && !inGateOpen) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("   Parking is   ");
    lcd.setCursor(0, 1);
    lcd.print("    EMPTY      ");
    delay(1500);
    lcd.clear();
  }

  // -------- CLOSE GATES --------
  if ((inGateOpen || outGateOpen) &&
      (currentTime - gateOpenTime >= GATE_OPEN_DURATION)) {

    inServo.write(90);
    outServo.write(90);

    inGateOpen = false;
    outGateOpen = false;

    lcd.clear();
  }

  // -------- IDLE DISPLAY --------
  if (!inGateOpen && !outGateOpen) {
    lcd.setCursor(0, 0);
    lcd.print("   WELCOME!   ");
    lcd.setCursor(0, 1);
    lcd.print("Slots Left: ");
    lcd.print(Slot);
    lcd.print("/");
    lcd.print(TOTAL_SLOTS);
    lcd.print(" ");
  }

  delay(100);
}