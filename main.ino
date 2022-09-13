// C++ code
//
#define MAX 50
#define CM 29.1
const int echo = 10;
const int trig = 11;
const int R = 7;
const int P = 6;
const int D = 5;
char gear;
int distance,cm;
void setup()
{
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo , INPUT);
  pinMode(13 , OUTPUT);
  pinMode(R , OUTPUT);
  pinMode(P , OUTPUT);
  pinMode(D , OUTPUT);
  
}

void loop()
{
  	digitalWrite(R,LOW);
  	digitalWrite(P,LOW);
  	digitalWrite(D,LOW);
  	if (Serial.available() > 0)
      	gear = Serial.read();
  
  	switch(gear)
    {
      	case 'R':
      		digitalWrite(R,HIGH);
      		break;
      	case 'P':
      		digitalWrite(P,HIGH);
      		break;
      	case 'D':
      		digitalWrite(D,HIGH);
      		break;
      	default:
      		break;
    }
    digitalWrite(trig , LOW);
    delay(5);
    digitalWrite(trig , HIGH);    
    delay(10);
    digitalWrite(trig , LOW);
  
  	distance = pulseIn(echo,HIGH);
  	cm = (distance/2)/CM;
  	Serial.println(cm);
  	if(cm <= MAX)
      digitalWrite(13,HIGH);
  	else
      digitalWrite(13,LOW);
}