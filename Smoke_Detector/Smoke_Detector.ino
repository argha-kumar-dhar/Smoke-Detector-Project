int blueLED = 2;
int redLED = 3;
int buzzer = 5;
int smokeSensor = A0;     // Using Analog pin A0

int smokeLevel = 0;       // To store the analog value
int threshold =350;      // Set your HIGH threshold (example: 300)

void setup() {
  pinMode(blueLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(smokeSensor, INPUT);
  
  Serial.begin(9600);     // To see readings on Serial Monitor
}

void loop() {
  smokeLevel = analogRead(smokeSensor);
  Serial.println(smokeLevel);   // Monitor the exact reading

  if (smokeLevel >= threshold) {
    // Smoke detected
    digitalWrite(blueLED, LOW);
    digitalWrite(redLED, HIGH);
    tone(buzzer, 1000);
  } else {
    // No smoke
    digitalWrite(blueLED, HIGH);
    digitalWrite(redLED, LOW);
    noTone(buzzer);
  }

  delay(500);  // Optional, reduces serial spamming
}
