void setup(){
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(2, INPUT_PULLUP); // defaut == true/HIGH/1

  pinMode(4, OUTPUT);  //green
  pinMode(5, OUTPUT);  //yellow
  pinMode(6, OUTPUT);  //red

  pinMode(10, OUTPUT);  //green
  pinMode(11, OUTPUT);  //yellow
  pinMode(12, OUTPUT);  //red
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
void Switch_for_10S(int on_g, int on_y, int on_r, int off_g, int off_y, int off_r){ //GYR are pins
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


void loop() {
  while(digitalRead(2) == LOW){  
  Switch_for_10S(4,5,6,10,11,12);
  }
  Green_funcion(10,11,12);
}


/*
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
*/ 
