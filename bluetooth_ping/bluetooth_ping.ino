#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

/*
 * This snippet will connect to a bluetooth device connected
 * to pins 10 and 11.  It will print 'n' once a second to anything
 * that reads from it.  If something writes to it, it will print out
 * what was written and then return to printing 'n'.
 */

void setup()  
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }


  Serial.println("Goodnight moon!");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  mySerial.println("Hello, world?");
}

char btread = 'n';

void loop() // run over and over
{
   delay(1000);
   mySerial.println(btread);
   Serial.println(btread);
   btread = mySerial.read();
   
   if(btread == -1){
     btread = 'n';
   }
}
