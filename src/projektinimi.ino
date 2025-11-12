#include <Servo.h>
#define SIGNAL_PIN 3  // Servo juhtimispin

Servo motor;  // Servo mootori objekt
int currentAngle = 0;  // Praegune nurk
int increment = 5;     // Nurga muutmise samm (kiirus)

void setup() {
  motor.attach(SIGNAL_PIN);  // Ühendame servo mootori
  Serial.begin(9600);        // Seadistame jadapordi
}

void loop() {
  motor.write(currentAngle);  // Määrame servo nurga
  Serial.print("Servo asend: ");
  Serial.println(currentAngle);
  
  currentAngle += increment;  // Muudame nurka
  
  // Muudame suunda kui piirid jõutakse
  if (currentAngle >= 140 || currentAngle <= 0) {
    increment = -increment;  // Vastupidine suund
  }
  
  delay(15);  // Viivitus sujuvuse jaoks (reguleerige vajadusel)
}
