void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(3, INPUT_PULLUP);
}

void loop() {
  Serial.println(digitalRead(3));
}
