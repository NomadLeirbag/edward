#include "whichWays.h"
#include "debug.h" // what could this be used for?

/******************************
 returns most efficient path
******************************/

// currentRoute[i][0] = x pos
// currentRoute[i][1] = y pos
// currentRoute[i][2] = next move

byte whichWay(Robot& aRobot)  {
  debug("whichWay start");
  byte nextSq = 4; // current option - 4 is bad
  
  // use the pythagorean theorem to calculate the distance between the goal and all four squares adjecent to the robot
  // then pick the one that shortens the distance to the goal the most that doesn't have a wall or doesn't lead to a dead end
  byte distance[4] = {0, 0, 0, 0}; // distance to goal from one square away in any direction       
  // the square of the difference in the y axis of the end point and one square above current position plus
  // the square of the difference in the x axis of the end point and one square above current position
  distance[0] = pow(abs(abs(aRobot.endY()) - (abs(aRobot.y()) + 1)), 2) + pow(abs(abs(aRobot.endX()) - abs(aRobot.x())), 2);
  // the square of the difference in the y axis of the end point and one square to the right current position plus
  // the square of the difference in the x axis of the end point and one square to the right current position
  distance[1] = pow(abs(abs(aRobot.endY()) - abs(aRobot.y())), 2) + pow(abs(abs(aRobot.endX()) - (abs(aRobot.x()) + 1)), 2);
  // the square of the difference in the y axis of the end point and one square below current position plus
  // the square of the difference in the x axis of the end point and one square below current position
  distance[2] = pow(abs(abs(aRobot.endY()) - (abs(aRobot.y()) - 1)), 2) + pow(abs(aRobot.endX()) - abs(aRobot.x()), 2);
  // the square of the difference in the y axis of the end point and one square to the left current position plus
  // the square of the difference in the x axis of the end point and one square to the left current position
  distance[3] = pow(abs(abs(aRobot.endY()) - abs(aRobot.y())), 2) + pow(abs(abs(aRobot.endX()) - (abs(aRobot.x() - 1))), 2);
  
  // if no way is viable or this is shorter than the previous shortest viable way and this way is viable, go this way
  if((nextSq == 4 || distance[0] < distance[nextSq]) && (aRobot.World.getDeadEnd(aRobot.x(), aRobot.y(), 0) != true) && (aRobot.World.getWall(aRobot.x(), aRobot.y(), 0) != true))  {
    nextSq = 0;
    }
  // if no way is viable or this is shorter than the previous shortest viable way and this way is viable, go this way
  if((nextSq == 4 || distance[1] < distance[nextSq]) && (aRobot.World.getDeadEnd(aRobot.x(), aRobot.y(), 1) != true) && (aRobot.World.getWall(aRobot.x(), aRobot.y(), 1) != true))  {
    nextSq = 1;
    }
  // if no way is viable or this is shorter than the previous shortest viable way and this way is viable, go this way
  if((nextSq == 4 || distance[2] < distance[nextSq]) && (aRobot.World.getDeadEnd(aRobot.x(), aRobot.y(), 2) != true) && (aRobot.World.getWall(aRobot.x(), aRobot.y(), 2) != true))  {
    nextSq = 2;
    }
  // if no way is viable or this is shorter than the previous shortest viable way and this way is viable, go this way
  if((nextSq == 4 || distance[3] < distance[nextSq]) && (aRobot.World.getDeadEnd(aRobot.x(), aRobot.y(), 3) != true) && (aRobot.World.getWall(aRobot.x(), aRobot.y(), 3) != true))  {
    nextSq = 3;
    }
  debug("whichWay end");
  return aRobot.intToDir(nextSq); 
  }
