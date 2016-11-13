#include <Servo.h>

Servo hip[4];  // create servo object to control a knee and hip joints.
Servo knee[4];
Servo waist, head;
Servo middle;

byte dir_hip[4];
byte dir_knee[4];

const byte DIR_FORWARD = 1;
const byte DIR_OUTWARD = 2;
const byte DIR_INWARD = 3;
const byte DIR_BACKWARD_BEFORE_ZERO = 4;
const byte DIR_BACKWARD_AFTER_ZERO = 5;
const byte DIR_NO_MOVEMENT = 6;

const byte DIR_CREEP_BACKWARD_1 = 7;
const byte DIR_CREEP_BACKWARD_2 = 8;
const byte DIR_CREEP_BACKWARD_3 = 9;
const byte DIR_CREEP_BACKWARD_4 = 10;
const byte DIR_CREEP_BACKWARD_5 = 11;
const byte DIR_CREEP_BACKWARD_6 = 12;

const int ANGLE_LEFT_MAX_HIP_POS = 110;
const int ANGLE_LEFT_MIN_HIP_POS = 70;
const int ANGLE_RIGHT_MAX_HIP_POS = 110;
const int ANGLE_RIGHT_MIN_HIP_POS = 70;

const int ANGLE_LEFT_MAX_KNEE_POS = 90;
const int ANGLE_LEFT_MIN_KNEE_POS = 60;
const int ANGLE_RIGHT_MAX_KNEE_POS = 120;
const int ANGLE_RIGHT_MIN_KNEE_POS = 90;

const int ANGLE_ZERO_POS = 90;
 int hippose = 60;



const int ANGLE_RIGHT_TURN_MAX_HIP_POS = 105;
const int ANGLE_RIGHT_TURN_MIN_HIP_POS = 75;
const int ANGLE_RIGHT_TURN_MAX_KNEE_POS = 105;
const int ANGLE_RIGHT_TURN_MIN_KNEE_POS = 90;

const int ANGLE_LEFT_TURN_MAX_HIP_POS = 75;
const int ANGLE_LEFT_TURN_MIN_HIP_POS = 105;
const int ANGLE_LEFT_TURN_MAX_KNEE_POS = 90;
const int ANGLE_LEFT_TURN_MIN_KNEE_POS = 75;

const int ANGLE_RIGHT_CREEP_BACK_1 = 110;
const int ANGLE_RIGHT_CREEP_BACK_2 = 100;
const int ANGLE_RIGHT_CREEP_BACK_3 = 90;
const int ANGLE_RIGHT_CREEP_BACK_4 = 80;
const int ANGLE_RIGHT_CREEP_BACK_5 = 70;

const int ANGLE_LEFT_CREEP_BACK_1 = 70;
const int ANGLE_LEFT_CREEP_BACK_2 = 80;
const int ANGLE_LEFT_CREEP_BACK_3 = 90;
const int ANGLE_LEFT_CREEP_BACK_4 = 100;
const int ANGLE_LEFT_CREEP_BACK_5 = 110;

const int ANGLE_RIGHT_TURN_WAIST_POS = 60;
const int ANGLE_LEFT_TURN_WAIST_POS = 120;

const int ANGLE_TURN_MAX_HEAD_POS = 110;
const int ANGLE_TURN_MIN_HEAD_POS = 70;

const int ANGLE_WAIST_CORRECTION = -4;

int NEXT_SERVO_ANGLE[9];
int CURR_SERVO_ANGLE[9];

const byte FUN_TROT_FORWARD = 0;
const byte FUN_TROT_LEFT = 1;
const byte FUN_TROT_RIGHT = 2;
const byte FUN_TROT_BACK = 3;
const byte FUN_CREEP_FORWARD = 4;
const byte FUN_STOP_MOVING = 5;

int DELAY_INIT_TIME = 1000;
int DELAY_TIME = 500;
int DELAY_TIME_1 = 25;

byte function = -1;
byte prev_function = -1;
 
int looping = 0;

void resetCreep()
{
  hip[0].write(ANGLE_RIGHT_MAX_HIP_POS);
  CURR_SERVO_ANGLE[0] = ANGLE_RIGHT_MAX_HIP_POS;
  hip[1].write(ANGLE_LEFT_MAX_HIP_POS);
  CURR_SERVO_ANGLE[1] = ANGLE_LEFT_MAX_HIP_POS;
  hip[2].write(ANGLE_LEFT_CREEP_BACK_4);
  CURR_SERVO_ANGLE[2] = ANGLE_LEFT_CREEP_BACK_4;
  hip[3].write(ANGLE_RIGHT_CREEP_BACK_2);
  CURR_SERVO_ANGLE[3] = ANGLE_RIGHT_CREEP_BACK_2;
  knee[0].write(ANGLE_ZERO_POS);
  CURR_SERVO_ANGLE[4] = ANGLE_ZERO_POS;
  knee[1].write(ANGLE_ZERO_POS);
  CURR_SERVO_ANGLE[5] = ANGLE_ZERO_POS;
  knee[2].write(ANGLE_ZERO_POS);
  CURR_SERVO_ANGLE[6] = ANGLE_ZERO_POS;
  knee[3].write(ANGLE_ZERO_POS);
  CURR_SERVO_ANGLE[7] = ANGLE_ZERO_POS;
  waist.write(ANGLE_ZERO_POS + ANGLE_WAIST_CORRECTION);
  CURR_SERVO_ANGLE[8] = ANGLE_ZERO_POS + ANGLE_WAIST_CORRECTION;
  delay(DELAY_INIT_TIME);
}

void initialiseCreepGait() {
  resetCreep();

  dir_hip[0] = DIR_FORWARD;
  dir_hip[1] = DIR_CREEP_BACKWARD_6;
  dir_hip[2] = DIR_CREEP_BACKWARD_4;
  dir_hip[3] = DIR_CREEP_BACKWARD_2;

  dir_knee[0] = DIR_INWARD;
  dir_knee[1] = DIR_NO_MOVEMENT;
  dir_knee[2] = DIR_NO_MOVEMENT;
  dir_knee[3] = DIR_NO_MOVEMENT;
}

void setup() 
{
  hip[0].attach(4); //Pin assignment for various joints
  hip[1].attach(5);
  hip[2].attach(A3);
  hip[3].attach(11);
  
  middle.attach(6);
  knee[0].attach(2);
  knee[1].attach(7);
  knee[2].attach(A2);
  knee[3].attach(12);
  Serial.begin(9600);
  middle.write(80);
  
  initialiseCreepGait(); 
}

void loop()
{
  /*
  
  for( hippose=60 ; hippose<=120 ;)
  {
    hip[0].write(hippose);
    knee[0].write(90);
    hippose = hippose + 1 ;
    delay(50);
  }
  delay(500);
  knee[0].write(60);
  for( hippose=60 ; hippose<=120 ;)
  {
    knee[3].write(90);
    hip[3].write(hippose);
    knee[3].write(90);
    hippose = hippose + 1 ;
    delay(50);
  }
  
  delay(500);
  hip[0].write(60);
  delay(500);
  
  */
  
  
  int i;
  for (i = 0; i < 4; i++) {
    if (i == 0 || i == 3) {
      if (dir_hip[i] == DIR_FORWARD && dir_knee[i] == DIR_OUTWARD) {
  delay(50);
        dir_knee[i] = DIR_INWARD;
        NEXT_SERVO_ANGLE[i] = ANGLE_RIGHT_MAX_HIP_POS;       
        hip[i].write(ANGLE_RIGHT_MAX_HIP_POS);
        NEXT_SERVO_ANGLE[i + 4] = ANGLE_RIGHT_MIN_KNEE_POS;  
        knee[i].write(ANGLE_RIGHT_MIN_KNEE_POS);
        
  delay(50);
      } else if (dir_hip[i] == DIR_FORWARD && dir_knee[i] == DIR_INWARD) {
        dir_hip[i] = DIR_CREEP_BACKWARD_1;
        dir_knee[i] = DIR_NO_MOVEMENT;
        NEXT_SERVO_ANGLE[i] = ANGLE_RIGHT_CREEP_BACK_1;      
        hip[i].write(ANGLE_RIGHT_CREEP_BACK_1);
        NEXT_SERVO_ANGLE[i + 4] = CURR_SERVO_ANGLE[i + 4];
  delay(50);
      } else if (dir_hip[i] == DIR_CREEP_BACKWARD_1) {
        dir_hip[i] = DIR_CREEP_BACKWARD_2;
        NEXT_SERVO_ANGLE[i] = ANGLE_RIGHT_CREEP_BACK_2;      
        hip[i].write(ANGLE_RIGHT_CREEP_BACK_2);
        NEXT_SERVO_ANGLE[i + 4] = CURR_SERVO_ANGLE[i + 4];
  delay(50);
      } else if (dir_hip[i] == DIR_CREEP_BACKWARD_2) {
        dir_hip[i] = DIR_CREEP_BACKWARD_3;
        NEXT_SERVO_ANGLE[i] = ANGLE_RIGHT_CREEP_BACK_3;      
        hip[i].write(ANGLE_RIGHT_CREEP_BACK_3);
        NEXT_SERVO_ANGLE[i + 4] = CURR_SERVO_ANGLE[i + 4];
  delay(50);
      } else if (dir_hip[i] == DIR_CREEP_BACKWARD_3) {
        dir_hip[i] = DIR_CREEP_BACKWARD_4;
        NEXT_SERVO_ANGLE[i] = ANGLE_RIGHT_CREEP_BACK_4;     
        hip[i].write(ANGLE_RIGHT_CREEP_BACK_4);
        NEXT_SERVO_ANGLE[i + 4] = CURR_SERVO_ANGLE[i + 4];
  delay(50);
      } else if (dir_hip[i] == DIR_CREEP_BACKWARD_4) {
        dir_hip[i] = DIR_CREEP_BACKWARD_5;
        NEXT_SERVO_ANGLE[i] = ANGLE_RIGHT_CREEP_BACK_5;      
        hip[i].write(ANGLE_RIGHT_CREEP_BACK_5);
        NEXT_SERVO_ANGLE[i + 4] = CURR_SERVO_ANGLE[i + 4];
  delay(50);
      } else if (dir_hip[i] == DIR_CREEP_BACKWARD_5) {
        dir_hip[i] = DIR_CREEP_BACKWARD_6;
        NEXT_SERVO_ANGLE[i] = ANGLE_RIGHT_MIN_HIP_POS;       
        hip[i].write(ANGLE_RIGHT_MIN_HIP_POS);
        NEXT_SERVO_ANGLE[i + 4] = CURR_SERVO_ANGLE[i + 4];
  delay(50);
      } else if (dir_hip[i] == DIR_CREEP_BACKWARD_6) {
        dir_hip[i] = DIR_FORWARD;
        dir_knee[i] = DIR_OUTWARD;
        NEXT_SERVO_ANGLE[i] = ANGLE_ZERO_POS;                
        hip[i].write(ANGLE_ZERO_POS);
        NEXT_SERVO_ANGLE[i + 4] = ANGLE_RIGHT_MAX_KNEE_POS;  
        knee[i].write(ANGLE_RIGHT_MAX_KNEE_POS);
      }
    } else {
      delay(50);
      if (dir_hip[i] == DIR_FORWARD && dir_knee[i] == DIR_OUTWARD) {
        dir_knee[i] = DIR_INWARD;
        NEXT_SERVO_ANGLE[i] = ANGLE_LEFT_MIN_HIP_POS;        
        hip[i].write(ANGLE_LEFT_MIN_HIP_POS);
        NEXT_SERVO_ANGLE[i + 4] = ANGLE_LEFT_MAX_KNEE_POS;   
        knee[i].write(ANGLE_LEFT_MAX_KNEE_POS);
  delay(50);
      } else if (dir_hip[i] == DIR_FORWARD && dir_knee[i] == DIR_INWARD) {
        dir_hip[i] = DIR_CREEP_BACKWARD_1;
        dir_knee[i] = DIR_NO_MOVEMENT;
        NEXT_SERVO_ANGLE[i] = ANGLE_LEFT_CREEP_BACK_1;       
        hip[i].write(ANGLE_LEFT_CREEP_BACK_1);
        NEXT_SERVO_ANGLE[i + 4] = CURR_SERVO_ANGLE[i + 4];
  delay(50);
      } else if (dir_hip[i] == DIR_CREEP_BACKWARD_1) {
        dir_hip[i] = DIR_CREEP_BACKWARD_2;
        NEXT_SERVO_ANGLE[i] = ANGLE_LEFT_CREEP_BACK_2;       
        hip[i].write(ANGLE_LEFT_CREEP_BACK_2);
        NEXT_SERVO_ANGLE[i + 4] = CURR_SERVO_ANGLE[i + 4];
  delay(50);
      } else if (dir_hip[i] == DIR_CREEP_BACKWARD_2) {
        dir_hip[i] = DIR_CREEP_BACKWARD_3;
        NEXT_SERVO_ANGLE[i] = ANGLE_LEFT_CREEP_BACK_3;       
        hip[i].write(ANGLE_LEFT_CREEP_BACK_3);
        NEXT_SERVO_ANGLE[i + 4] = CURR_SERVO_ANGLE[i + 4];
  delay(50);
      } else if (dir_hip[i] == DIR_CREEP_BACKWARD_3) {
        dir_hip[i] = DIR_CREEP_BACKWARD_4;
        NEXT_SERVO_ANGLE[i] = ANGLE_LEFT_CREEP_BACK_4;       
        hip[i].write(ANGLE_LEFT_CREEP_BACK_4);
        NEXT_SERVO_ANGLE[i + 4] = CURR_SERVO_ANGLE[i + 4];
  delay(50);
      } else if (dir_hip[i] == DIR_CREEP_BACKWARD_4) {
        dir_hip[i] = DIR_CREEP_BACKWARD_5;
        NEXT_SERVO_ANGLE[i] = ANGLE_LEFT_CREEP_BACK_5;       
        hip[i].write(ANGLE_LEFT_CREEP_BACK_5);
        NEXT_SERVO_ANGLE[i + 4] = CURR_SERVO_ANGLE[i + 4];
  delay(50);
      } else if (dir_hip[i] == DIR_CREEP_BACKWARD_5) {
        dir_hip[i] = DIR_CREEP_BACKWARD_6;
        NEXT_SERVO_ANGLE[i] = ANGLE_LEFT_MAX_HIP_POS;        
        hip[i].write(ANGLE_LEFT_MAX_HIP_POS);
        NEXT_SERVO_ANGLE[i + 4] = CURR_SERVO_ANGLE[i + 4];
  delay(50);
      } else if (dir_hip[i] == DIR_CREEP_BACKWARD_6) {
        dir_hip[i] = DIR_FORWARD;
        dir_knee[i] = DIR_OUTWARD;
        NEXT_SERVO_ANGLE[i] = ANGLE_ZERO_POS;                
        hip[i].write(ANGLE_ZERO_POS);
        NEXT_SERVO_ANGLE[i + 4] = ANGLE_LEFT_MIN_KNEE_POS;   
        knee[i].write(ANGLE_LEFT_MIN_KNEE_POS);
        
  
      }
    }
  }
  //execute(); 
 
 
 
 
}

//END CREEP GAIT FUNCTIONS





