// Include the required Wire library for I2C bus
#include <Wire.h>
// declar prevtime for time management 
unsigned long prevtime = 0;
// declar ident
int ident = 1 ;

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
  if (ident == 1 && currenttime - prevtime > 5000) { // to yellow
      write(12);
      write(22);
      ident = 2;
      prevtime = currenttime;
    }
  
  if (ident == 2 && currenttime - prevtime > 5000) {// to red
      write(13);
      write(23);
      ident = 3;
      prevtime = currenttime;
    
  }
  if (ident == 3 && currenttime - prevtime > 5000) {// to green
      write(31);
      ident = 4;
      prevtime = currenttime;
    
  }
  if (ident == 4 && currenttime - prevtime > 5000) {// to yellow
      write(32);
      ident = 5;
      prevtime = currenttime;
  }
  if (ident == 5 && currenttime - prevtime > 5000) {// to red
      write(33);
      ident = 6;
      prevtime = currenttime;
  }

  if (ident == 6 && currenttime - prevtime > 5000) {// to green
    write(11);
    write(21);
    ident = 1;
    prevtime = currenttime;
  }
}

