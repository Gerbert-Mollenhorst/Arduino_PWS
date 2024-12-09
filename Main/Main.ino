void setup(){
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(2, INPUT_PULLUP); // defaut == true/HIGH/1

  pinMode(12, OUTPUT);  //red
  pinMode(11, OUTPUT);  //yellow
  pinMode(10, OUTPUT);  //green
}

void ON_funcion(int x /*pin*/){
  Serial.println("on");
  digitalWrite(x , HIGH);
}
void OFF_funcion(int x /*pin*/){
  Serial.println("off");
  digitalWrite(x , LOW);
}
void Green_funcion(int g, int y, int r ){ // GYR are pins
  Serial.println("green");
  digitalWrite(g , HIGH);
  digitalWrite(y , LOW);
  digitalWrite(r , LOW);
}
void YELLOW_funcion(int g, int y, int r ){ //GYR are pins
  Serial.println("red");
  digitalWrite(g , LOW);      // yellow
  digitalWrite(y , HIGH);     // yellow
  digitalWrite(r , LOW);      // yellow
  delay(3000);
}
void RED_funcion(int g, int y, int r ){ //GYR are pins
  digitalWrite(g , LOW);      // red
  digitalWrite(y , LOW);      // red
  digitalWrite(r , HIGH);     // red
}
int i = 0;
void loop() {
  while(digitalRead(2) == LOW){
    YELLOW_funcion(10,11,12);
    RED_funcion(10,11,12);
    ON_funcion(13);
    delay(10000);
  }
  
  Green_funcion(10,11,12);
  OFF_funcion(13);
  

}

