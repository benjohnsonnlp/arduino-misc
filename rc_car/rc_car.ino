 const int turningMotor1 = 7;
 const int turningMotor2 = 8;
 const int driveMotor1 = 10;
 const int driveMotor2 = 11;
 const int sonarTrigger = 5;
 const int sonarEcho = 6;
 
 void setup(){
   Serial.begin(9600);
   pinMode(turningMotor1, OUTPUT);
   pinMode(turningMotor2, OUTPUT);
   pinMode(driveMotor1, OUTPUT);
   pinMode(driveMotor2, OUTPUT);
   pinMode(sonarTrigger, OUTPUT);
   pinMode(sonarEcho, INPUT);
 }
 
 void loop(){
   //pathFind();
//   int distance = updateAverage(pollSonar());
//   int motorSpeed = map(distance, 1, 61, 1, 99);
//   go(true, motorSpeed, 100);
    //go(true, 100, 1);
    turnLeft();
    //digitalWrite(driveMotor1, LOW);
    //digitalWrite(driveMotor2, HIGH);
 }
 
 void pathFind(){
   int distance = pollSonar();
   int avg = updateAverage(distance);
      
   if(avg > 58){
     go(true, 99, 50);
     turnStraight();
   } else  if (avg > 35){
     go(true, 99, 50);
     turnRight();
   } else {
     go(false, 70, 50);
     turnLeft();
   }
 }
 
 int readings[] = {-1, -1, -1};
 const int readingsHeld = 3;
 int readingsTaken = 0;
 int updateAverage(int newReading){
   //update array
   int indexToMod = readingsTaken % readingsHeld;
   readingsTaken++;
   readings[indexToMod] = newReading;
   
   //calculate average
   int total = 0;
   for(int i = 0; i < readingsHeld; i++){
     int reading = readings[i];
     if(reading != -1){
       total += reading;
     }
   }
   int numReadings = readingsTaken > readingsHeld ? readingsHeld : readingsTaken;
   return total / numReadings;
 }
 
 int pollSonar(){
   digitalWrite(sonarTrigger, LOW);
   delayMicroseconds(2);
   digitalWrite(sonarTrigger, HIGH);
   delayMicroseconds(10);
   digitalWrite(sonarTrigger, LOW);
   long duration = pulseIn(sonarEcho, HIGH, 3600);
   int distance = (int) ( (duration / 2) / 29.1);
   if(distance > 61 || duration == 0){
     distance = 61;
   }
   return distance;
 }
 
 void turnRight(){
   digitalWrite(turningMotor1, HIGH);
   digitalWrite(turningMotor2, LOW);
 }
 
 void turnLeft(){
   digitalWrite(turningMotor1, LOW);
   digitalWrite(turningMotor2, HIGH);
 }
 
 void turnStraight(){
   digitalWrite(turningMotor1, LOW);
   digitalWrite(turningMotor2, LOW);
 }
 
 void go(boolean forward, int motorSpeed, long durationInMS){
   //long PW = map(motorSpeed, 1, 100, 500, 1);
   
   long durationElapsed = 0;
   
   int pulse = 1000;
   int upPulse = map(motorSpeed, 1, 100, 1, pulse);
   int downPulse = pulse - upPulse;
   int pulses = 0;
   while(durationElapsed <= (durationInMS * 1000)){
     pulses++;
     if(forward){
       digitalWrite(driveMotor1, LOW);
       digitalWrite(driveMotor2, HIGH);
     } else {
       digitalWrite(driveMotor1, HIGH);
       digitalWrite(driveMotor2, LOW);
     }
     delayMicroseconds(upPulse);
     digitalWrite(driveMotor1, HIGH);
     digitalWrite(driveMotor2, HIGH);
     delayMicroseconds(downPulse);
     durationElapsed += pulse;
   }
   Serial.print("pulse:  "); Serial.println(pulse);
   Serial.print("pulses:  "); Serial.println(pulses);
 }
 
 void stopMotor(){
   digitalWrite(driveMotor1, HIGH);
   digitalWrite(driveMotor2, HIGH);
 }

