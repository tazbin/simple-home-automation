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

void setup() {
//  motion setup--------------------------------------------------
  pinMode(sensor, INPUT);    // initialize sensor as an input
//  motion setup--------------------------------------------------

//  ldr setup--------------------------------------------------
  pinMode(lightPin, OUTPUT);      // initalize LED as an output
  pinMode(LDRpin, INPUT);    // initialize sensor as an input
//  ldr setup--------------------------------------------------
  Serial.begin(9600);        // initialize serial
}

void loop(){
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
  delay(100);                    // wait a little
//  ldr--------------------------------------------------------

  }

  Serial.print("PIR: ");
  Serial.print(pirVal);
  Serial.print("  LDR:");
  Serial.print(lrdValue);      // print the value to the serial port
  Serial.print("\n");

  lrdValue = 0;
   digitalWrite(lightPin, LOW);

}
