#include <Servo.h>

// ------------ SERVO ------------
#define SERVO_PIN 5
Servo servo;

int servoDownAngle = 115;   // nuga all
int servoUpAngle   = 50;     // nuga üleval

bool isCutting = false;
bool cutDone = false;
unsigned long cutStartTime = 0;
unsigned long cutDuration = 800;  // kui kaua nuga on all (ms)

// ------------ STEPPER ------------
const int dirPin = 2;
const int stepPin = 3;

int stepDirection = 1;      // 1 = edasi, -1 = tagasi
int smallStep = 50;         
int stepsDone = 0;          
int stepsLimit = 600;

// jätame meelde suurima tegelikult tehtud sammu arvu
int maxStepsDone = 0;

unsigned long lastStepTime = 0;
unsigned long stepInterval = 8000;

// paus
unsigned long pauseStart = 0;
unsigned long pauseDuration = 4000;
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

  // ------------------------------------------------------
  // 1) PAUSIREŽIIM
  // ------------------------------------------------------
  if (isPaused) {

    // LÕIGE
    if (!cutDone) {

      if (!isCutting) {
        servo.write(servoDownAngle);
        isCutting = true;
        cutStartTime = nowMillis;
      }
      else if (nowMillis - cutStartTime >= cutDuration) {
        servo.write(servoUpAngle);
        cutDone = true;
        isCutting = false;
      }
    }

    // paus lõppeb
    if (cutDone && nowMillis - pauseStart >= pauseDuration) {
      isPaused = false;
      cutDone = false;
      isCutting = false;
    }

    return;   // stepper seisab
  }

  // ------------------------------------------------------
  // 2) TAGASISUUND
  // ------------------------------------------------------
  if (stepDirection == -1) {

    if (nowMicros - lastStepTime >= stepInterval) {
      lastStepTime = nowMicros;

      digitalWrite(stepPin, HIGH);
      delayMicroseconds(5);
      digitalWrite(stepPin, LOW);

      stepsDone--;

      // Kui jõuame tagasi algusesse → tagasi edasi suunda
      if (stepsDone <= 0) {
        stepDirection = 1;
        digitalWrite(dirPin, HIGH);

        // UUS: tsükli reset, et järgmine ring algaks nullist
        stepsDone = 0;
        maxStepsDone = 0;
      }
    }
    return;
  }

  // ------------------------------------------------------
  // 3) EDASI SUUND
  // ------------------------------------------------------
  if (nowMicros - lastStepTime >= stepInterval) {
    lastStepTime = nowMicros;

    digitalWrite(stepPin, HIGH);
    delayMicroseconds(5);
    digitalWrite(stepPin, LOW);

    stepsDone++;

    // jätame meelde reaalse maksimumi
    if (stepsDone > maxStepsDone) {
      maxStepsDone = stepsDone;
    }

    // Iga väikese distantsi järel paus sõlme jaoks
    if (stepsDone % smallStep == 0) {
      isPaused = true;
      pauseStart = nowMillis;
      cutDone = false;
      isCutting = false;
    }

    // Kui jõuti edasi liikumise piirini → tagasisuund
    if (stepsDone >= stepsLimit) {
      stepDirection = -1;
      digitalWrite(dirPin, LOW);
    }
  }
}
