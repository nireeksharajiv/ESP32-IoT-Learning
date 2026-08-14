// Smart Traffic Light with Pedestrian Crossing

// Pin Definitions
const int redPin = 2;
const int yellowPin = 4;
const int greenPin = 5;
const int walkPin = 18;
const int buttonPin = 19;
const int buzzerPin = 21;

// Stores whether a pedestrian has requested to cross
bool pedestrianRequested = false;

void setup() {

  // Configure LEDs and buzzer
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(walkPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  // Configure push button with internal pull-up resistor
  pinMode(buttonPin, INPUT_PULLUP);

  // Keep buzzer OFF initially (LOW-triggered)
  digitalWrite(buzzerPin, HIGH);

}

void loop() {

  greenPhase();
  yellowPhase();
  redPhase();

}

// Runs the green light phase
void greenPhase() {

  allOff();
  digitalWrite(greenPin, HIGH);

  unsigned long start = millis();

  while (millis() - start < 4000) {
    checkButton();
  }

}

// Runs the yellow light phase
void yellowPhase() {

  allOff();
  digitalWrite(yellowPin, HIGH);

  unsigned long start = millis();

  while (millis() - start < 1500) {
    checkButton();
  }

}

// Runs the red light phase
void redPhase() {

  allOff();
  digitalWrite(redPin, HIGH);

  unsigned long start = millis();

  while (millis() - start < 3000) {

    // Check if the button is pressed during the red light
    if (digitalRead(buttonPin) == LOW) {
      pedestrianRequested = true;

      while (digitalRead(buttonPin) == LOW);
      delay(20);
    }

  }

  // If a request was made, allow pedestrians to cross
  if (pedestrianRequested) {
    pedestrianPhase();
    pedestrianRequested = false;
  }

}

// Executes the pedestrian crossing phase
void pedestrianPhase() {

  digitalWrite(walkPin, HIGH);

  unsigned long start = millis();

  while (millis() - start < 5000) {

    // LOW-triggered active buzzer
    digitalWrite(buzzerPin, LOW);
    delay(300);

    digitalWrite(buzzerPin, HIGH);
    delay(300);

  }

  digitalWrite(walkPin, LOW);

}

// Checks whether the pedestrian button is pressed
void checkButton() {

  if (digitalRead(buttonPin) == LOW) {

    pedestrianRequested = true;

    // Wait until the button is released
    while (digitalRead(buttonPin) == LOW);

    delay(20);

  }

}

// Turns OFF all LEDs
void allOff() {

  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(walkPin, LOW);

}