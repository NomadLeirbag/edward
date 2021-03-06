#ifndef locomotion.h
#define locomotion.h

#include <Arduino.h>
#include <Servo.h>

/******************************
 class to coordinate the two
 drive wheels of the robot.
 the wheels are represented by
 class Servo from Servo.h
******************************/

class Locomotion  {
  public:
    // pass the pin numbers to be used
    void start(byte Lpin, byte Rpin, unsigned int tempLeftTime, unsigned int tempRightTime, unsigned int tempMoveTime, byte tempLzero = 90, byte tempRzero = 90);
    
    // move one square forward
    void moveForward();
    
    // turn in place to the left
    void turnLeft();
    
    // turn in place to the right
    void turnRight();
    
    // u-turn clockwise
    void uTurn();
    
    void stop();
    
  private:
    Servo Lservo, Rservo;
    byte Lzero, Rzero; // the values that will stop the motors
    unsigned int leftTime, rightTime, moveTime;
  };

#endif


