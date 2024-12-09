#include <Arduino.h>

void setup() {
  // put your setup code here, to run once:
  pinMode(2,OUTPUT); // red
  pinMode(3,OUTPUT); // yellow
  pinMode(4,OUTPUT); // green
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  delay(3000);
  digitalWrite(2, LOW);
  digitalWrite(4, HIGH);
  delay(4000);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  delay(1000);
}
void eenFunctie() {
  
}
