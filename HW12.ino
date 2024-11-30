// Pin Assignments
const int button1 = 3; // Button 1 connected to D3
const int button2 = 4; // Button 2 connected to D4
const int potentiometer = A0; // Potentiometer connected to A0
const int greenLED = 9; // Green LED for success
const int redLED = 10; // Red LED for failure

// Variables to track password state
int step = 0;
bool success = false;

void setup() {
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  Serial.begin(9600); // Optional for debugging
}

void loop() {
  // Read inputs
  int button1State = digitalRead(button1);
  int button2State = digitalRead(button2);
  int potValue = analogRead(potentiometer);

  // Password sequence logic
  if (step == 0 && button1State == HIGH) {
    step = 1; // Step 1: Button 1 pressed
    delay(300); // Debounce delay
  } 
  else if (step == 1 && potValue < 50) { // Step 2: Potentiometer to the left
    step = 2;
    delay(300); // Debounce delay
  } 
  else if (step == 2 && potValue > 950) { // Step 3: Potentiometer to the right
    step = 3;
    delay(300); // Debounce delay
  } 
  else if (step == 3 && button2State == HIGH) { // Step 4: Button 2 pressed
    success = true;
    signalSuccess(); // Password correct
    resetSequence();
  } 
  else if (step == 3 && button1State == HIGH) { // Step 4: Wrong button pressed
    signalFailure(); // Password failed
    resetSequence();
  }

  // Debugging: Print step and potentiometer value
  Serial.print("Step: ");
  Serial.print(step);
  Serial.print(" | Potentiometer: ");
  Serial.println(potValue);

  delay(100); // Short delay for stability
}

// Signal success with green LED
void signalSuccess() {
  digitalWrite(greenLED, HIGH);
  digitalWrite(redLED, LOW);
  delay(2000);
  digitalWrite(greenLED, LOW);
}

// Signal failure with red LED
void signalFailure() {
  digitalWrite(redLED, HIGH);
  digitalWrite(greenLED, LOW);
  delay(2000);
  digitalWrite(redLED, LOW);
}

// Reset the sequence to start over
void resetSequence() {
  step = 0;
  success = false;
}
