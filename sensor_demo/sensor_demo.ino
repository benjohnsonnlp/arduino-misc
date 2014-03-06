#include <Servo.h>
Servo servoMain; // Define our Servo

#define trigPin 13
#define echoPin 12
#define speakerPin 9
#define  cFreq     3830    // 261 Hz
#define  dFreq     3400    // 294 Hz
#define  eFreq     3038    // 329 Hz
#define  fFreq     2864    // 349 Hz
#define  gFreq     2550    // 392 Hz
#define  aFreq     2272    // 440 Hz
#define  bFreq    2028    // 493 Hz 

boolean goingUp = true;
int degree = 0;
int scale[] = {cFreq, dFreq, eFreq, fFreq, gFreq, aFreq, bFreq};

void setup() {
   Serial.begin(9600);
   //servoMain.attach(10); // servo on digital pin 10
   pinMode(trigPin, OUTPUT);
   pinMode(echoPin, INPUT);
   pinMode(speakerPin, OUTPUT);
}

void loop(){
  long duration = pingSonar();
  
  long distance = getDistance(duration);
    
  Serial.print(distance);
  Serial.println(" cm");
  
  //long servoDest = map(distance, 0, 61, 0, 180);
  
  //servoMain.write(servoDest);

  long toneLength = 1000;
  int restLength = 10;
  
  int scaleIndex = map(distance, 0, 61, 0, 6);
  int note = scale[scaleIndex];
  
  long played = 0;
  
  while(played < (toneLength * 100)){
    played += (note);

    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(note / 2);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(note / 2);
  }
  
   delay(restLength);
//  if(degree >= 180 && goingUp){
//    goingUp = false;
//  } else if (degree <= 0 && !goingUp){
//    goingUp = true;
//  }
//
//  servoMain.write(degree);  
//  if(distance >= 61){
//    if(goingUp){
//      degree ++;
//    } else {
//      degree --;
//    }
//  }
  
  
}

long getDistance(long duration){
  long distance = (duration/2) / 29.1;
  if(distance > 61){
    distance = 61;
  }
  return distance;
}

long pingSonar(){
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  return pulseIn(echoPin, HIGH);
}
