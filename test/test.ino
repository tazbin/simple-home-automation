#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT11 

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));

  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(1000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();

  Serial.print(F("Temperature: "));
  Serial.println(t);
}
