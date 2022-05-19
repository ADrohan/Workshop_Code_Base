/******************************************************************************

LilyPad Light Sensor Trigger - Automatic Night Light
SparkFun Electronics

Adapted from Digital Sandbox Experiment 11: Automatic Night Light

This example code reads the input from a LilyPad Light Sensor compares it to
a set threshold named 'dark'. If the light reading is below the threshold,
an LED will turn on.

Light Sensor connections:
   * S the signal output pin to A2 
   * - to -

Connect an LED to petal 11 
Connect an additional led to petal 6

******************************************************************************/
// The dark variable determines when we turn the LEDs on or off. 
// Set higher or lower to adjust sensitivity.
const int darkLevel = 60;

// Create a variable to hold the readings from the light sensor 
int lightValue;

// Set which analog pin the Signal output (petal marked s) from the light sensor is connected to
int sensorPin = A2;  

// Set which pin the LED is connected to. 
int ledPin = 11;
int ledPin2 = 6;

void setup()
{
    // Set sensorPin as an INPUT
    pinMode(sensorPin, INPUT);

    // Set LEDs as outputs
    pinMode(ledPin, OUTPUT);
    pinMode(ledPin2, OUTPUT);

    // Initialize Serial, set the baud rate to 9600 bps.
    Serial.begin(9600);
}

void loop()
{
    // Read the light sensor's value and store in 'lightValue'
    lightValue = analogRead(sensorPin);

    // Print some descriptive text and then the value from the sensor
    Serial.print("Light value is:");
    Serial.println(lightValue);

    // Compare "lightValue" to the "dark" variable
    if (lightValue <= darkLevel) // If the reading is less then 'darkLevel'
    {
     
        analogWrite(ledPin, 64); // Turn LED on at quarter brightness analogWrite can take values between 0 to 255
        digitalWrite(ledPin2, HIGH); // Digital write this led high  
    }
    else // Otherwise, if "lightValue" is greater than "dark"
    {    
         analogWrite(ledPin, 0);  // Turn off LED
         digitalWrite(ledPin2, 0);  // Turn off LED
    }

    // Delay 1/10th of a second before looping over again
    // This delay ensures that the text doesn't scroll too fast on the Serial Monitor. 
    // Adjust to a larger number for a slower scroll and less sensor readings
    delay(100);  
}
