/* Example code for HC-SR04 ultrasonic distance sensor with Arduino. 
   No library required. More info: https://www.makerguides.com */
#include <Servo.h>

// Define Trig and Echo pin:
#define trigPin 8
#define echoPin 9

Servo myservo;

// Define variables:
long duration;
int distance;
int angle;

void setup() {
  // Define inputs and outputs:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.attach(6);

  //Begin Serial communication at a baudrate of 9600:
  Serial.begin(9600);
}

void loop() {
  // Clear the trigPin by setting it LOW:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);

  // Trigger the sensor by setting the trigPin high for 10 microseconds:
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echoPin, pulseIn() returns the duration (length of the pulse) in microseconds:
  duration = pulseIn(echoPin, HIGH);
  // Calculate the distance:
  distance = duration * 0.034 / 2;

  // Print the distance on the Serial Monitor (Ctrl+Shift+M):
  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println(" cm");

  angle = map(distance, 0, 30, 0, 180);     // scale it for use with the servo (value between 0 and 180)
  myservo.write(angle);

  delay(50);
}