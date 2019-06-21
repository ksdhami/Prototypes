// ALLNET Temperature & Humidity/Temp. & Feuchtigkeit
// Information http://www.allnet.de
//Arduino-DHT Iibrary wird hinzugefuegt
#include "DHT.h"
// Arduino-DHT Library wird initialisiert
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
//einmalig ausgeführte SetUp Befehle
void setup()
{
 //Starten der seriellen Übertragung
 Serial.begin(9600);
 Serial.println("DHTxx test!");
 //DHT11 Sensor wird gestartet
 dht.begin();
}
void loop()
{
 //Pause
 delay(2000);
 //Auslesen der Luftfeuchtigkeit
 float h = dht.readHumidity();
 
//Auslesen der Temperatur in Celsius
 float t = dht.readTemperature();
 //Auslesen der Temperatur in Farenheit
 float f = dht.readTemperature(true);
 //Prüft ob eine Messung fehlerhaft ist und bricht in dem Fall vorzeitig ab
// Eine Information darüber wird in der seriellen Ausgabe bereitgestellt
 if (isnan(h) || isnan(t) || isnan(f))
 {
 Serial.println("Failed to read from DHT sensor!");
 return;
 }
 //Berechnet den Heat Index in Farenheit
 float hif = dht.computeHeatIndex(f, h);
 //Berechnet den Heat Index in Celsius (isFahreheit
//= false)
 float hic = dht.computeHeatIndex(t, h, false);
 //Ausgabe der Sensorwerte
 Serial.print("Luftfeuchtigkeit: ");
 Serial.print(h);
 Serial.print(" %\t");
 Serial.print("Temperatur: ");
 Serial.print(t);
 Serial.print(" *C ");
 Serial.print(f);
 Serial.print(" *F\t");
 Serial.print("Heat index: ");
 Serial.print(hic);
 Serial.print(" *C ");
 Serial.print(hif);
 Serial.println(" *F");
} 
