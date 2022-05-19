/*
Push button code
When the button is pressed the led turns on. Otherwise the led is off 

*/

const int ledPin = 6;      //The LED is connected to pin 6 - this is a PWM pin
const int buttonPin = 2;   //The Button is connected to pin 2
int buttonState = 0;       // This is a variable to store the button's state 

void setup() {
  Serial.begin(9600);                  // required to output to the serial monitor
  pinMode (ledPin, OUTPUT);            //Set the LED pin as an output
  pinMode (buttonPin, INPUT_PULLUP);   //Set button as input pulling it HIGH 
}

void loop() {
  buttonState = digitalRead(buttonPin);  // read the state of the button pin
  Serial.println(buttonState);           // out put the state to the serial monitor

  //check if the button is pressed
  if (buttonState == LOW)  // if it is the button state is LOW
  {
    digitalWrite(ledPin, HIGH);  // turn the led on
  }
  else
  {
    digitalWrite(ledPin, LOW);  // or else turn the led off
  }
}
