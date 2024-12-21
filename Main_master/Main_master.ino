// Include the required Wire library for I2C bus
#include <Wire.h>
// declar prevtime for time management 
unsigned long prevtime = 0;
// declar ident
int ident = 1 ;
// declar wait time (ms)
int red = 1000;
int yellow = 5000;
int green = 10000;
// setup button pins
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

// loop function *mandatory
void loop() {
  // declar currenttime for time management 
  unsigned long currenttime = millis();
  if (ident == 1 && currenttime - prevtime > green) { // to yellow
      write(12);
      write(22);
      ident = 2;
      prevtime = currenttime;
    }
  
  if (ident == 2 && currenttime - prevtime > yellow) {// to red
      write(13);
      write(23);
      ident = 3;
      prevtime = currenttime;
    
  }
  if (ident == 3 && currenttime - prevtime > red ) {// to green
      write(31);
      ident = 4;
      prevtime = currenttime;
    
  }
  if (ident == 4 && currenttime - prevtime > green) {// to yellow
      write(32);
      ident = 5;
      prevtime = currenttime;
  }
  if (ident == 5 && currenttime - prevtime > yellow) {// to red
      write(33);
      ident = 6;
      prevtime = currenttime;
  }

  if (ident == 6 && currenttime - prevtime > red) {// to green
    write(11);
    write(21);
    ident = 1;
    prevtime = currenttime;
  }
  if (ident == 1 && digitalRead(side_road) == 0 ){
    prevtime = currenttime + yellow;
  }
  if (ident == 4 && digitalRead(main_road) == 0 ){
    prevtime = currenttime + yellow;
  }
}

