// Simple Arduino program covering basic concepts

// Include necessary libraries
#include <Arduino.h>
#include <Servo.h>

// Define constants
const int ledPin = 13;
const int buttonPin = 2;
const int servoPin = 9;

// Create a Servo object
Servo myservo;

// Variables
int buttonState = 0;
int angle = 0;

void setup() {
  // Initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);

  // Initialize the button pin as an input
  pinMode(buttonPin, INPUT);

  // Attach the servo to its pin
  myservo.attach(servoPin);

  // Serial communication setup (for debugging)
  Serial.begin(9600);
}

void loop() {
  // Digital I/O: Turn the LED on and off
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);

  // Analog I/O: Read analog value from a sensor (e.g., potentiometer)
  int sensorValue = analogRead(A0);
  Serial.print("Analog Sensor Value: ");
  Serial.println(sensorValue);

  // Control structures: Use a button to control servo motor
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    angle += 10;
    if (angle > 180) {
      angle = 0;
    }
    myservo.write(angle);
    delay(100);
  }

  // Functions: Custom function to blink the LED
  blinkLED(ledPin, 3, 500);

  // Conditional statements: Check the state of a sensor and take action
  if (sensorValue > 512) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}

// Custom function to blink an LED a specified number of times with a given delay
void blinkLED(int pin, int count, int delayTime) {
  for (int i = 0; i < count; i++) {
    digitalWrite(pin, HIGH);
    delay(delayTime);
    digitalWrite(pin, LOW);
    delay(delayTime);
  }
}
