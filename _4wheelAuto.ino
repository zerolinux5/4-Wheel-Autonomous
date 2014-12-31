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
