#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

/*
 * This specifies an api for a serial client to directly control
 * devices that are wired to the arduino.
 *
 * The device sits listening to a serial device connected at pins 10, and 11.
 * It reads in a single character that represents a command.
 *
 * Commands:
 * p (rawPinRequest)
 * This request asks to do a digitalWrite onto a pin on the arduino.  The second byte read
 * is an int representing in the pin's number.  The third byte read is a char 'h' or 'l' which
 * specifies how to set the pin, (high and low respectively)
 *
 */

int light = 13;

void setup()  
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  Serial.println("Listening for input...");

  pinMode(light, OUTPUT);
  digitalWrite(light, HIGH);


  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
}

void rawPinRequest(){
  int pin = mySerial.read();
  if (pin == -1){
    return;
  }

  char setting = mySerial.read();

  if (setting == -1){
    return;
  } 
  else if (setting == 'h'){
    Serial.println("Writing pin HIGH");
    digitalWrite(pin, HIGH);
  } 
  else if (setting == 'l'){
    Serial.println("Writing pin LOW");
    digitalWrite(pin, LOW);
  }
}

void loop() // run over and over
{
  char command = mySerial.read();
  delay(5);
  /* if(command != -1){
   Serial.println("Command received" + command);
   } */
  if(command == 'p'){
    rawPinRequest();
  }
}



