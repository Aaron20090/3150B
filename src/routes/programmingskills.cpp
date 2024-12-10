#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void ProgSkill() {
    PIDDataSet TestPara={1.5,0.1,0.15}; //initialize

    Lift.setVelocity(200, rpm);
      Pistake.set(false); // score alliance ring
    wait(500,msec);
    MoveEncoderPID(TestPara, -65, 13, 0.4, 0, true); //back up
    TurnMaxTimePID(TestPara, -97,.5,true); 
    MoveEncoderPID(TestPara, -100, 15, 0.3, -90, false);
    MoveEncoderPID(TestPara, -60, 15, 0.3, -90, true );
    Clamp.set(false);
    Lift.spinToPosition(-350, degrees, false);
    MoveEncoderPID(TestPara, -100, 5, 0.3, -90, true);
    
    TurnMaxTimePID(TestPara, 200, 0.8, true);
    Pistake.set(true);
    RunRoller(-100); //pickup 1st ring
    MoveEncoderPID(TestPara, 100, 28, 0.3, 200, true);
    wait(100, msec);
    TurnMaxTimePID(TestPara, 91, 0.3, true);
    MoveEncoderPID(TestPara, 100, 22 , 0.3, 91, true); //go to 2nd ring
    wait(100,msec); 
    MoveEncoderPID(TestPara, 80, 2, 0.3, 91, true);
    TurnMaxTimePID(TestPara, 3, 0.8, true); //pickup 3rd ring
    MoveEncoderPID(TestPara, 60, 30, 0.3, 3, true);
    wait(100, msec);







    MoveEncoderPID(TestPara, 60, 20, 0.3, 3, true); 
    MoveEncoderPID(TestPara, -80, 8, 0.3, 8, true);    
    TurnMaxTimePID(TestPara, 103, 0.8, true);
    MoveEncoderPID(TestPara, 80, 10, 0.3, 103, true); //pickup 5th ring
    wait(500,msec);
    MoveEncoderPID(TestPara, -100, 10, 0.4, 90, true);
    TurnMaxTimePID(TestPara, 190, 0.8, true);
    MoveEncoderPID(TestPara, -100, 23, 0.4, -130, true);
    Clamp.set(true); //drop mogo 1st corner
    wait(500,msec);
    MoveEncoderPID(TestPara, 100, 10, 0.4, 140, true);
    TurnMaxTimePID(TestPara, -170, 0.8, true);
    RunRoller(-100);
    MoveEncoderPID(TestPara, 100, 85, 0.4, -170, true);
    MoveEncoderPID(TestPara, -100, 5, 0.4, -170, true);
    Pistake.set(false);
    RunRoller(100);
    wait(500, msec);
    RunRoller(-100);
    Lift.spinToPosition(300, degrees, false);
    wait(1300, msec);
    TurnMaxTimePID(TestPara, 108, 0.5, true);
    wait(500, msec);
    MoveEncoderPID(TestPara, 80, 22, 0.4, 108, true);
    Lift.spinToPosition(-150, degrees, false);
    wait(700, msec);
    MoveEncoderPID(TestPara, -100, 10, 0.4, 96, true);
    TurnMaxTimePID(TestPara, 205, 0.4, true);
    MoveEncoderPID(TestPara, 100, 100, 0.4, 205, true);
    TurnMaxTimePID(TestPara, 85, 0.8, true);
    MoveEncoderPID(TestPara, 80, 50, 0.4, 160, true);
    MoveEncoderPID(TestPara, 100, 5, 0.4, 160, true);
    MoveEncoderPID(TestPara, -100, 75, 0.4, 108, true);
    MoveEncoderPID(TestPara, -70, 5, 0.4, 108, true);
    Clamp.set(true);




}

