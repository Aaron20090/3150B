#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void AWP(){
    //blue side
    PIDDataSet TestPara={1.5,0.1,0.15};
    MoveEncoderPID(TestPara, -100, 4 , 0.4, 0, true);
    Clamp.set(false);




}

void  redAWP(){
PIDDataSet TestPara={1.5,0.1,0.15}; //initialize
Clamp.set(true);
 MoveEncoderPID(TestPara, 100, 60, 0.4, 0, true);
 OPMECH.set(false);
 wait(100,msec);
MoveEncoderPID(TestPara, -100, 25, 0.4, 0, true);
OPMECH.set(true);
TurnMaxTimePID(TestPara, 190, 0.4, true);
MoveEncoderPID(TestPara, -100, 7, 0.4, 190, true);
MoveEncoderPID(TestPara, -20, 7, 0.4, 190, true);
Clamp.set(false);
wait(300, msec);
RunRoller(100);//run roller
wait(500, msec);
Clamp.set(true);
wait(800, msec);
MoveEncoderPID(TestPara, 80, 10, 0.4, 190, true);
TurnMaxTimePID(TestPara, 124, 0.4, true);
MoveEncoderPID(TestPara, -30, 20, 0.4, 130, true);
Clamp.set(false);
wait(400, msec);
MoveEncoderPID(TestPara, 80, 35, 0.4, 80 , true);
TurnMaxTimePID(TestPara, -120, 0.4, true);
MoveEncoderPID(TestPara, 100, 50, 0.4, -120 , true);
Pistake.set(true);
MoveEncoderPID(TestPara, 60, 27, 0.4, -120 , true);
wait(500, msec);








}

void redSafeAWP() {
  PIDDataSet TestPara={1.5,0.1,0.15}; //initialize
    
       doinker.set(false);
    OPMECH.set(false);
    Clamp.set(true);
    Pistake.set(true);


 MoveEncoderPID(TestPara, -100, 25, 0.3, 0, true);// go forward toward mogo
 MoveEncoderPID(TestPara, -40, 10, 0.3, -1, true);// slow down to grab mogo
Clamp.set(false); // grab mogo
wait(100, msec);
TurnMaxTimePID(TestPara, 140, 0.8, true);// turn toward middle first ring
RunRoller(100);//run roller
MoveEncoderPID(TestPara, 60, 34, 0.3, 140, true);// go toward for middle rings
wait(50, msec);
MoveEncoderPID(TestPara, -100, 8, 0.3, 138, true);//move back
TurnMaxTimePID(TestPara, 125, 0.4, true);//turn toward second middle ring
MoveEncoderPID(TestPara, 60, 20.5, 0.4, 125, true);//Drive to get second middle ring
MoveEncoderPID(TestPara, -100, 30, 0.4, 125, true);//move back 
TurnMaxTimePID(TestPara, 100, 0.4, true);//turn to single rings
MoveEncoderPID(TestPara, 90, 30, 0.4, 90, true);//get it
wait(100,msec);
/*TurnMaxTimePID(TestPara, -60, 0.4, true);//turn to corner ring
Pistake.set(false);
MoveEncoderPID(TestPara, 100, 50, 0.4, -60, true);
MoveEncoderPID(TestPara, 45, 22, 0.4, -60, true);
wait(100, msec);    
Pistake.set(true);
wait(600, msec);
MoveEncoderPID(TestPara, -80, 9, 0.4 , -90, true);
wait(100, msec);
TurnMaxTimePID(TestPara, -180, 0.4, true);
MoveEncoderPID(TestPara, 130, 39, 0.4 ,-170 ,false);
RunLift(-100);
wait(200, msec);
RunLift(0);*/






}
void redSuperSafe() {
   PIDDataSet TestPara={1.5,0.1,0.15}; //initialize
    
       doinker.set(false);
    OPMECH.set(false);
    Clamp.set(true);
    Pistake.set(true);


 MoveEncoderPID(TestPara, -100, 25, 0.3, 0, true);// go forward toward mogo
 MoveEncoderPID(TestPara, -40, 10, 0.3, -1, true);// slow down to grab mogo
Clamp.set(false); // grab mogo
wait(100, msec);
TurnMaxTimePID(TestPara, 140, 0.8, true);// turn toward middle first ring
RunRoller(100);//run roller
MoveEncoderPID(TestPara, 60, 34.5, 0.3, 140, true);// go toward for middle rings
wait(50, msec);
MoveEncoderPID(TestPara, -100, 8, 0.3, 138, true);//move back
TurnMaxTimePID(TestPara, 125, 0.4, true);//turn toward second middle ring
MoveEncoderPID(TestPara, 60, 20.5, 0.4, 125, true);//Drive to get second middle ring
MoveEncoderPID(TestPara, -100, 30, 0.4, 125, true);//move back 
TurnMaxTimePID(TestPara, 100, 0.4, true);//turn to single rings
MoveEncoderPID(TestPara, 90, 30, 0.4, 90, true);//get it
wait(100,msec);
/*TurnMaxTimePID(TestPara, -60, 0.4, true);//turn to corner ring
Pistake.set(false);
MoveEncoderPID(TestPara, 100, 50, 0.4, -60, true);
MoveEncoderPID(TestPara, 45, 22, 0.4, -60, true);
wait(100, msec);    
Pistake.set(true);
wait(600, msec);
MoveEncoderPID(TestPara, -80, 9, 0.4 , -90, true);
wait(100, msec);
TurnMaxTimePID(TestPara, -180, 0.4, true);
MoveEncoderPID(TestPara, 130, 39, 0.4 ,-170 ,false);
RunLift(-100);
wait(200, msec);
RunLift(0);*/


   


}
void blueSafeAWP() {
     PIDDataSet TestPara={1.5,0.1,0.15}; //initialize
     Clamp.set(true);
     Pistake.set(false);
    
     
     MoveEncoderPID(TestPara, 100, 2, 0.4, 0, true);
     wait(100, msec);
    RunLift(-100);
  wait(480, msec);
 RunLift(0);
 MoveEncoderPID(TestPara, -100, 30, 0.4, 0, true);
 MoveEncoderPID(TestPara, -30, 15, 0.4, -2, true);
 RunLift(100);
 Clamp.set(false);
wait(485, msec);
RunLift(0);
    TurnMaxTimePID(TestPara, -110, 0.4, true);
    RunRoller(100);
    MoveEncoderPID(TestPara, 100, 35, 0.4, -110, true);
    TurnMaxTimePID(TestPara,-47, 0.4, true);
    MoveEncoderPID(TestPara, 100, 40, 0.4, -47, true);
    MoveEncoderPID(TestPara, 65, 10, 0.4, -47, true);
   // TurnMaxTimePID(TestPara, 45, 0.4, true);
   // MoveEncoderPID(TestPara, 100, 55, 0.4, 45, true);

 /*MoveEncoderPID(TestPara, -100, 3, 0.4, 0, true);
  TurnMaxTimePID(TestPara, -110, 0.4, true);
  RunRoller(100);
 MoveEncoderPID(TestPara, 100, 20, 0.4, -110, true);
    MoveEncoderPID(TestPara, 50, 5, 0.4, -110, true);
    MoveEncoderPID(TestPara, -50, 20, 0.4, -110, true);
    TurnMaxTimePID(TestPara, -15, 0.4, true);
    MoveEncoderPID(TestPara, 100, 35, 0.4, -15, true);
    TurnMaxTimePID(TestPara, -130, 0.4, true);
    MoveEncoderPID(TestPara, 70, 35, 0.5, -130, true);
    wait(200, msec);
    MoveEncoderPID(TestPara, -100, 10, 0.4, -110, true);
    TurnMaxTimePID(TestPara, -260, 0.4, true);
    MoveEncoderPID(TestPara, 50, 50, 0.4, -260, true);
    MoveEncoderPID(TestPara,70, 20, 0.4, 110, true);
    RunLift(-100);
    wait(330, msec);
    RunLift(0);
*/






}

void blue9PTRing() {
   PIDDataSet TestPara={1.5,0.1,0.15}; //initialize
    
    MoveEncoderPID(TestPara, -100, 11.5, 0.4, 0, true); 
    Clamp.set(true); //Dunk
    MoveEncoderPID(TestPara, 100, 30, 0.4, 0, false); // drive to mogo 
    TurnMaxTimePID(TestPara, -5.2, 0.12, true);
    MoveEncoderPID(TestPara, 55, 21.4, 0.4, -5.2, true);
    lift.spinToPosition(200, degrees, false); //lower arm
    Pistake.set(true);
    //Clamp.set(false);
    RunRoller(100); 
    MoveEncoderPID(TestPara, 100, 4.5, 0.4, -2.8, true ); // move back a little more 
    TurnMaxTimePID(TestPara, -153, 0.8, true); // turn to face rings
    MoveEncoderPID(TestPara, -100,10.7, 0.3, -150, true); // drive to get first ring
    TurnMaxTimePID(TestPara, -124, 0.5, true); // turn to second ring
    MoveEncoderPID(TestPara, -90, 7.9, 0.3, -124, true); // drive to second ring
    Clamp.set(false);
    TurnMaxTimePID(TestPara, -3, 0.6, true); // turn to third ring
    MoveEncoderPID(TestPara, -100, 7, 0.3, -3, true); // drive to third ring
    Clamp.set(false);
  //  OPMECH.set(true); // raise up intake
    TurnMaxTimePID(TestPara, 32, 0.7, true); // turn to last ring
    OPMECH.set(true); // raise up intake
    
    MoveEncoderPID(TestPara, -100, 65, 0.4, 32, true ); // drive full speed to last ring
    
    OPMECH.set(true); // raise up intake
    //MoveEncoderPID(TestPara, -46, 11, 0.5, 41, true); // slow down so you dont knock it out
    RunRoller(100);
    
    wait(500,msec);
    MoveEncoderPID(TestPara, 60, 10, 0.3,41,false ); // pull back
    wait(300,msec);
    lift.resetPosition();
    lift.spinToPosition(-1000, degrees, false); //raise arm
    MoveEncoderPID(TestPara, 100, 20, 0.3, 100, true); // align with ladder
    MoveEncoderPID(TestPara, -80, 26, 0.3, 100, true); // drive to ladder 
    





}
void MogoRush(){
    PIDDataSet TestPara={1.5,0.1,0.15};
    //Corner swipe 4 ring safe
    MoveEncoderPID(TestPara, 100, 28, 0.2, -1.7, false); 
    MoveEncoderPID(TestPara, 100, 6, 0.2, -1.7, false); 
    MoveEncoderPID(TestPara, 100, 18, 0.2, -25.7, false);
    MoveEncoderPID(TestPara, 60, 2, 0.2, -25.7, false);
    MoveEncoderPID(TestPara, 50, 1.93, 0.3, -25.8, true);
   
    //MoveEncoderPID(TestPara, 60, .8, 0.2, -26.8, true);
    Clamp.set(false);
   
    
    MoveEncoderPID(TestPara, -100, 8, 0.2, -26, true);
    wait(200,msec);
    TurnMaxTimePID(TestPara, 77, 0.4, true);
    RunRoller(100);
    MoveEncoderPID(TestPara, -100, 19.6, 0.3, 77, true);
    MoveEncoderPID(TestPara, 100, 7, 0.3, 77, true);
    TurnMaxTimePID(TestPara, -150, 0.6, true);
    
    MoveEncoderPID(TestPara, 80, 10, 0.2,-150, false);
    Clamp.set(true);
    MoveEncoderPID(TestPara, 90, 5, 0.3, -150, true);
    RunRoller(0);
    
    MoveEncoderPID(TestPara, -90, 1.5, 0.3, -150, true);
    TurnMaxTimePID(TestPara, 92, 0.5, true);
    MoveEncoderPID(TestPara, 80, 24, 0.2, 92, false);
    MoveEncoderPID(TestPara, 70, 13, 0.2, 92, true);
    Clamp.set(false);
    TurnMaxTimePID(TestPara, -45, 0.6, true);
    RunRoller(90);
    MoveEncoderPID(TestPara, -100, 25, 0.3, -45, true);
    
    Pistake.set(true);
    MoveEncoderPID(TestPara, -70, 7, 0.2, -45, true);
    Pistake.set(false);
    wait(200,msec);
    MoveEncoderPID(TestPara, 70, 10, 0.3, -45, true);
    TurnMaxTimePID(TestPara, -17.2, 0.4, true);
    
    MoveEncoderPID(TestPara, -60, 32, 0.3, -17.2, true);
    RunRoller(0);
  
    wait(800,msec);
    RunLift(0);



   










    


    
    /*
    wait(300,msec);
    MoveEncoderPID(TestPara, -70, 7, 0.3,30.5, true );
    MoveEncoderPID(TestPara, -50, 8, 0.3,0,false );

  
    TurnMaxTimePID(TestPara, -75, 0.7, true);
    doinker.set(true);
    MoveEncoderPID(TestPara, -100, 39.5, 0.4, -75, true);
    RunRoller(0);
   
    MoveEncoderPID(TestPara, -100, 18.4, 0.4, -75, true);
    wait(100, msec);
    TurnMaxTimePID(TestPara, -200, 0.46, true);
    RunRoller(-100);
    TurnMaxTimePID(TestPara, -220, 0.2, true);
    doinker.set(false);
    TurnMaxTimePID(TestPara, -88, 0.4, true);
    RunRoller(100);
    MoveEncoderPID(TestPara, -95, 19, 0.3, -88, true);
    wait(200, msec);
    MoveEncoderPID(TestPara, 100, 50, 0.3, -88, true);
    lift.resetPosition();
    lift.spinToPosition(-1000, degrees, false);
    MoveEncoderPID(TestPara, -100, 5, 0.3, 98, true);
    MoveEncoderPID(TestPara, -100, 23, 0.3, 98, true);
    lift.spinToPosition(20, degrees, false);
    */

   // MoveEncoderPID(TestPara, 100, 12, 0.3, 70, true);
    //MoveEncoderPID(TestPara, -100, 10, 0.3, 70, true);
}
    
void Simple6(){
  PIDDataSet TestPara={1.5,0.1,0.15};
  lift.resetPosition();
  MoveEncoderPID(TestPara, 100,13.5 , 0.4, 0, false);//Move back fast for mogo
  MoveEncoderPID(TestPara, 80, 11.9, 0.4, 0, false);//Move back slower so moog doesn't go flying
  Clamp.set(false);
  wait(200,msec);
  //MoveEncoderPID(TestPara, 100, 3.3 , 0.3, 0, true);
  TurnMaxTimePID(TestPara, 133, 0.6, true);//turn to face 1st ring
  RunRoller(90);
  MoveEncoderPID(TestPara, -100, 25, 0.3, 133 ,true);//drive to 1st ring
  RunRoller(100);
  MoveEncoderPID(TestPara, 100, 4, 0.2, 133 ,true);//drive back to be safe
  TurnMaxTimePID(TestPara, 118, 0.3, true);//turn to 2nd ring
  MoveEncoderPID(TestPara, -100, 17, 0.2, 118, true);//drive to second ring
  wait(100,msec);
  MoveEncoderPID(TestPara, 100, 9, 0.2, 118, false);//drive back
  TurnMaxTimePID(TestPara, 45, 0.5, true);// turn to 3rd ring
  MoveEncoderPID(TestPara, -100, 16, 0.2, 45, true);//drive to 3rd ring
  MoveEncoderPID(TestPara, 100, 10, 0.2, 30, true);// drive back
  TurnMaxTimePID(TestPara, 34, 0.5, true);// turn to corner
  MoveEncoderPID(TestPara, -100, 60, 0.2, 34, true);//drive fast to corner
  MoveEncoderPID(TestPara, -80, 20, 0.2, 34, true);// drive slower to not break anything
  wait(50,msec);
  MoveEncoderPID(TestPara, 100, 10, 0.2, 60, true);//drive back
  TurnMaxTimePID(TestPara, -90, 0.5, true);//face last ring
  MoveEncoderPID(TestPara, -100, 25, 0.2, -90, true);// drive to last ring
  //lift.setVelocity(60,percent);
  //lift.spinTo(-86, degrees);//lift wall stakes
  Pistake.set(true);
  MoveEncoderPID(TestPara, -70, 25, 0.3, -90, true);// drive  to last ring
  Pistake.set(false);
  wait(200,msec);
  MoveEncoderPID(TestPara, 65, 6, 0.3, -90, true);// drive back so the ring goes all the way
  RunRoller(0);
  wait(50,msec);
  RunRoller(100);
  
  TurnMaxTimePID(TestPara, -37, 0.5, true);// turn to alliance stake
  
  
  //MoveEncoderPID(TestPara, -70, 21, 0.5, -37, true);// drive to alliance stake
  //RunRoller(0);
  //RunLift(-40);
  //wait(800,msec);
  //RunLift(60);
  MoveEncoderPID(TestPara, 70, 24, 0.5, -37, true);// drive back
  //MoveEncoderPID(TestPara, 70, 45, 0.5, -37, true);// drive back
  //RunLift(0);
  //lift.setVelocity(100,percent);
  
}

void Simple6Inverted(){
  PIDDataSet TestPara={1.5,0.1,0.15};
  lift.resetPosition();
  MoveEncoderPID(TestPara, 100,13.5 , 0.4, 0, false);//Move back fast for mogo
  MoveEncoderPID(TestPara, 80, 11.9, 0.4, 0, false);//Move back slower so moog doesn't go flying
  Clamp.set(false);
  wait(200,msec);
  //MoveEncoderPID(TestPara, 100, 3.3 , 0.3, 0, true);
  TurnMaxTimePID(TestPara, -133, 0.6, true);//turn to face 1st ring
  RunRoller(90);
  MoveEncoderPID(TestPara, -100, 24, 0.2, -133 ,true);//drive to 1st ring
  RunRoller(100);
  MoveEncoderPID(TestPara, 100, 4, 0.2, -133 ,true);//drive back to be safe
  TurnMaxTimePID(TestPara, -118, 0.25, true);//turn to 2nd ring
  MoveEncoderPID(TestPara, -100, 17.2, 0.2, -118, true);//drive to second ring
  wait(100,msec);
  MoveEncoderPID(TestPara, 100, 9, 0.2, -118, false);//drive back
  TurnMaxTimePID(TestPara, -45, 0.5, true);// turn to 3rd ring
  MoveEncoderPID(TestPara, -100, 17, 0.2, -45, true);//drive to 3rd ring
  MoveEncoderPID(TestPara, 100, 10, 0.2, -30, true);// drive back
  TurnMaxTimePID(TestPara, -34, 0.4, true);// turn to corner
  MoveEncoderPID(TestPara, -100, 60, 0.2, -34, true);//drive fast to corner
  MoveEncoderPID(TestPara, -80, 20, 0.2, -34, true);// drive slower to not break anything
  wait(50,msec);
  MoveEncoderPID(TestPara, 100, 10, 0.2, 60, true);//drive back
  TurnMaxTimePID(TestPara, 90, 0.5, true);//face last ring
  MoveEncoderPID(TestPara, -100, 40, 0.2, 90, true);// drive to last ring
  //lift.setVelocity(60,percent);
  //lift.spinTo(-86, degrees);//lift wall stakes
  Pistake.set(true);
  MoveEncoderPID(TestPara, -70, 27, 0.3, 90, true);// drive  to last ring
  Pistake.set(false);
  wait(200,msec);
  MoveEncoderPID(TestPara, 65, 6, 0.3, 90, true);// drive back so the ring goes all the way
  RunRoller(0);
  wait(50,msec);
  RunRoller(100);
  TurnMaxTimePID(TestPara, 32, 0.5, true);// turn to alliance stake
  
  
  //MoveEncoderPID(TestPara, -70, 18, 0.5, 37, true);// drive to alliance stake
  //RunRoller(0);
  //RunLift(-40);
  //wait(800,msec);
  //RunLift(60);
  MoveEncoderPID(TestPara, 70, 35, 0.5, 37, true);// drive back
  //RunLift(0);
  //lift.setVelocity(100,percent);
  
}
