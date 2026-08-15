// Analog Level Meter

const int potPin = 34;

const int led1 = 2;
const int led2 = 4;
const int led3 = 5;
const int led4 = 13;
const int led5 = 14;

void setup() {

  // Configure LEDs as outputs
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);

  // Configure potentiometer as analog input
  pinMode(potPin, INPUT);

  Serial.begin(115200);
}

void loop() {

  // Read the potentiometer value
  int value = analogRead(potPin);

  // Display the potentiometer value
  Serial.println(value);

  // Turn OFF all LEDs first
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);

  // Turn ON LEDs according to the potentiometer level
  if (value >= 820) {
    digitalWrite(led1, HIGH);
  }

  if (value >= 1640) {
    digitalWrite(led2, HIGH);
  }

  if (value >= 2460) {
    digitalWrite(led3, HIGH);
  }

  if (value >= 3280) {
    digitalWrite(led4, HIGH);
  }

  if (value >= 3900) {
    digitalWrite(led5, HIGH);
  }

  delay(50);
}