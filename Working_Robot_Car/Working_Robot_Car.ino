#include <AFMotor.h>

// Define Trig and Echo pin:
#define trigPin 10
#define echoPin 9

AF_DCMotor motor1(3, MOTOR12_64KHZ); // create motor #1, 64KHz pwm
AF_DCMotor motor2(4, MOTOR12_64KHZ); // create motor #2, 64KHz pwm

// Define variables:
long duration;
int distance;

void setup() {
  // Define inputs and outputs:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600); // set up Serial library at 9600 bps
  Serial.println("Motor test!");

  motor1.setSpeed(200);
  motor2.setSpeed(200);
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

  if (distance < 20) {
    motor1.run(RELEASE);
    motor2.run(RELEASE);
  }
  else {
    motor1.run(FORWARD);
    motor2.run(FORWARD);
  }

  delay(100);
}