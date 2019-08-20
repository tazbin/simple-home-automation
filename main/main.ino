//motion initialization--------------------------------------------
int sensor = A5;              // the pin that the sensor is atteched to
int state = LOW;             // by default, no motion detected
int pirVal = 0;                 // variable to store the sensor status (value)
//motion initializatin--------------------------------------------

//ldr initialization--------------------------------------------
#define LDRpin A0 // pin where we connected the LDR and the resistor
int lrdValue = 0;     // result of reading the analog pin
int lightPin = 13;
//ldr initializatin--------------------------------------------

//dht11 initialization--------------------------------------------
#include <DHT.h>
#define DHTPIN 4
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);
float t = 0;
//dht11 initializatin--------------------------------------------

//fan initialization--------------------------------------------
#define fanPin 10
//fan initializatin--------------------------------------------

void setup() {
//  motion setup--------------------------------------------------
  pinMode(sensor, INPUT);    // initialize sensor as an input
//  motion setup--------------------------------------------------

//  ldr setup--------------------------------------------------
  pinMode(lightPin, OUTPUT);      // initalize LED as an output
  pinMode(LDRpin, INPUT);    // initialize sensor as an input
//  ldr setup--------------------------------------------------

//  dht11 setup--------------------------------------------------
  dht.begin();
//  dht11 setup--------------------------------------------------

//  fan setup--------------------------------------------------
  pinMode(fanPin, OUTPUT); 
//  fan setup--------------------------------------------------
  Serial.begin(9600);        // initialize serial
}

void loop(){
    delay(2000);                    // wait a little
    
//  motion--------------------------------------------------------
  pirVal = analogRead(sensor);   // read sensor value
//  motion--------------------------------------------------------

  if(pirVal>100){
    
//  ldr--------------------------------------------------------
  lrdValue = analogRead(LDRpin); // read the value from the LDR
  if(lrdValue<100){
    digitalWrite(lightPin, HIGH);
  } else{
    digitalWrite(lightPin, LOW);
  }
//  ldr--------------------------------------------------------

//  dht11--------------------------------------------------------
  float t = dht.readTemperature();
  Serial.print(F("Temperature: "));
  Serial.print(t);
  if(t>25){
    digitalWrite(fanPin, HIGH);
  } else {
    digitalWrite(fanPin, LOW);
  }
//  dht11--------------------------------------------------------

  }

  Serial.print("  PIR: ");
  Serial.print(pirVal);
  Serial.print("  LDR: ");
  Serial.println(lrdValue);      // print the value to the serial port

  lrdValue = 0;
   digitalWrite(lightPin, LOW);

}
