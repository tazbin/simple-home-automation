#define LDRpin A0 // pin where we connected the LDR and the resistor

int lrdValue = 0;     // result of reading the analog pin
int lightPin = 13;

void setup() {
  Serial.begin(9600); // sets serial port for communication
}

void loop() {
  lrdValue = analogRead(LDRpin); // read the value from the LDR
  Serial.println(lrdValue);      // print the value to the serial port
  if(lrdValue<100){
    digitalWrite(lightPin, HIGH);
  } else{
    digitalWrite(lightPin, LOW);
  }
  delay(100);                    // wait a little
}
