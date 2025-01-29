// Include the required Wire library for I2C bus
#include <Wire.h>

// Definieer de pinnen voor de sensoren
const int trigPin = 9; // definieer de pin waar de trigger van de sensor op aangesloten is
const int echoPin = 10; // definieer de pin waar de echo van de sensor op aangesloten is

const int trigPin_2 = 7; // definieer de pin waar de trigger van de sensor op aangesloten is
const int echoPin_2 = 8; // definieer de pin waar de echo van de sensor op aangesloten is

// Definieer variabelen
long duration; // variabele voor de tijd die nodig is voor de echo van de sensor om terug te keren
int distance; // variabele voor de afstand die we gaan meten
long duration_2; // variabele voor de tijd die nodig is voor de echo van de sensor om terug te keren
int distance_2; // variabele voor de afstand die we gaan meten

int ref_distance = 10;

// function send data over I2C bus
void write(int data) {
  Wire.beginTransmission(9);  // transmit to device #9
  Wire.write(data);           // sending data
  Wire.endTransmission();     // Stop transmitting
}

void setup() {
  // Zet de seriële monitor aan
  Serial.begin(9600); // start de seriële communicatie met een baud rate van 9600
  //Start the I2C Bus as Master
  Wire.begin(); 

  // Definieer de pinnen als invoer of uitvoer
  pinMode(trigPin, OUTPUT); // stel de trigger pin in als uitgang
  pinMode(echoPin, INPUT); // stel de echo pin in als ingang

  pinMode(trigPin_2, OUTPUT); // stel de trigger pin in als uitgang
  pinMode(echoPin_2, INPUT); // stel de echo pin in als ingang
}

void loop() {
  // Stuur een signaal naar de trig-pin
  digitalWrite(trigPin, LOW); // zet de trigpin uit
  delayMicroseconds(50); // wacht 50 milliseconden
  digitalWrite(trigPin, HIGH); // stuur een signaal naar de trigpin, een golf word uigezonden
  delayMicroseconds(200); // wacht 200 milliseconden
  digitalWrite(trigPin, LOW); // zet de trigger pin weer uit

  duration = pulseIn(echoPin, HIGH);// Meet de tijd tussen het verzenden en ontvangen van het signaal

  distance = duration * 0.034 / 2; // bereken de afstand in centimeters met de formule: afstand = (tijd * geluidssnelheid) / 2

  Serial.print("Afstand_1: "); // toon de tekst "Afstand:" op de seriële monitor
  Serial.print(distance); // toon de berekende afstand op de seriële monitor
  Serial.println(" cm"); // toon de tekst "cm" op de seriële monitor en maak een nieuwe regel aan

  delay(250); // wacht 500 milliseconden voordat we opnieuw beginnen met meten

  // Stuur een signaal naar de trig-pin
  digitalWrite(trigPin_2, LOW); // zet de trigpin uit
  delayMicroseconds(50); // wacht 50 milliseconden
  digitalWrite(trigPin_2, HIGH); // stuur een signaal naar de trigpin, een golf word uigezonden
  delayMicroseconds(200); // wacht 200 milliseconden
  digitalWrite(trigPin_2, LOW); // zet de trigger pin weer uit

  duration_2 = pulseIn(echoPin_2, HIGH);// Meet de tijd tussen het verzenden en ontvangen van het signaal

  distance_2 = duration_2 * 0.034 / 2; // bereken de afstand in centimeters met de formule: afstand = (tijd * geluidssnelheid) / 2

  Serial.print("Afstand_2: "); // toon de tekst "Afstand:" op de seriële monitor
  Serial.print(distance_2); // toon de berekende afstand op de seriële monitor
  Serial.println(" cm"); // toon de tekst "cm" op de seriële monitor en maak een nieuwe regel aan

  delay(250); // wacht 500 milliseconden voordat we opnieuw beginnen met meten

  if (distance < ref_distance || distance_2 < ref_distance){
    write(1);
  }
 

  if (distance > ref_distance && distance_2 > ref_distance ){
    write(0);
  }
}





