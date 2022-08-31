#include <arduino-timer.h>
//interruputs for encoders according to arduino mega datasheet
int Enc1Arm1=0;
int Enc2Arm1=3;
int Enc1Arm2=18;
int Enc2Arm2=19;
//digital pins for motor drivers
int motor1pin1=4;
int motor1pin2=5;
int motor2pin1=6;
int motor2pin2=7;
int button =8;

float angle1=0;
float angle2=0;
auto timer = timer_create_default(); //create timer with default settings
long long countARM1=0;
long long countARM2=0;

#define angle60 400         //(60/360)*2400=400
#define angle90 900         //(90/360)*2400=900

bool print_angle(void*)
{
  Serial.print("Angle of arm1 = ");
  Serial.println(angle1);
  
  Serial.print("Angle of arm2 = ");
  Serial.println(angle2);
  return true;
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Enc1Arm1,INPUT_PULLUP);
  pinMode(Enc2Arm1,INPUT_PULLUP);
  pinMode(Enc1Arm2,INPUT_PULLUP);
  pinMode(Enc2Arm2,INPUT_PULLUP);
  pinMode(button,INPUT);
  pinMode(motor1pin1,OUTPUT);
  pinMode(motor1pin2,OUTPUT);
  pinMode(motor2pin1,OUTPUT);
  pinMode(motor2pin2,OUTPUT);

  //interrupts for encoder of motor1 
  attachInterrupt(Enc1Arm1, ISR_Enc1Arm1, CHANGE);
  attachInterrupt(Enc2Arm1, ISR_Enc2Arm1, CHANGE);
  //interrupts for encoder of motor2
  attachInterrupt(Enc1Arm2, ISR_Enc1Arm2, CHANGE);
  attachInterrupt(Enc2Arm2, ISR_Enc2Arm2, CHANGE);

  timer.every(1000, print_angle);  //print angles every second

}

void loop() {
  // put your main code here, to run repeatedly:
  angle1=(countARM1/2400)*360;
  angle2=(countARM2/2400)*360;
  if(countARM1<angle60){    //rotating clockwise before reaching req. angle
    digitalWrite(motor1pin1,HIGH);
    digitalWrite(motor1pin2,LOW);
  }
  else if(countARM1>=angle60){    //when reaching the req. angle turn of motor
    digitalWrite(motor1pin1,LOW);
    digitalWrite(motor1pin2,LOW);
  }

  if(digitalRead(button)==HIGH){   //when turn on switch rotate arm2 
    if(countARM2<angle90){         //rotating clockwise before reaching req. angle
      digitalWrite(motor2pin1,HIGH);
      digitalWrite(motor2pin2,LOW);
    }
    else if(countARM2>=angle90){   //when reaching the req. angle turn of motor
      digitalWrite(motor2pin1,LOW);
      digitalWrite(motor2pin2,LOW);
    }
  }

  if(digitalRead(button)==LOW){    //when switch is off return the motor to 0 position
    if(countARM2>0){         //rotate motor in reverse direction to its 0 position
      digitalWrite(motor2pin1,LOW);
      digitalWrite(motor2pin2,HIGH);
    }
    if(countARM2==0){        //when reaching 0 position stop
      digitalWrite(motor2pin1,LOW);
      digitalWrite(motor2pin2,LOW);
    }
  }
  timer.tick();  //ticking timer
}

void ISR_Enc1Arm1()
{
  if((digitalRead(Enc1Arm1)) != (digitalRead(Enc2Arm1)))
  {
    countARM1++;
  }
  else
  {
    countARM1--;
  }
}

void ISR_Enc2Arm1()
{
  if((digitalRead(Enc1Arm1)) == (digitalRead(Enc2Arm1)))
  {
    countARM1++;
  }
  else
  {
    countARM1--;
  }
}

void ISR_Enc1Arm2()
{
  if((digitalRead(Enc1Arm2)) != (digitalRead(Enc2Arm2)))
  {
    countARM2++;
  }
  else
  {
    countARM2--;
  }
}

void ISR_Enc2Arm2()
{
  if((digitalRead(Enc1Arm2)) == (digitalRead(Enc2Arm2)))
  {
    countARM2++;
  }
  else
  {
    countARM2--;
  }
}
