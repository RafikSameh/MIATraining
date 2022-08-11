#include<Wire.h>

int moist = A0;//moist_sensor connected to A0 pin

void setup() 
{
  Serial.begin(9600);
  pinMode(moist, INPUT);
}

void loop() 
{
  int val_moist = analogRead(moist); //read moisture reading
  val_moist=map(val_moist,0,876,0,100); //mapping moisture reading
  Serial.write(val_moist);
  delay(1000);
}
