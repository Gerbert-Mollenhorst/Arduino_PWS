// Definieer de pinnen voor de sensoren
const int trigPin = 9; // definieer de pin waar de trigger van de sensor op aangesloten is
const int echoPin = 10; // definieer de pin waar de echo van de sensor op aangesloten is

// Definieer variabelen
long duration; // variabele voor de tijd die nodig is voor de echo van de sensor om terug te keren
int distance; // variabele voor de afstand die we gaan meten

void setup() {
  // Zet de seriële monitor aan
  Serial.begin(9600); // start de seriële communicatie met een baud rate van 9600

  // Definieer de pinnen als invoer of uitvoer
  pinMode(trigPin, OUTPUT); // stel de trigger pin in als uitgang
  pinMode(echoPin, INPUT); // stel de echo pin in als ingang
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

  Serial.print("Afstand: "); // toon de tekst "Afstand:" op de seriële monitor
  Serial.print(distance); // toon de berekende afstand op de seriële monitor
  Serial.println(" cm"); // toon de tekst "cm" op de seriële monitor en maak een nieuwe regel aan

  delay(500); // wacht 500 milliseconden voordat we opnieuw beginnen met meten
}