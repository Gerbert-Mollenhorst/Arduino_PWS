// Include the required Wire library for I2C bus
#include <Wire.h>

int data = 0; 
// declar lights group 1 
int green_1 = 4;
int yellow_1 = 5;
int red_1 = 6;
// declar lights group 2
int green_2 = 10;
int yellow_2 = 11;
int red_2 = 12;
// declar lights group 3
int green_3 = 7;
int yellow_3 = 2;
int red_3 = 3;

// setup function *mandatory
void setup(){
  // start debug tool
  Serial.begin(9600);
  // Start the I2C Bus as Slave on address 9
  Wire.begin(9); 
  // Attach a function to trigger when something is received.
  Wire.onReceive(receiveEvent);
  // Setup lights group 1
  pinMode(green_1, OUTPUT);
  pinMode(yellow_1, OUTPUT);
  pinMode(red_1, OUTPUT);
  // Setup lights group 2
  pinMode(green_2, OUTPUT);
  pinMode(yellow_2, OUTPUT);
  pinMode(red_2, OUTPUT);
  // Setup lights group 3
  pinMode(green_3, OUTPUT);
  pinMode(yellow_3, OUTPUT);
  pinMode(red_3, OUTPUT);
}

// function for receiving from master and set in variable "data"
void receiveEvent() {
  data = Wire.read();
}
// function for turing lights green
void Green_funcion(int g, int y, int r ){ // GYR are pins
  digitalWrite(g , HIGH);
  digitalWrite(y , LOW);
  digitalWrite(r , LOW);
}
// function for turing lights yellow
void YELLOW_funcion(int g, int y, int r ){ //GYR are pins
  digitalWrite(g , LOW); 
  digitalWrite(y , HIGH);
  digitalWrite(r , LOW);
}
// function for turing lights red
void RED_funcion(int g, int y, int r ){ //GYR are pins
  digitalWrite(g , LOW);      
  digitalWrite(y , LOW);      
  digitalWrite(r , HIGH);    
}

// loop function *mandatory
void loop() {
  // declare functions for lights groep 1
  if (data == 41) {
    Green_funcion(green_1, yellow_1, red_1);
  }
  if (data == 42) {
    YELLOW_funcion(green_1, yellow_1, red_1);
  }
  if (data == 43) {
    RED_funcion(green_1, yellow_1, red_1);
  }

  // declare functions for lights groep 2
  if (data == 51) {
    Green_funcion(green_2, yellow_2, red_2);
    Green_funcion(green_3, yellow_3, red_3);
  }
  if (data == 52) {
    YELLOW_funcion(green_2, yellow_2, red_2);
    YELLOW_funcion(green_3, yellow_3, red_3);
  }
  if (data == 53) {
    RED_funcion(green_2, yellow_2, red_2);
    RED_funcion(green_3, yellow_3, red_3);
  }
  

}
