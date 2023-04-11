#include<Arduino.h>
int P,Q;
int C,R;
void assign(int C,int R)
{
digitalWrite(3,R);
digitalWrite(2,C);
}
void setup()
{
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(5,INPUT);
pinMode(6,INPUT);
}

void loop()
{
P=digitalRead(5);
Q=digitalRead(6);
C=((!P)^(!Q));
R=(P^Q);
assign(C,R);
}
