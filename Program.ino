// for driving 'D'
#define FD 19
#define BD 20
#define LD 21
#define RD 22

// for arm 'A'
#define AU 23
#define AD 24
#define AO 25
#define AC 26

// for driving
#define m11 8     // left motor
#define m12 9     // left motor
#define m21 10    // right motor
#define m22 11    // right motor

// for arm
#define m31 12    // for up-down
#define m32 13    // for up-down
#define m41 14    // for open-close
#define m42 15    // for open-close

// for ultrasonic sensor
#define trig 1    // trigger pin
#define echo 2    // echo pin

// variables for measuring distance
long duration, distance;

void forward_drive()
{
   digitalWrite(m11, HIGH);
   digitalWrite(m12, LOW);
   digitalWrite(m21, HIGH);
   digitalWrite(m22, LOW);
}

void backward_drive()
{
   digitalWrite(m11, LOW);
   digitalWrite(m12, HIGH);
   digitalWrite(m21, LOW);
   digitalWrite(m22, HIGH); 
}

void left_drive()
{
   digitalWrite(m11, LOW);
   digitalWrite(m12, HIGH);
   digitalWrite(m21, HIGH);
   digitalWrite(m22, LOW);
}

void right_drive()
{
   digitalWrite(m11, HIGH);
   digitalWrite(m12, LOW);
   digitalWrite(m21, LOW);
   digitalWrite(m22, HIGH);
}

void Stop_driving()
{
   digitalWrite(m11, LOW);
   digitalWrite(m12, LOW);
   digitalWrite(m21, LOW);
   digitalWrite(m22, LOW);
}

void arm_up()
{
   digitalWrite(m31, HIGH);
   digitalWrite(m32, LOW);
   digitalWrite(m41, LOW);
   digitalWrite(m42, LOW); 
}

void arm_down()
{
   digitalWrite(m31, LOW);
   digitalWrite(m32, HIGH);
   digitalWrite(m41, LOW);
   digitalWrite(m42, LOW); 
}

void arm_open()
{
   digitalWrite(m31, LOW);
   digitalWrite(m32, LOW);
   digitalWrite(m41, HIGH);
   digitalWrite(m42, LOW); 
}

void arm_close()
{
   digitalWrite(m31, LOW);
   digitalWrite(m32, LOW);
   digitalWrite(m41, LOW);
   digitalWrite(m42, HIGH); 
}

void arm_stable()
{
   digitalWrite(m31, LOW);
   digitalWrite(m32, LOW);
   digitalWrite(m41, LOW);
   digitalWrite(m42, LOW); 
}

void setup() 
{
  pinMode(FD, INPUT);
  pinMode(BD, INPUT);
  pinMode(LD, INPUT);
  pinMode(RD, INPUT);
  pinMode(AU, INPUT);
  pinMode(AD, INPUT);
  pinMode(AO, INPUT);
  pinMode(AC, INPUT);

  pinMode(m11, OUTPUT);
  pinMode(m12, OUTPUT);
  pinMode(m21, OUTPUT);
  pinMode(m22, OUTPUT);
  pinMode(m31, OUTPUT);
  pinMode(m32, OUTPUT);
  pinMode(m41, OUTPUT);
  pinMode(m42, OUTPUT);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() 
{
  int temp1=digitalRead(FD);
  int temp2=digitalRead(BD);
  int temp3=digitalRead(LD);
  int temp4=digitalRead(RD);
  int temp5=digitalRead(AU);
  int temp6=digitalRead(AD);
  int temp7=digitalRead(AO);
  int temp8=digitalRead(AC);

  digitalWrite(trig, LOW);    // starting with a LOW pulse beforehand to ensure a clean HIGH pulse
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);   // sending waves for 10 us
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);   // receive reflected waves
  distance = duration/58.3;   // converting to distance
  delay(10);

  if (distance >= 19)
  {
    if(temp1==1 && temp2==0 && temp3==0 && temp4==0)
      forward_drive();
  
    else if(temp1==0 && temp2==1 && temp3==0 && temp4==0)
      backward_drive();
  
    else if(temp1==0 && temp2==0 && temp3==1 && temp4==0)
      left_drive();
  
    else if(temp1==0 && temp2==0 && temp3==0 && temp4==1)
      right_drive();
  
    else if(temp1==0 && temp2==0 && temp3==0 && temp4==0)
      Stop_driving();
  }
  else if (distance < 18)
  {
    Stop_driving();
    delay(500);
    backward_drive();
    delay(500);
    Stop_driving();
    delay(100);
    left_drive();
    delay(500);
  }
  if(temp5==1 && temp6==0 && temp7==0 && temp8==0)
    arm_up();

  else if(temp5==0 && temp6==1 && temp7==0 && temp8==0)
    arm_down();

  else if(temp5==0 && temp6==0 && temp7==1 && temp8==0)
    arm_open();

  else if(temp5==0 && temp6==0 && temp7==0 && temp8==1)
    arm_close();

  else if(temp5==0 && temp6==0 && temp7==0 && temp8==0)
  arm_stable();
}
