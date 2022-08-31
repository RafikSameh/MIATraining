#include <Wire.h>
#define IMU_ADD 0x68

int16_t AcX,AcY,AcZ;

int minVal=265;
int maxVal=402;

double x;
double y;
double z;


void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Wire.beginTransmission(IMU_ADD);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.beginTransmission(IMU_ADD);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(IMU_ADD,6,true);

  while(Wire.available()<6);
  AcX=Wire.read()<<8|Wire.read();
  AcY=Wire.read()<<8|Wire.read();
  AcZ=Wire.read()<<8|Wire.read();
    int xAng = map(AcX,minVal,maxVal,-90,90);
    int yAng = map(AcY,minVal,maxVal,-90,90);
    int zAng = map(AcZ,minVal,maxVal,-90,90);

       x= RAD_TO_DEG * (atan2(-yAng, -zAng)+PI);
       y= RAD_TO_DEG * (atan2(-xAng, -zAng)+PI);
       z= RAD_TO_DEG * (atan2(-yAng, -xAng)+PI);

     Serial.print("AngleZ= ");
     Serial.println(z);
     delay(200);
     
}
