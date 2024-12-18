#include <Wire.h>
int data = 0; 


void setup(){
  Serial.begin(9600);
  // Start the I2C Bus as Slave on address 9
  Wire.begin(9); 
  // Attach a function to trigger when something is received.
  Wire.onReceive(receiveEvent);

  pinMode(4, OUTPUT);  //green
  pinMode(5, OUTPUT);  //yellow
  pinMode(6, OUTPUT);  //red

  pinMode(10, OUTPUT);  //green
  pinMode(11, OUTPUT);  //yellow
  pinMode(12, OUTPUT);  //red

  pinMode(1, OUTPUT);  //green
  pinMode(2, OUTPUT);  //yellow
  pinMode(7, OUTPUT);  //red
}
void receiveEvent() {
  data = Wire.read();    // read one character from the I2C
  /*  led's 456 are data id 1x noord
      led's 10 11 12 are data id 2x zuid
   */
}
/*
void ON_funcion(int x /*pin/){
  Serial.println("on");
  digitalWrite(x , HIGH);
}
void OFF_funcion(int x /*pin/){
  Serial.println("off");
  digitalWrite(x , LOW);
}
*/
void Green_funcion(int g, int y, int r ){ // GYR are pins
  Serial.println("green");
  digitalWrite(g , HIGH);
  digitalWrite(y , LOW);
  digitalWrite(r , LOW);
}
void YELLOW_funcion(int g, int y, int r ){ //GYR are pins
  Serial.println("Yellow");
  digitalWrite(g , LOW);      // yellow
  digitalWrite(y , HIGH);     // yellow
  digitalWrite(r , LOW);      // yellow
}
void RED_funcion(int g, int y, int r ){ //GYR are pins
  Serial.println("red");
  digitalWrite(g , LOW);      // red
  digitalWrite(y , LOW);      // red
  digitalWrite(r , HIGH);     // red
}
/*void Switch_for_10S(int on_g, int on_y, int on_r, int off_g, int off_y, int off_r){ //GYR are pins
  OFF_funcion(off_g);
  YELLOW_funcion(off_g, off_y, off_r);
  RED_funcion(off_g, off_y, off_r);
  delay(1000);
  Green_funcion(on_g, on_y, on_r);
  delay(10000);
  OFF_funcion(on_g);
  YELLOW_funcion(on_g, on_y, on_r);
  RED_funcion(on_g, on_y, on_r);
  delay(1000);
}

*/
void loop() {
  Serial.print(data);
  if (data == 11) {
    Green_funcion(4,5,6);
  }
  if (data == 12) {
    YELLOW_funcion(4,5,6);
  }
  if (data == 13) {
    RED_funcion(4,5,6);
  }


  if (data == 21) {
    Green_funcion(10,11,12);
  }
  if (data == 22) {
    YELLOW_funcion(10,11,12);
  }
  if (data == 23) {
    RED_funcion(10,11,12);
  }


  if (data == 31) {
    Green_funcion(7,2,3);
  }
  if (data == 32) {
    YELLOW_funcion(7,2,3);
  }
  if (data == 33) {
    RED_funcion(7,2,3);
  }
}
