#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void MogoRushQual() {
 PIDDataSet TestPara={1.5,0.1,0.15}; //initialize
Clamp.set(true);
 MoveEncoderPID(TestPara, 100, 60, 0.4, 0, true);
 OPMECH.set(false);
 wait(100,msec);
MoveEncoderPID(TestPara, -100, 25, 0.4, 0, true);
OPMECH.set(true);
TurnMaxTimePID(TestPara, -190, 0.4, true);
MoveEncoderPID(TestPara, -100, 7, 0.4, -190, true);
MoveEncoderPID(TestPara, -20, 7, 0.4, -190, true);
Clamp.set(false);
wait(300, msec);
RunRoller(100);//run roller
wait(500, msec);
Clamp.set(true);
wait(800, msec);
MoveEncoderPID(TestPara, 80, 10, 0.4, -190, true);
TurnMaxTimePID(TestPara, -124, 0.4, true);
MoveEncoderPID(TestPara, -30, 20, 0.4, -124, true);
Clamp.set(false);
wait(400, msec);
MoveEncoderPID(TestPara, 80, 35, 0.4, -80 , true);
TurnMaxTimePID(TestPara, 120, 0.4, true);
MoveEncoderPID(TestPara, 100, 50, 0.4, 120 , true);
Pistake.set(true);
MoveEncoderPID(TestPara, 60, 27, 0.4, 120 , true);
wait(500, msec);
Pistake.set(false);


}

void RedMogoRushQual()
{

    PIDDataSet TestPara={1.5,0.1,0.15}; //initialize
   RunLift(100);
   wait(100, msec);
   RunLift(0);



}