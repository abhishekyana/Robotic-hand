/*
Author: Abhishek Yanamandra
Connections:
Arduino Pins -> Robot hand Servo Data line
Pin 2 -> Little Finger Servo
Pin 3 -> Ring Finger Servo
Pin 4 -> Middle Finger Servo
Pin 5 -> Index Finger Servo
Pin 6 -> Thumb Finger Servo

5V and Gnd for servos is given from external power supply. Any smartphone charger would work.
Connect Gnd common for external supply and Arduino.

*/
#include <Servo.h>

Servo finger[5];  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int wave_delay=10;
char statess[10];
String data="";
void setup() {
  for(int i=2; i<=6; i++)
  {
    finger[i-2].attach(i);
  }
  Serial.begin(115200);
  Serial.println("Serial Initialization Done");
}
/*
 * Finger[0] is Litte(0)  finger: Close=0   and Open=180
 * Finger[1] is Ring(1)   finger: Close=180 and Open=30
 * Finger[2] is Middle(2) finger: Close=0   and Open=180
 * Finger[3] is Index(3)  finger: Close=180 and Open=0
 * Finger[4] is Thumb(4)  finger: Close=180   and Open=0
 */

void all_open()
{
  finger[0].write(180);
  finger[1].write(30);
  finger[2].write(180);
  finger[3].write(0);
  finger[4].write(0);
}

void all_close()
{
  finger[0].write(0);
  finger[1].write(180);
  finger[2].write(0);
  finger[3].write(180);
  finger[4].write(180);
}

int wave_close(int d=500)
{
  finger[0].write(0);
  delay(d);
  finger[1].write(180);
  delay(d);
  finger[2].write(0);
  delay(d);
  finger[3].write(180);
  delay(d);
  finger[4].write(180); 
  delay(d);
}

int wave_open(int d=500)
{
  finger[0].write(180);
  delay(d);
  finger[1].write(30);
  delay(d);
  finger[2].write(180);
  delay(d);
  finger[3].write(0);
  delay(d);
  finger[4].write(0);  
  delay(d);
}

void make_finger(String fingeris, String finger_status)
{
  if(fingeris=="thumb")
  {
    if(finger_status=="o"){finger[4].write(0);}
    else if(finger_status=="c"){finger[4].write(180);}
    }
    
  if(fingeris=="index")
  {
    if(finger_status=="o"){finger[3].write(0);}
    else if(finger_status=="c"){finger[3].write(180);}
    }
    
  if(fingeris=="middle")
  {
    if(finger_status=="o"){finger[2].write(180);}
    else if(finger_status=="c"){finger[2].write(0);}
    }
    
    if(fingeris=="ring")
  {
    if(finger_status=="o"){finger[1].write(30);}
    else if(finger_status=="c"){finger[1].write(180);}
    }
    if(fingeris=="little")
  {
    if(finger_status=="o"){finger[0].write(180);}
    else if(finger_status=="c"){finger[0].write(0);}
    }
if(fingeris=="all")
  {
    if(finger_status=="o"){all_open();}
    else if(finger_status=="c"){all_close();}
    }
}
void make_finger_symbol(int fingeris, char finger_status)
{
  if(fingeris==4)
  {
    if(finger_status=='o'){finger[4].write(0);}
    else if(finger_status=='c'){finger[4].write(180);}
    }
    
  if(fingeris==3)
  {
    if(finger_status=='o'){finger[3].write(0);}
    else if(finger_status=='c'){finger[3].write(180);}
    }
    
  if(fingeris==2)
  {
    if(finger_status=='o'){finger[2].write(180);}
    else if(finger_status=='c'){finger[2].write(0);}
    }
    
    if(fingeris==1)
  {
    if(finger_status=='o'){finger[1].write(30);}
    else if(finger_status=='c'){finger[1].write(180);}
    }
    if(fingeris==0)
  {
    if(finger_status=='o'){finger[0].write(180);}
    else if(finger_status=='c'){finger[0].write(0);}
    }
if(fingeris==5)
  {
    if(finger_status=='o'){all_open();}
    else if(finger_status=='c'){all_close();}
    }
}

void bye_bye()
{
  all_open();
  delay(500);
  all_close();
  delay(500);
  all_open();
  delay(500);
  all_close();
  delay(500);
  all_open();
  delay(500);
  all_close();
  delay(500);
}
void hand_model(String states)
{
  states.toCharArray(statess,10);
  for(int i=0;i<=5;i++)
  {
    Serial.println(statess[i]);
    make_finger_symbol(i,statess[i]);
  }
}
void loop() 
{
  if(Serial.available())
  {
    data = Serial.readString();
    if(data[1]=='b'){bye_bye();}
    else{hand_model(data);}
  }
  //Uncomment to see amazing actions
//  //hand_model("occoo");
//  //wave_open();
//  //delay(600);
//  //hand_model("ccccc");
//  //wave_close();
//  //delay(600);
//hand_model("ooooo");
//delay(1000);
//hand_model("ccooc");
//delay(1000);
//hand_model("ccccc");
//delay(1000);
}

