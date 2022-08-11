int mois_sensor =A0 ; //moisture sensor to A0
int force_sensor=A1;  //force sensor to A1
int counter_interrupt = 2; //counter button
int refill_button=3; // button the start the motor to refill the tank
int ledPin =9;
int water_motor=7;
int refill_motor=8;
int counter=0;  //variable that counts the number of refillings
int val_water_motor=0;  //to get the value of water motor
unsigned int time = 0;  //gets time


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(counter_interrupt,INPUT_PULLUP);
  pinMode(refill_button,INPUT);
  pinMode(mois_sensor,INPUT);
  pinMode(force_sensor,INPUT);
  pinMode(ledPin,OUTPUT);
  pinMode(water_motor,OUTPUT);
  pinMode(refill_motor,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(counter_interrupt),count,RISING); //for counting
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int val_moist = analogRead(mois_sensor);  //read the moisture sensor reading
  int val_force = analogRead(force_sensor); //read the force sensor reading
  int val_LED = map(val_force,0,1023,255,0); // mapping force to Led brightness
  int val_water_motor = map(val_moist,0,876,255,0); //mapping the moisture sensor to speed of water motor
  Serial.println(counter); //display counter

  digitalWrite(refill_motor ,LOW); //default motor state is low
  if(digitalRead(refill_button) ==HIGH){
    time=millis();
    while (millis()<(time+10000)){  //to count 10 seconds from starting then stop
      digitalWrite(refill_motor,HIGH);
    }
  }
  analogWrite(water_motor,val_water_motor);  
  analogWrite(ledPin,val_LED);
}
void count(){
  counter++;
}
