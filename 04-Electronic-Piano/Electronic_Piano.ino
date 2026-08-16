// Buttons and their GPIO pins
const int NUM_KEYS = 4;
const int buttonPins[NUM_KEYS] = {19, 18, 14, 13};

// C4, D4, E4, F4
const int notes[NUM_KEYS] = {262, 294, 330, 349};

const int buzzerPin = 23;

void setup() {
  pinMode(buzzerPin, OUTPUT);

  // Internal pull-up for buttons
  for (int i = 0; i < NUM_KEYS; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
}

void loop() {
  bool keyPressed = false;

  // Check each button
  for (int i = 0; i < NUM_KEYS; i++) {

    // Pressed = LOW
    if (digitalRead(buttonPins[i]) == LOW) {
      tone(buzzerPin, notes[i]);
      keyPressed = true;
      break;
    }
  }

  // Stop when no button is pressed
  if (!keyPressed) {
    noTone(buzzerPin);
  }
}