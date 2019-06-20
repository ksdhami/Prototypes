#include <AltSoftSerial.h>
AltSoftSerial BTserial; 
boolean DEBUG = true;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BTserial.begin(9600);

  if(DEBUG) {
    // open serial communication for debugging and show 
    // the sketch filename and the date compiled
    Serial.begin(9600);
    Serial.println(__FILE__);
    Serial.println(__DATE__);
    Serial.println(" ");
  }

  if (DEBUG) {   
    Serial.println("BTserial started at 9600");
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if 
}
