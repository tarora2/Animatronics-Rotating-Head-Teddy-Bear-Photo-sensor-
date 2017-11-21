const int pin1 = 2;  // pin 14 of hbox
const int pin2 = 3;  // pin 10 of hbox
const int speedpin = 9; 
const int ledpin = 13;
const int sensorpin = A0;

int sensorvalue; 
int sensor;
int sensorlow = 1023;
int sensorhigh = 0; 
int motorspeed = 0;
int enable = 0;

void setup() {
  pinMode (pin1, OUTPUT);
  pinMode (pin2, OUTPUT); 
  pinMode (speedpin, OUTPUT);
  pinMode (ledpin, OUTPUT);
  pinMode (sensorpin, INPUT);

  digitalWrite (speedpin, LOW);
  digitalWrite (ledpin, HIGH); 

  while (millis () < 5000) {
    sensorvalue = analogRead(A0);
    if (sensorvalue > sensorhigh) {
      sensorhigh = sensorvalue;
    }
    if (sensorvalue < sensorlow) {
      sensorlow = sensorvalue;
    }
  }
  digitalWrite (ledpin, LOW);
}

void loop() {
  sensorvalue = analogRead(A0);
  motorspeed = 40;

  int sensor = map(sensorvalue, sensorlow, sensorhigh, 0, 1000);
  
  if (sensor > 700) {
     analogWrite (speedpin, motorspeed);
     digitalWrite (pin1, HIGH);
     digitalWrite (pin2, LOW);
     delay(1000);
     digitalWrite (pin1, LOW);
     digitalWrite (pin2, HIGH);
     delay(1000);
  }
  else {
    analogWrite (speedpin, 0);
  }
}
