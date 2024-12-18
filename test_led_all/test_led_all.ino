void setup() {
  pinMode(1, OUTPUT);  //green
  pinMode(2, OUTPUT);  //yellow
  pinMode(3, OUTPUT);  //red
  
  pinMode(4, OUTPUT);  //green
  pinMode(5, OUTPUT);  //yellow
  pinMode(6, OUTPUT);  //red

  pinMode(10, OUTPUT);  //green
  pinMode(11, OUTPUT);  //yellow
  pinMode(12, OUTPUT);  //red
}

void loop() {
  digitalWrite(1 , HIGH);
  digitalWrite(2 , HIGH);
  digitalWrite(3 , HIGH);
  digitalWrite(4 , HIGH);
  digitalWrite(5 , HIGH);
  digitalWrite(6 , HIGH);
  digitalWrite(10 , HIGH);
  digitalWrite(11 , HIGH);
  digitalWrite(12 , HIGH);
}
