
//this is sketch file for torque mode operation of Open-MAC commutator 
int dirPin  = A7;  // Direction
int stepPin = A8; // Step
int EnPin   = A9; // Enable

// Define Hall sensor connections
#define HALL_SENSOR_A      A1
#define HALL_SENSOR_B      A2
int sensorReading_delay   = 0;
int step_delay_dur = 300;
int stepsPerRevolution = 50;

void setup() {
  // initial speed and the target position
  pinMode(EnPin,OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(stepPin, OUTPUT);
  // Hall sensors 

  pinMode(HALL_SENSOR_A, INPUT);
  pinMode(HALL_SENSOR_B, INPUT);
  attachInterrupt(digitalPinToInterrupt(HALL_SENSOR_A), move_backward, LOW);  
  attachInterrupt(digitalPinToInterrupt(HALL_SENSOR_B), move_forward, LOW);    
}


void move_forward(){ 
  digitalWrite(dirPin, LOW); 
  // Spin the stepper motor 1 revolution quickly:
  for (int i = 0; i < stepsPerRevolution; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(step_delay_dur);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(step_delay_dur);    
  }  
  
}

void move_backward(){   
  digitalWrite(dirPin, HIGH);
  // Spin the stepper motor 1 revolution quickly:
  for (int i = 0; i < stepsPerRevolution; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);    
    delayMicroseconds(step_delay_dur);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(step_delay_dur);
  }  
  
}

  
void loop() { 
  delayMicroseconds(sensorReading_delay); 
 
 }
