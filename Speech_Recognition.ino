#define CMD_ON_PIN 2  // Button for "Turn ON"
#define CMD_OFF_PIN 3 // Button for "Turn OFF"
#define LED1_PIN 8    // First LED
#define LED2_PIN 9    // Second LED

bool deviceState = false; // Track LED state

void setup() {
  pinMode(CMD_ON_PIN, INPUT_PULLUP);
  pinMode(CMD_OFF_PIN, INPUT_PULLUP);
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  digitalWrite(LED1_PIN, LOW);
  digitalWrite(LED2_PIN, LOW);
}

void loop() {
  static bool lastOnState = HIGH;  
  static bool lastOffState = HIGH; 

  bool currentOnState = digitalRead(CMD_ON_PIN);
  bool currentOffState = digitalRead(CMD_OFF_PIN);

  // Detect button press (state change from HIGH to LOW)
  if (lastOnState == HIGH && currentOnState == LOW) {
    deviceState = true;
    digitalWrite(LED1_PIN, HIGH);
    digitalWrite(LED2_PIN, HIGH);
  }

  if (lastOffState == HIGH && currentOffState == LOW) {
    deviceState = false;
    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED2_PIN, LOW);
  }

  // Update last state
  lastOnState = currentOnState;
  lastOffState = currentOffState;

  delay(50); // Short debounce delay
}


