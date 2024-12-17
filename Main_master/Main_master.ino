// Include the required Wire library for I2C<br>#include 
#include <Wire.h>

int x = 0;
int noord = 5;
int zuid = 6;

void setup() {
  Serial.begin(9600);
  //Start the I2C Bus as Master
  Wire.begin(); 
  pinMode(noord, INPUT_PULLUP); // defaut == true/HIGH/1
  pinMode(zuid, INPUT_PULLUP); // defaut == true/HIGH/1
}

void loop() {
  Serial.print("test");
  if (digitalRead(noord) == 0) {
    Serial.println("testn");
    Wire.beginTransmission(9); // transmit to device #9
    Wire.write(12);              // sends x 

    
    Wire.endTransmission();    // stop transmitting
  }
  if (digitalRead(zuid) == 0) {
    Serial.println("testz");
    Wire.beginTransmission(9); // transmit to device #9
    Wire.write(21);              // sends x 
    Wire.endTransmission();    // stop transmitting
  }
  if (digitalRead(zuid) == 1 && digitalRead(noord) == 1) {
    Serial.println("testa");
    Wire.beginTransmission(9); // transmit to device #9
    Wire.write(01);              // sends x 
    Wire.endTransmission();    // stop transmitting
    }
}
