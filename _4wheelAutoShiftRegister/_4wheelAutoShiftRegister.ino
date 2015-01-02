#include <Servo.h>

//***Globals and constants***
//Needs to be on pulse width module input
const int EN2 = 5; //Front Right Tire
const int EN1 = 3; //Back Right Tire
const int EN3 = 9; //Front Left Tire
const int EN4 = 10; //Back Left Tire

//Shift Register pin values
const int SER = 11;
const int LATCH = 12;
const int CLK = 13;

//Servo Pin
const int SERVO = 6;
Servo myServo;

//PING Pin
const int pingPin = 7;
long duration, cm;

// ***Helper Methods***
//Set all 4 tires to stopped
void fullStop()
{
  //Set to Write to H-Bridge
  digitalWrite(EN2, LOW);
  digitalWrite(EN1, LOW);
  digitalWrite(EN3, LOW);
  digitalWrite(EN4, LOW);
 
  //Set Latch to low to write, send all lows to stop
  //Then set Latch to High to push values
  digitalWrite(LATCH,LOW);
  shiftOut(SER, CLK, MSBFIRST, B00000000);
  digitalWrite(LATCH,HIGH);
 
  digitalWrite(EN2, HIGH); 
  digitalWrite(EN1, HIGH);
  digitalWrite(EN3, HIGH); 
  digitalWrite(EN4, HIGH); 
}

//Go straight ahead full force
void fullForward()
{
  digitalWrite(EN2, LOW);
  digitalWrite(EN1, LOW);
  digitalWrite(EN3, LOW);
  digitalWrite(EN4, LOW);
   
  //Set Latch to low to write, send alternating
  //high then low to drive straight ahead
  //Then set Latch to High to push values
  digitalWrite(LATCH,LOW);
  shiftOut(SER, CLK, MSBFIRST, B10101010);
  digitalWrite(LATCH,HIGH);
  
  analogWrite(EN2, 255);
  analogWrite(EN1, 255);
  analogWrite(EN3, 255);
  analogWrite(EN4, 255);
}

//Go in reverse full force
void fullReverse()
{
  digitalWrite(EN2, LOW);
  digitalWrite(EN1, LOW);
  digitalWrite(EN3, LOW);
  digitalWrite(EN4, LOW);
   
  //Set Latch to low to write, send alternating
  //low then high to drive in reverse
  //Then set Latch to High to push values
  digitalWrite(LATCH,LOW);
  shiftOut(SER, CLK, MSBFIRST, B01010101);
  digitalWrite(LATCH,HIGH);
  
  analogWrite(EN2, 255);
  analogWrite(EN1, 255);
  analogWrite(EN3, 255);
  analogWrite(EN4, 255);
}

//Turn Left about 90%
void left()
{
  digitalWrite(EN2, LOW);
  digitalWrite(EN1, LOW);
  digitalWrite(EN3, LOW);
  digitalWrite(EN4, LOW);
   
  //Set Latch to low to write, send alternating
  //low then high to right side to drive reverse
  //and high to low left side to drive forward and turn
  //Then set Latch to High to push values
  digitalWrite(LATCH,LOW);
  shiftOut(SER, CLK, MSBFIRST, B01011010);
  digitalWrite(LATCH,HIGH);
  
  analogWrite(EN1, 255);
  analogWrite(EN2, 255);
  analogWrite(EN3, 255);
  analogWrite(EN4, 255);
}

//Turn Right about 90%
void right()
{
  digitalWrite(EN2, LOW);
  digitalWrite(EN1, LOW);
  digitalWrite(EN3, LOW);
  digitalWrite(EN4, LOW);
  
  //Set Latch to low to write, send alternating
  //high then low to right side to drive forward
  //and low to high left side to drive reverse and turn
  //Then set Latch to High to push values 
  digitalWrite(LATCH,LOW);
  shiftOut(SER, CLK, MSBFIRST, B10100101);
  digitalWrite(LATCH,HIGH);
  
  analogWrite(EN2, 255);
  analogWrite(EN1, 255);
  analogWrite(EN3, 255);
  analogWrite(EN4, 255);
}

//Using PING arduino helper methods to get distance
long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

//***Setup and Loop Code ***
void setup()
{
  pinMode(EN1, OUTPUT);
  pinMode(EN2, OUTPUT);
  pinMode(EN3, OUTPUT);
  pinMode(EN4, OUTPUT);
  
  //Pins for the shift register
  pinMode(SER, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLK, OUTPUT);
  //fullStop();
  
  //Attach the servo motor to the pin
  myServo.attach(SERVO);
  Serial.begin(9600);
}

void loop()
{
  /*left();
  delay(500);
  fullStop();
  delay(500);
  right();
  delay(500);
  fullStop();
  delay(500);*/
  
  /*
  //Servo Movement Practice
  myServo.write(0);
  delay(1000);
  myServo.write(45);
  delay(1000);
  myServo.write(90);
  delay(1000);
  myServo.write(135);
  delay(1000);
  myServo.write(179);
  delay(500);*/
  
  //PING Ultrasonic Sensor test
  //Ping out
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  
  //Read the Ping
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);
  cm = microsecondsToCentimeters(duration);
  Serial.print(cm);
  Serial.println("cm");
}
