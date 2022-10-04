// This is a line follower.
// It is made of 2 IR-sensor modules, L293D is used as a motor driver, 2 T-gear motors are used with a
// 9V battery and arduino uno is used. 
// The motor 1 has the inputs 1,2 and is on the right side of the chassey.
// The motor 2 has inputs 2,3 and is on the left side of the chassey.
// The sensor ir1 is on the right side f the chassey and the sensor ir2 is on the left side of the chassey.
// Black indicates 0, white is 1.
int in1 = 4;
int in2 = 7;
int in3 = 2;
int in4 = 3;
int ena = 6;
int enb = 5;
int irs1 = 8;
int irs2 = 9;
int ir1;
int ir2;


void setup(){
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(ena,OUTPUT);
  pinMode(enb,OUTPUT);
  pinMode(ir1,INPUT);
  pinMode(ir2,INPUT);
  Serial.begin(9600);
}

void loop(){
  logic();
}
void logic(){
  ir1 = digitalRead(irs1);
  ir2 = digitalRead(irs2);
  Serial.print("Sensor 1 : ");
  Serial.println(ir1);
  Serial.print("Sensor 2 : ");
  Serial.println(ir2);
  if(ir1==ir2){
    forward();
  }
  else if(ir1!=ir2 && ir1==1 && ir2==0){
    stop();
    left();
  }
  else if(ir1!=ir2 && ir1==0 && ir2==1){
    stop();
    right();
  }
}
void forward(){
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  analogWrite(ena,220);
  analogWrite(enb,220);
}


void left(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  analogWrite(ena,200);
  analogWrite(enb,150);
  delay(100);
}
void right(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  analogWrite(ena,150);
  analogWrite(enb,200);
  delay(100);
}
void stop(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  analogWrite(ena,0);
  analogWrite(enb,0);
}
