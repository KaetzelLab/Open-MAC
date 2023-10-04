//this is sketch file for torque mode operation of Open-MAC commutator
int dirPin = D7;   // Direction was 7
int stepPin = D8;  // Step
int EnPin = D9;    // Enable was 9

int sensorReading_delay = 0;
int step_delay_dur = 500;
int stepsPerRevolution = 50;

void setup() {
  Serial.begin(9600);
  // initial speed and the target position
  pinMode(EnPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(stepPin, OUTPUT);
  // Hall sensors
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  digitalWrite(EnPin, HIGH);
}

void loop() {
  if (digitalRead(A2) == 0) {
    digitalWrite(dirPin, HIGH);
    digitalWrite(EnPin, LOW);
    for (int i = 0; i < stepsPerRevolution; i++) {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(step_delay_dur);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(step_delay_dur);
    }
    digitalWrite(EnPin, HIGH);
  } else if (digitalRead(A1) == 0) {
    digitalWrite(dirPin, LOW);
    digitalWrite(EnPin, LOW);
    for (int i = 0; i < stepsPerRevolution; i++) {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(step_delay_dur);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(step_delay_dur);
    }
    digitalWrite(EnPin, HIGH);
  }
}