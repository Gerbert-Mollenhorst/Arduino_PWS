// Include the required Wire library for I2C bus
#include <Wire.h>
// declar prevtime for time management 
unsigned long prevtime = 0;
// declar ident
int ident = 1 ;
// declar wait time (ms)
int red = 500;
int yellow = 2000;
int green = 5000;
// setup button pins
int main_road = 2;
int side_road = 3;

// Definieer de pinnen voor de sensoren
const int trigPin = 9; // definieer de pin waar de trigger van de sensor op aangesloten is
const int echoPin = 10; // definieer de pin waar de echo van de sensor op aangesloten is

int ref_distance = 10;

// Definieer variabelen
long duration; // variabele voor de tijd die nodig is voor de echo van de sensor om terug te keren
int distance; // variabele voor de afstand die we gaan meten

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
    // Attach a function to trigger when something is received.
  Wire.onReceive(receiveEvent);
  pinMode(main_road , INPUT_PULLUP);
  pinMode(side_road , INPUT_PULLUP);
  // Definieer de pinnen als invoer of uitvoer
  pinMode(trigPin, OUTPUT); // stel de trigger pin in als uitgang
  pinMode(echoPin, INPUT); // stel de echo pin in als ingang

  // start lights
  write(11);
  write(23);
  write(33);
  write(43);
  write(53);
  // debug tool
  Serial.println("end setup");
}
// function for receiving from master and set in variable "data"
void receiveEvent() {
  data = Wire.read();
// loop function *mandatory
void loop() {
  // declar currenttime for time management 
  if (currenttime - prevtime > 500){
    traffic()
  }

  unsigned long currenttime = millis();
  if (ident == 1 && currenttime - prevtime > green) { // to yellow
    write(12);
    ident = 2;
    prevtime = currenttime;
  }
  if (ident == 2 && currenttime - prevtime > yellow) {// to red
    write(13);
    ident = 3;
    prevtime = currenttime;
  }
  if (ident == 3 && currenttime - prevtime > red ) {// to green
    write(21);
    ident = 4;
    prevtime = currenttime;
  }
  if (ident == 4 && currenttime - prevtime > green) {// to yellow
    write(22);
    ident = 5;
    prevtime = currenttime;
  }
  if (ident == 5 && currenttime - prevtime > yellow) {// to red
    write(23);
    ident = 6;
    prevtime = currenttime;
  }
  if (ident == 6 && currenttime - prevtime > red) {// to green
    write(31);
    ident = 7;
    prevtime = currenttime;
  }
  if (ident == 7 && currenttime - prevtime > green) {// to green
    write(32);
    ident = 8;
    prevtime = currenttime;
  }
  if (ident == 8 && currenttime - prevtime > yellow) {// to green
    write(33);
    ident = 9;
    prevtime = currenttime;
  }
  if (ident == 9 && currenttime - prevtime > red) {// to green
    write(41);
    ident = 10;
    prevtime = currenttime;
  }
  if (ident == 10 && currenttime - prevtime > green) {// to green
    write(42);
    ident = 11;
    prevtime = currenttime;
  }
  if (ident == 11 && currenttime - prevtime > yellow) {// to green
    write(43);
    ident = 12;
    prevtime = currenttime;
  }
  if (ident == 12 && currenttime - prevtime > red) {// to green
    write(51);
    ident = 13;
    prevtime = currenttime;
  }
  if (ident == 13 && currenttime - prevtime > green) {// to green
    write(52);
    ident = 14;
    prevtime = currenttime;
  }
  if (ident == 14 && currenttime - prevtime > yellow) {// to green
    write(53);
    ident = 15;
    prevtime = currenttime;
  }
  if (ident == 15 && currenttime - prevtime > red) {// to green
    write(11);
    ident = 1;
    prevtime = currenttime;
  }

  if (data == 1){
    ident = 15;
  }

}

