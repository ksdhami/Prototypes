#include <Servo.h>
#include "DHT.h"

#define DHTPIN 2  // input digital pin 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

Servo serv1;
boolean btnDebug = true;

void setup() {

  Serial.begin(9600);

  serv1.attach(6);
  dht.begin();
}

void loop() {
//  int sensor = analogRead(A1);
//  Serial.println(sensor);
  delay(1000);

//  TOUCH SENSOR ONLY 
//  if(sensor > 900) {
//    btnDebug = !btnDebug;
//    if(btnDebug) {
//      Serial.println("Button On");
//      int pos = 150;
//      serv1.write(pos);
//      delay(5);
//    } else {
//      Serial.println("Button Off");
//      int pos = 0;
//      serv1.write(pos);
//      delay(5);
//    }
//  } 

  float h = dht.readHumidity(); // read humidity
  float t = dht.readTemperature();  // read temp

  if (isnan(h) || isnan(t)) { // error handling 
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  float hic = dht.computeHeatIndex(t, h, false);  // heat index in celcius 
  Serial.print("Luftfeuchtigkeit: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperatur: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.println(" *C ");

  if(hic > 27.00) {
    Serial.println("pull apart");
    int pos = 150;
    serv1.write(pos);
    delay(5);
  } else {
    Serial.println("put together");
    int pos = 0;
    serv1.write(pos);
    delay(5);
  }
}
