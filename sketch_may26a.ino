
void setup(){
  Serial.begin(9600);
//  pinMode(A5, INPUT);
}

void loop(){
  int sound = analogRead(A5);
  if(sound > 7){
    Serial.println(sound);
  }
}
