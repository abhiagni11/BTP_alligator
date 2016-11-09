#include <Servo.h>

Servo hip1;  // create servo object to control a knee and hip joints.
Servo hip2;
Servo hip3;
Servo hip4;
Servo knee1;
Servo knee2;
Servo knee3;
Servo knee4;
//Servo tail1;
Servo middle;
Servo head;
//Servo tail2;

int pos=0;
int hipPoss=120;  // variables to control input angles
int hipPosinvs=90;
int hipPosf=120;  // variables to control input angles
int hipPosinvf=90;
double angles = 15;

float k1 = 0.1;
float k2 = 0.2;
int delaytime = 30;
int amp=30;

int lastCommand;
int command=0;
int ori = 0, lastori = 0;
char CHAR = 'y';
float cycle=0;
void setup()
{
    
    knee1.attach(2);
    knee2.attach(7);
    hip1.attach(4);
    hip2.attach(5);
    middle.attach(6);
    head.attach(3);
    
    hip3.attach(A3);
    hip4.attach(11);
    knee3.attach(A2);
    knee4.attach(12);
    //tail1.attach(A4);
    //tail2.attach(A5);

    middle.write(90);
    head.write(120);
    //tail1.write(75);
    //tail2.write(60);
    
    knee1.write(90);
    knee2.write(90);
    knee3.write(90);
    knee4.write(90);
    hip1.write(60);
    hip2.write(75);
    hip3.write(120);
    hip4.write(105); 
    //tail1.write(60);
    //tail2.write(60);
    Serial.begin(9600);
    delay(50);
}

void loop()
{	
	while (Serial.available()>0)
	{
	cycle=0;
	Serial.println(cycle);
	Serial.flush();
    	CHAR = (char)Serial.read();
	Serial.end();    // Ends the serial communication once all data is received
     	Serial.begin(9600); 
	//if ((CHAR == 'x')){ori = lastori;}
	//else if (CHAR != 'x'){	
	ori = CHAR-'j';
	ori = ori*3;
	lastori = ori;

	//Serial.print("CHAR is : ");
	//Serial.println(CHAR);
	//Serial.print("ori is : ");
	//Serial.println(ori);
	//Serial.print("lastori is : ");
	//Serial.println(lastori);
    	angles = amp;
	k1 = amp*4;
	k1 = k1/90;
	//FORWARD
    delay(delaytime);
    knee1.write(115);
    knee4.write(80);
    knee2.write(100);
    knee3.write(60);
//cycle1
	//Serial.print("cycle111111111111111111111111111111111");
    hipPosf = 75;
    for(hipPoss = 60; hipPoss <= 120; hipPoss +=2)
    {
        hipPosinvs=180-hipPoss;
        hipPosinvf=180-hipPosf;
       
        hip1.write(hipPoss);      //Move forward
        hip3.write(hipPosinvs);   //Move forward
        hip2.write(hipPosf);      //Move backward
        hip4.write(hipPosinvf);   //Move backward   
        
        angles = angles - k1;
        
        head.write(90 - angles); 
        middle.write(80 - ori - angles);
        //tail1.write(90 - angles);
        //tail2.write(90 - angles);  
        
        hipPosf +=1;
        delay(delaytime );	
	cycle =cycle+4;
	Serial.println(cycle);
    }
    knee1.write(75);
    knee4.write(80);
    knee2.write(100);
    knee3.write(100);
//cycle2
	//Serial.print("cycle22222222222222222222222222222222");
    for(; hipPoss >= 105; hipPoss -=1)
    {
        hipPosinvs=180-hipPoss;
        hipPosinvf=180-hipPosf;
       
        hip1.write(hipPoss); //Move backward
        hip3.write(hipPosinvs);   //Move backward
        hip2.write(hipPosf);   //Move backward
        hip4.write(hipPosinvf);   //Move backward  
        
        head.write(90 - angles); 
        middle.write(80 - ori - angles);
        //tail1.write(90 - angles);
        //tail2.write(90 - angles);

        angles = angles - k1;   
              
        hipPosf +=1;
        delay(delaytime );
	cycle =cycle+3;
	Serial.println(cycle);
    }
    knee1.write(75);
    knee4.write(120);
    knee2.write(60);
    knee3.write(100);

//cycle3
	//Serial.print("cycle33333333333333333333333333333333333333333333333333");
    for(; hipPoss >=75; hipPoss -=1)
    {
        hipPosinvs=180-hipPoss;
        hipPosinvf=180-hipPosf;
       
        hip1.write(hipPoss); //Move forward
        hip3.write(hipPosinvs);   //Move forward
        hip2.write(hipPosf);   //Move backward
        hip4.write(hipPosinvf);   //Move backward   
        
        head.write(90 - angles); 
        middle.write(80 - ori  - angles );
        //tail1.write(90 - angles);
        //tail2.write(90 - angles);
        angles = angles + k1;

        hipPosf -=2;
        delay(delaytime );
	cycle =cycle+4;
	Serial.println(cycle);
    }
    knee1.write(75);
    knee4.write(80);
    knee2.write(100);
    knee3.write(100);  
    
//cycle4
	//Serial.print("cycle4444444444444444444444444444444444444444444444444");
        for(; hipPoss >= 60; hipPoss -=1)
        {
        hipPosinvs=180-hipPoss;
        hipPosinvf=180-hipPosf;
       
        hip1.write(hipPoss); //Move backward
        hip3.write(hipPosinvs);   //Move backward
        hip2.write(hipPosf);   //Move backward
        hip4.write(hipPosinvf);   //Move backward  
        
        head.write(90 - angles); 
        middle.write(80 - ori  - angles);
        //tail1.write(90 - angles);
        //tail2.write(90 - angles);
        angles = angles + k1;
        delay(delaytime );
              
        hipPosf +=1;
	cycle =cycle+4;
	Serial.println(cycle);
    
	}
//Serial.println('f');


}
}

  
