/* Sweep
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>
Servo myservo1;  // create servo object to control a servo
Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo5;
Servo myservo6;

boolean btnTouch = false;

//int pos = 0;    

void setup() {
  Serial.begin(9600);
  
  myservo1.attach(3);  // attaches the servo on pins
  myservo2.attach(5);
  myservo3.attach(6);
  myservo4.attach(9);
  myservo5.attach(10);
  myservo6.attach(11);
}

void loop() {
  int sensor=analogRead(A0);
  Serial.println(sensor);
  delay(500);
  
  if(sensor > 900) {
    btnTouch = !btnTouch;
    if(btnTouch) {
      Serial.println("Button True");
      for (int pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
        myservo2.write(pos);              // tell servo to go to position in variable 'pos'
        myservo3.write(pos);
        delay(5);                       // waits 15ms for the servo to reach the position
      }
    } else {
      Serial.println("Button False");
      for (int pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
        myservo2.write(pos);              // tell servo to go to position in variable 'pos'
        myservo3.write(pos);
        delay(5);                       // waits 15ms for the servo to reach the position
      }
    }
  }
}

void showPanels() {
  // TODO
}

void hidePanels() {
  // TODO
}
