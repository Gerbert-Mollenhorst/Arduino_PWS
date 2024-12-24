// Include the required Wire library for I2C bus
#include <Wire.h>
// declar prevtime for time management 
unsigned long prevtime_1 = 0;
unsigned long prevtime_2 = 0;
// declar ident
int ident_1 = 1 ;
int ident_2 = 1 ;
// declar wait time (ms)
int red = 1000;
int yellow = 5000;
int green = 10000;
// setup button pins
bool button_1 = false;
int main_road = 2;
int side_road = 3;

// function send data over I2C bus
void write(int data) {
  Wire.beginTransmission(9);  // transmit to device #9
  Wire.write(data);           // sending data
  Wire.endTransmission();     // Stop transmitting
}
// setup function *mandatory
void setup() {
  // start debug tool
  Serial.begin(9600);
  //Start the I2C Bus as Master
  Wire.begin(); 
  // setup the input ligts 
  pinMode(main_road , INPUT_PULLUP);
  pinMode(side_road , INPUT_PULLUP);
  // start lights
  write(11);
  write(21);
  write(33);
  // debug tool
  Serial.println("end setup");
}
int tbd = 0; 
// loop function *mandatory
void loop() {
  // declar currenttime for time management 
  unsigned long currenttime_1 = millis();

  while (ident_1 == 1 && currenttime_1 - prevtime_1 > tbd ){
    unsigned long currenttime_2 = millis();
    if (ident_2== 1 && currenttime_2 - prevtime_2 > green) { // to yellow
      write(12);
      write(22);
      ident_2 = 2;
      prevtime_2 = currenttime_2;
    }
    
    if (ident_2 == 2 && currenttime_2 - prevtime_2 > yellow) {// to red
      write(13);
      write(23);
      ident_2 = 3;
      prevtime_2 = currenttime_2;
    }

    if (ident_2 == 3 && currenttime_2 - prevtime_2 > red ) {// to green
      write(31);
      ident_2 = 4;
      prevtime_2 = currenttime_2;
    }
    
    if (true/*button press*/){
      button_1 = true;
    }

    if (ident_2 == 4){
      ident_1 = 2;
      ident_2 = 1;
      prevtime_1 = currenttime_1;
    }
  }

  while (ident_1 == 2 && currenttime_1 - prevtime_1 > tbd ){
    unsigned long currenttime_2 = millis();
    if (ident_2 == 1 && currenttime_2 - prevtime_2 > green) {// to yellow
      write(32);
      ident_2 = 2; 
      prevtime_2 = currenttime_2;
    }

    if (ident_2 == 2 && currenttime_2 - prevtime_2 > yellow) {// to red
      write(33);
      ident_2 = 3;
      prevtime_2 = currenttime_2;
    }

    if (ident_2 == 3 && currenttime_2 - prevtime_2 > red) {// to green
      write(11);
      write(21);
      ident_2 = 4;
      prevtime_2 = currenttime_2;
    }

    if (true/*button press*/){
      button_1 = true;
    }

    if (ident_2 == 4){
      ident_1 = 3;
      ident_2 = 1;
      prevtime_1 = currenttime_1;
    }
  }
  if (button_1 = true){
    button_1 = false;
    // set correct "ident_1"
  }
}


















