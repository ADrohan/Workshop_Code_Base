/*
Blink

Turns an LED on for one second,  then off for one second
*/


int ledPin = 6;  // set which pin the led is connected to


// the setup function runs once when you press reset or power the board
void setup() { // opening brace for setup
  // initialize digital pin 6 as an output.
  pinMode(ledPin, OUTPUT);
} // closing brace for setup

// the loop function runs over and over again forever
void loop() { //opening brace for loop
  digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                  // wait for a second
  digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
} // closing brace for loop
