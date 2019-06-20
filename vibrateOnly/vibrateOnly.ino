/*
 * 
 */

bool debugMessage = false; // debugging message
int vPin = 6; // set vibrate pin
int vPin2 = 5;
int ramp[153];

void setup() {
  
  Serial.begin(9600);
  pinMode(vPin, OUTPUT); 
  pinMode(vPin2, OUTPUT);
  
}

// duty_cycle = motor_volt/power_volt
// using 3V motor and 5V power
// 1.5/5 => max = 76 => 30% duty cycle

void loop() {
  
  analogWrite(vPin, 1); 
  analogWrite(vPin2, 1); 
  delay(2000); 
  analogWrite(vPin, 75);
  analogWrite(vPin2, 75);
  delay(2000); 

//  analogWrite(vPin, 0); 
//  analogWrite(vPin, LOW);
//  delay(1000); 


//  int x;
//  for(x=0; x<255; x++) {
//    analogWrite(6, x);
//  }
//  analogWrite(6, 0);
//  delay(2000);



//  for(int x=0; x<154; x++) {
//    int y = ramp[x];
//    analogWrite(vPin, y);
//  }
//  analogWrite(vPin, 0);
//  delay(2000);

}


void back(int intensity) {
  // TODO
}

void shoulder(int intensity) {
  // TODO
}

void pocket(int intensity) {
  // TODO
}
