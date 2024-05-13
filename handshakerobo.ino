
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
int pos1 = 150;  
int pos2 = 10;    
int HandShake = 50;    
//int pos3 = 0;    

int trigPin = 8;      // trig pin of HC-SR04

int echoPin = 12;     // Echo pin of HC-SR04

long duration, distance;


void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);         // set trig pin as output
  pinMode(echoPin, INPUT);          //set echo pin as input to capture reflected waves

 myservo.attach(7);  // attaches the servo on pin 9 to the servo object
}


void loop() {


  digitalWrite(trigPin, LOW);

  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);     // send waves for 10 us

  delayMicroseconds(10);

  duration = pulseIn(echoPin, HIGH); // receive reflected waves

  distance = duration / 58.2;   // convert to distance
  Serial.println("distance: ");

  Serial.println(distance);

  delay(10);

  if (distance <= 30) {
    myservo.write(HandShake);
    delay(5000);
  }
  else  {
    myservo.write(pos1);
//  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    //myservo.write(pos);              // tell servo to go to position in variable 'pos'
    //delay(15);
}}
