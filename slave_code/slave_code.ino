// Include the required Wire library for I2C<br>
#include <Wire.h>
int LED = 7;
int x = 0;
void setup() {
  Serial.begin(9600);
  // Define the LED pin as Output
  pinMode (LED, OUTPUT);
  // Start the I2C Bus as Slave on address 9
  Wire.begin(9); 
  // Attach a function to trigger when something is received.
  Wire.onReceive(receiveEvent);
}
void receiveEvent(int bytes) {
  x = Wire.read();    // read one character from the I2C
}
void loop() {
  //If value received is 0 blink LED for 200 ms
  Serial.println(x);
  if (x == 0) {
    Serial.println("a");
    digitalWrite(LED, HIGH);
    delay(2000);
    digitalWrite(LED, LOW);
    delay(2000);
  }
  //If value received is 3 blink LED for 400 ms
  if (x == 3) {
    Serial.println("b");
    digitalWrite(LED, HIGH);
    delay(4000);
    digitalWrite(LED, LOW);
    delay(4000);
  }
}