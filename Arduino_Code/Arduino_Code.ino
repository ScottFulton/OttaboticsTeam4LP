#include <Servo.h>

// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
const int servoPin = 8;
const int motorPin1 = 8;
const int motorPin2 = 4;
const int motorPin3 = 7;
const int motorPin4 = 6;
int pos = 0;
int flag = 0;
// defines variables
long duration;
int distance = 0 ;
//initiating functions
float ultrasonic();
float sweep();
void right(int t);
void left(int t);
void forward(int t);
void back(int t);
//initiating servo
Servo myservo;
void setup() {
  // put your setup code here, to run once:
  myservo.attach(servoPin);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
}
void loop(){
  // put your main code here, to run repeatedly:
//  ultrasonic();
//  sweep();
//  //motorSystemFunc();
//  if (distance <= 10 && pos > 120)
//  {
//    left(40);
//   }
//  else if (distance <= 10 && pos < 60)
//  {
//    right(40);
//  }
  analogWrite( motorPin1, 255 );
}
float ultrasonic()
{
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  return distance;
}
float servo()
{
  for (pos = 0; pos <= 180; pos += 1) // goes from 0 degrees to 180 degrees
  {
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
    return pos;
  }
  for (pos = 180; pos >= 0; pos -= 1) // goes from 180 degrees to 0 degrees
  {
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);// waits 15ms for the servo to reach the position
    return (pos);
  }
}
void right(int t)
{
  digitalWrite( motorPin1, HIGH );
  digitalWrite(motorPin2, HIGH);
  delay(t);
  digitalWrite( motorPin1, LOW );
  digitalWrite(motorPin2, LOW);
}
void left(int t)
{
  digitalWrite( motorPin3, HIGH );
  digitalWrite(motorPin4, HIGH);
  delay(t);
  digitalWrite( motorPin3, LOW );
  digitalWrite(motorPin4, LOW);
}
void forward(int t)
{
  analogWrite( motorPin1, 255 );
  analogWrite(motorPin2, HIGH);
  delay(t);
  analogWrite( motorPin1, 0 );
  analogWrite(motorPin2, LOW);
}
