//***Globals and constants***
//Needs to be on pulse width module input
const int EN2 = 5; //Front Right Tire
const int EN1 = 3; //Back Right Tire
const int EN3 = 9; //Front Left Tire
const int EN4 = 10; //Back Left Tire

//Is only digital input
const int MCL1 = 2; //Front Right Tire Set
const int MCL2 = 7;

const int MCL3 = 4; //Back Right Tire Set
const int MCL4 = 6;

const int MCR1 = 12; //Front Left Tire Set
const int MCR2 = 13;

const int MCR3 = 11; //Back Left Tire Set
const int MCR4 = 8;


// ***Helper Methods***
//Set all 4 tires to stopped
void fullStop()
{
 digitalWrite(EN1, LOW);
 digitalWrite(MCL1, LOW);
 digitalWrite(MCL2, LOW);
 digitalWrite(EN1, HIGH); 
 
 digitalWrite(EN2, LOW);
 digitalWrite(MCL3, LOW);
 digitalWrite(MCL4, LOW);
 digitalWrite(EN2, HIGH);

 digitalWrite(EN3, LOW);
 digitalWrite(MCR1, LOW);
 digitalWrite(MCR2, LOW);
 digitalWrite(EN3, HIGH); 

 digitalWrite(EN4, LOW);
 digitalWrite(MCR1, LOW);
 digitalWrite(MCR2, LOW);
 digitalWrite(EN4, HIGH);  
}

//Go straight ahead full force
void fullForward()
{
  digitalWrite(EN1, LOW);
  digitalWrite(MCL1, HIGH);
  digitalWrite(MCL2, LOW);
  analogWrite(EN1, 255);
  
  digitalWrite(EN2, LOW);
  digitalWrite(MCL3, HIGH);
  digitalWrite(MCL4, LOW);
  analogWrite(EN2, 255);
  
  digitalWrite(EN3, LOW);
  digitalWrite(MCR1, HIGH);
  digitalWrite(MCR2, LOW);
  analogWrite(EN3, 255);
  
  digitalWrite(EN4, LOW);
  digitalWrite(MCR1, HIGH);
  digitalWrite(MCR2, LOW);
  analogWrite(EN4, 255);
}

//Go in reverse full force
void fullReverse()
{
  digitalWrite(EN1, LOW);
  digitalWrite(MCL1, LOW);
  digitalWrite(MCL2, HIGH);
  analogWrite(EN1, 255);
  
  digitalWrite(EN2, LOW);
  digitalWrite(MCL3, LOW);
  digitalWrite(MCL4, HIGH);
  analogWrite(EN2, 255);
  
  digitalWrite(EN3, LOW);
  digitalWrite(MCR1, LOW);
  digitalWrite(MCR2, HIGH);
  analogWrite(EN3, 255);
  
  digitalWrite(EN4, LOW);
  digitalWrite(MCR1, LOW);
  digitalWrite(MCR2, HIGH);
  analogWrite(EN4, 255);
}

//***Setup and Loop Code ***
void setup()
{
  pinMode(EN1, OUTPUT);
  pinMode(MCL1, OUTPUT);
  pinMode(MCL2, OUTPUT);
  
  pinMode(EN2, OUTPUT);
  pinMode(MCL3, OUTPUT);
  pinMode(MCL4, OUTPUT);
  
  pinMode(EN3, OUTPUT);
  pinMode(MCR1, OUTPUT);
  pinMode(MCR2, OUTPUT);
  
  pinMode(EN4, OUTPUT);
  pinMode(MCR1, OUTPUT);
  pinMode(MCR2, OUTPUT);
  fullStop();
}

void loop()
{
  
}
