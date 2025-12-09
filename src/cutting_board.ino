#include <Servo.h>

// ------------ SERVO ------------
#define SERVO_PIN 5
Servo servo;

int servoDownAngle = 115;   // nuga all
int servoUpAngle   = 0;     // nuga üleval

bool isCutting = false;     
bool cutDone = false;       
unsigned long cutStartTime = 0;
unsigned long cutDuration = 800;  // kui kaua nuga on all (ms)

// ------------ STEPPER ------------
const int dirPin = 2;
const int stepPin = 3;

int stepDirection = 1;     
int smallStep = 50;        
int stepsDone = 0;         
int stepsLimit = 600;      

unsigned long lastStepTime = 0;
unsigned long stepInterval = 8000; 

// paus
unsigned long pauseStart = 0;
unsigned long pauseDuration = 5000;
bool isPaused = false;

void setup() {
  servo.attach(SERVO_PIN);
  servo.write(servoUpAngle);

  pinMode(dirPin, OUTPUT);
  pinMode(stepPin, OUTPUT);
  digitalWrite(dirPin, HIGH);
}

void loop() {
  unsigned long nowMicros = micros();
  unsigned long nowMillis = millis();

  if (isPaused) {

    if (!cutDone) {

      if (!isCutting) {
        // alusta lõikamist (allapoole)
        servo.write(servoDownAngle);
        isCutting = true;
        cutStartTime = nowMillis;
      }

      // kui nuga on all olnud cutDuration ms → tõsta üles
      else if (nowMillis - cutStartTime >= cutDuration) {
        servo.write(servoUpAngle);
        cutDone = true;     // TÄPSUSEGA ÜKS lõige
        isCutting = false;
      }
    }

    if (cutDone && nowMillis - pauseStart >= pauseDuration) {
      isPaused = false;
      cutDone = false;
      isCutting = false;
    }

    return;   // Stepper EI LIIGU
  }

  if (stepDirection == -1) {
    if (nowMicros - lastStepTime >= stepInterval) {
      lastStepTime = nowMicros;

      digitalWrite(stepPin, HIGH);
      delayMicroseconds(5);
      digitalWrite(stepPin, LOW);

      stepsDone--;

      if (stepsDone <= 0) {
        stepDirection = 1;
        digitalWrite(dirPin, HIGH);
      }
    }
    return;
  }

  if (nowMicros - lastStepTime >= stepInterval) {
    lastStepTime = nowMicros;

    digitalWrite(stepPin, HIGH);
    delayMicroseconds(5);
    digitalWrite(stepPin, LOW);

    stepsDone++;

    if (stepsDone % smallStep == 0) {
      isPaused = true;
      pauseStart = nowMillis;
      cutDone = false;
      isCutting = false;
    }

    if (stepsDone >= stepsLimit) {
      stepDirection = -1;
      digitalWrite(dirPin, LOW);
    }
  }
}
