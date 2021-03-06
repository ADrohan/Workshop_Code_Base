/*
  LilyPad Vibe Board
 
  The main loop checks for a button press. If there is a button press,
  the Arduino turns on the LilyPad Vibe motor Board and an LED will turn on too. 
  Otherwise, the LED and motor will remain off.
*/

const int motorPin = 7;     // vibe board connected to  7
const int button1Pin = 4;  // pushbutton connected to 4
const int ledPin =  8;     // LED connected to 8

int button1State;  //check state of button press

void setup() {
  //Serial.begin(9600); //setup serial monitor, uncomment Serial.print()'s to debug
  //Serial.println("Begin LilyPad Vibe Motor Tests");

  pinMode(button1Pin, INPUT_PULLUP);//set internal pull up for button
  pinMode(ledPin, OUTPUT); //visual feedback


  //Quick Test 1: Check If LED and Motor Can Turn On

  //Serial.println("Turn LilyPad Vibe Motor And LED ON");
  //digitalWrite(ledPin, HIGH);  // turn the LED on
  analogWrite(motorPin, 255);  //turn motor
  delay(300);

  //Serial.println("Turn LilyPad Vibe Motor And LED OFF");
  //digitalWrite(ledPin, LOW);  // turn the LED off
  analogWrite(motorPin, 0);   //turn motor off
  delay(300);

  //Quick Test 2: Check Intensity of Motor (turns on at about 130
  // fade in from min to max in increments of 5 points:
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    // sets the value (range from 0 to 255):
    analogWrite(motorPin, fadeValue);
    //Serial.print("LilyPad Vibe Motor Intensity = ");
    //Serial.println(fadeValue);

    // wait for 100 milliseconds to see motor
    delay(100);
  }
  // fade out from max to min in increments of 5 points:
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    // sets the value (range from 0 to 255):
    analogWrite(motorPin, fadeValue);
    //Serial.print("LilyPad Vibe Motor Intensity = ");
    //Serial.println(fadeValue);

    // wait for 100 milliseconds to see motor
    delay(100);
  }

}

void loop() {
  // Here we'll read the current pushbutton states into
  // a variable:

  // Remember that if the button is being pressed, it will be
  // connected to GND. If the button is not being pressed,
  // the pullup resistor will connect it to Vcc.

  // So the state will be LOW when it is being pressed,
  // and HIGH when it is not being pressed.

  // Now we'll use those states to control the LED.
  // Here's what we want to do:

  button1State = digitalRead(button1Pin);

  if (button1State == LOW)  // if we're pushing button 1
  {
    //Serial.println("Button has been pressed, turn LilyPad Vibe Motor And LED ON");
    digitalWrite(ledPin, HIGH);  // turn the LED on
    analogWrite(motorPin, 255);  //turn motor on
    delay(300);                  //slight delay for feedback
  }
  else
  {
    digitalWrite(ledPin, LOW);  // turn the LED
    analogWrite(motorPin, 0);   //turn motor off
    delay(300);
  }
}
