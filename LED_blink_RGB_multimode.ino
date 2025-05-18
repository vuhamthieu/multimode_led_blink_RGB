///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// LIBRARIES
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <Arduino.h>


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// CONSTANTS
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define RED_LED_PIN 9
#define GREEN_LED_PIN 10
#define BLUE_LED_PIN 11
const int buttonPin = 2;


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// VARIABLES
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int buttonState = 0;   // Variable for reading the pushbutton status
int currentMode = -1;  // Variable for LED mode
bool lastButtonState = HIGH;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// FUNCTION PROTOTYPES
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void incMode() {
  currentMode++;
}


void turnOffLED() {
  digitalWrite(RED_LED_PIN, LOW);
  digitalWrite(GREEN_LED_PIN, LOW);
  digitalWrite(BLUE_LED_PIN, LOW);
}



void constantBlink() {
  static unsigned long lastBlinkTime = 0;
  static int blinkState = 0;

  unsigned long currentMillis = millis();
  if (currentMillis - lastBlinkTime >= 400) {
    lastBlinkTime = currentMillis;

    turnOffLED();  // turn off all LED before turn on another

    switch (blinkState) {
      case 0: digitalWrite(RED_LED_PIN, HIGH); break;
      case 1: digitalWrite(GREEN_LED_PIN, HIGH); break;
      case 2: digitalWrite(BLUE_LED_PIN, HIGH); break;
    }

    // Choose the next state
    blinkState = (blinkState + 1) % 3;
  }
}


void fadeBlink() {
  static int brightness = 0;
  static int fadeAmount = 5;
  static int fadeState = 0;
  static unsigned long previousMillis = 0;
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= 40) {
    previousMillis = currentMillis;


    switch (fadeState) {
      case 0: analogWrite(RED_LED_PIN, brightness); break;
      case 1: analogWrite(GREEN_LED_PIN, brightness); break;
      case 2: analogWrite(BLUE_LED_PIN, brightness); break;
    }

    // Changing brightness
    brightness += fadeAmount;

    if (brightness <= 0 || brightness >= 255) {
      fadeAmount = -fadeAmount;
      if (brightness <= 0) {
        fadeState = (fadeState + 1) % 3;
        turnOffLED();
      }
    }
  }
}




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SETUP
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void setup() {
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);

  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(12500);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// LOOP
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void loop() {
  buttonState = digitalRead(buttonPin);  // Read button is pressed, Ìf it is, set LOW

  if (lastButtonState == HIGH && buttonState == LOW) {
    incMode();
    if (currentMode > 5) currentMode = 0;
    turnOffLED();
  }
  lastButtonState = buttonState;

  // Run current mode
  switch (currentMode) {
    case 0: digitalWrite(RED_LED_PIN, HIGH); break;
    case 1: digitalWrite(GREEN_LED_PIN, HIGH); break;
    case 2: digitalWrite(BLUE_LED_PIN, HIGH); break;
    case 3: constantBlink(); break;
    case 4: fadeBlink(); break;
    case 5: turnOffLED(); break;
  }

  delay(10);
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// CUSTOM FUNCTIONS
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
