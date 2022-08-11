#include<Wire.h>
int temp=A0;
int x=0;
void setup()
{
  pinMode(temp,INPUT);
  Wire.begin(10); //address 10
  Wire.onRequest(requestEvent);
  Serial.begin(9600);
}

void loop()
{
  
  x=analogRead(temp); //read temp
  x=map(x,20,358,0,100); //mapping temp
  Serial.println(x);
  delay(1000);
  
}
void requestEvent ()
{
  Wire.write(x); //send x 
}
