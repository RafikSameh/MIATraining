#include<Wire.h>

int motorpin1 = 5;//motor connected to pin 5
int motorpin2=6;
int enable=11;
int y = 0;//variable to get the reading from moist_sensor
int speed=255; //speed of motor

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  pinMode(motorpin1, OUTPUT);
  pinMode(motorpin2,OUTPUT);//another pin to control the direction of the motor
  pinMode(enable,OUTPUT);//control the motor speed
}

void loop()
{
  first : Wire.requestFrom(10,1);//getting data from temp sensor which adress 10
  while(Wire.available()){
  int x = Wire.read();
  Serial.println(x);//displaying it on the serial monitor
  //checking conditions  (20c=35, 40c=49)
  if (x>49) //clockwise
    {
      analogWrite(enable,speed);
      digitalWrite(motorpin1,LOW);
      digitalWrite(motorpin2,HIGH);
    }
    else if (x>=35&&x<=49) //stop
    {
       analogWrite(enable,0);
      digitalWrite(motorpin1,LOW);
      digitalWrite(motorpin2,LOW);
    }
    else if (x<35) //anti-clockwise
    {
      analogWrite(enable,speed);
      digitalWrite(motorpin1,HIGH);
      digitalWrite(motorpin2,LOW);
    }
  delay(500);}
  while(Serial.available())//checking if there's data from moisture sensor
  {
    y = Serial.read();
    Serial.println(y);//displaying it on the serial monitor
    goto first;
    delay(500);
  }
  
}
