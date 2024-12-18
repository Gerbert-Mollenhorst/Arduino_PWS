// Include the required Wire library for I2C<br>#include 
#include <Wire.h>

//int x = 0;
int noord = 5;
int zuid = 6;

long p_10 = 10000;
long P_5 = 5000;

unsigned long prevtime = millis();
unsigned long prevtime_2 = millis();
unsigned long prevtime_3 = millis();
unsigned long prevtime_4 = millis();


void setup() {
  Serial.begin(9600);
  //Start the I2C Bus as Master
  Wire.begin(); 
  //pinMode(noord, INPUT_PULLUP); // defaut == true/HIGH/1
  //pinMode(zuid, INPUT_PULLUP); // defaut == true/HIGH/1
  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(11);
  Wire.write(21);
  Wire.write(33); 
  Wire.endTransmission();      // Stop transmitting
  Serial.println("end setup");


}

void loop() {
  unsigned long currenttime = millis();
  if (currenttime - prevtime > 5000){
    Serial.println(1);
    Wire.beginTransmission(9); // transmit to device #9
    Wire.write(12);
    Wire.write(22);
    Wire.endTransmission();      // Stop transmitting
    prevtime = currenttime;
  }
  if (currenttime - prevtime > 15000){
    Serial.println(2);
    Wire.beginTransmission(9); // transmit to device #9
    Wire.write(13);
    Wire.write(23);
    Wire.write(31);
    Wire.endTransmission();      // Stop transmitting
    prevtime = currenttime;
  }
  if (currenttime - prevtime > 20000){
    Serial.println(3);
    Wire.beginTransmission(9); // transmit to device #9
    Wire.write(32);
    Wire.endTransmission();      // Stop transmitting
    prevtime = currenttime;
  }
  if (currenttime - prevtime > 30000){
    Serial.println(4);
    Wire.beginTransmission(9); // transmit to device #9
    Wire.write(11);
    Wire.write(21);
    Wire.write(33); 
    Wire.endTransmission();      // Stop transmitting
    prevtime = currenttime;
  }
}




















