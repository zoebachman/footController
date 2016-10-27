/*
  Analog Input
 Demonstrates analog input by reading an analog sensor on analog pin 0 and
 turning on and off a light emitting diode(LED)  connected to digital pin 13.
 The amount of time the LED will be on and off depends on
 the value obtained by analogRead().

 The circuit:
 * Potentiometer attached to analog input 0
 * center pin of the potentiometer to the analog pin
 * one side pin (either one) to ground
 * the other side pin to +5V
 * LED anode (long leg) attached to digital output 13
 * LED cathode (short leg) attached to ground

 * Note: because most Arduinos have a built-in LED attached
 to pin 13 on the board, the LED is optional.


 Created by David Cuartielles
 modified 30 Aug 2011
 By Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/AnalogInput

 */

int sensorPinTop = A0;
int sensorPinBottom = A1;
int ledPinTop = 12;
int ledPinBottom = 13; // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor
int top; 
int bottom;

void setup() {
  // declare the ledPin as an OUTPUT:
  Serial.begin(9600);   
  pinMode(ledPinTop, OUTPUT);
  pinMode(ledPinBottom, OUTPUT);
}

void loop() {

  top = analogRead(sensorPinTop);  // Reads the FSR
  bottom = analogRead(sensorPinBottom); 
  Serial.print("Analog reading Top = "); 
  Serial.println(top);
  Serial.print("Analog reading Bottom= "); 
  Serial.println(bottom);

  if (top < 600){
    digitalWrite(ledPinTop, LOW);
  } else {
    digitalWrite(ledPinTop, HIGH);
  }
  delay(150);

  if (bottom < 500){
    digitalWrite(ledPinBottom, LOW);
  } else {
    digitalWrite(ledPinBottom, HIGH);
  }
  delay(150);

  
}
//top - 470
//bottom - 540
