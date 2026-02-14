
#include "auton.h"         // IWYU pragma: keep
#include "driverControl.h" // IWYU pragma: keep
#include "main.h"          // IWYU pragma: keep
#include "pros/error.h"
// #include <ios>
void run_auto_skills() {
  // chassis.setPose(0, 0, 90);
 
  // hoodlum.move(-40);
  // chassis.moveToPose(18,6,61,700,{.earlyExitRange=1},false);
  // sucker.move(127);
  // matcher.set_value(1);
  // chassis.moveToPoint(23,9,600,{.earlyExitRange=.5},false);
  // chassis.moveToPose(44,-12,-41,1300,{.forwards=false},false);
  // sucker.move(-50);
  // pros::delay(300);
  // sucker.move(127);
  // center.set_value(1);
  // pros::delay(1300);
  // sucker.move(0);
  // chassis.moveToPose(0,31,270,3000,{.lead=.1,.minSpeed=60,.earlyExitRange=3},false);
  // center.set_value(0);
  // chassis.moveToPoint(chassis.getPose().x+30,chassis.getPose().y,400,{.forwards=false},false);
  // hoodlum.move(127);
  // sucker.move(127);







  // // wingerL.set_value(1);
  // // wingerR.set_value(1);
  // /******************
  // CLEAR PARKING ZONE
  // *******************/
  // // sucker.move(127);
  // // // chassis.moveToPoint(0, -5, 500, {.forwards = false, .minSpeed = 50});
  // // chassis.moveToPoint(0, 14, 5000, {.minSpeed = 100});
  // /******************
  // TRACK DISTANCE FROM WALL
  // *******************/
  // // chassis.turnToHeading(40, 750);
  // // chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
  // // while (true) {
  // //   chassis.moveToPoint(chassis.getPose().x, chassis.getPose().y + 2, 500,
  // //                       {.maxSpeed = 80, .minSpeed = 60, .earlyExitRange = 0.5},
  // //                       false);
  // //   if (lookoutF.get_distance() < 790) {
  // //     chassis.turnToHeading(270, 750);
  // //     break;
  // //   }
  // // }
  // // /******************
  // // SCORE LONG GOAL
  // // *******************/
  // pros::delay(1000);

  // /******************
  // CLEAR RED LEFT MATCH LOADER
  // *******************/
  // chassis.setPose(0, 0, chassis.getPose().theta);
  // matcher.set_value(1);
  // chassis.moveToPose(-50, 0, 270, 2000, {.maxSpeed = 50},false);
  // hoodlum.move(-40);
  // pros::delay(2500);

  // chassis.moveToPoint(chassis.getPose().x+7,chassis.getPose().y,400,{.forwards=false,.earlyExitRange=1},false);
  // matcher.set_value(0);
  // chassis.moveToPose(chassis.getPose().x+50,chassis.getPose().y+15,270,1500,{.forwards=false,.lead=.69,.earlyExitRange=1},false);
  // chassis.moveToPoint(65,chassis.getPose().y,1500,{.forwards=false},false); 
  // chassis.turnToHeading(180,800,{},false);
  
  // while (lookoutB.get_distance() < 310) {
  //   chassis.moveToPoint(chassis.getPose().x, chassis.getPose().y - .1, 500,
  //                       {.minSpeed = 40, .earlyExitRange = 0.01}, false);
  // }
  //     chassis.turnToHeading(90, 750);
  //     chassis.moveToPoint(chassis.getPose().x-50,chassis.getPose().y,1000,{.forwards=false,.maxSpeed=55},false);









  // /******************
  // MOVE TO OTHER END OF LONG GOAL
  // *******************/
  // // chassis.moveToPoint(10, 0, 750, {.forwards=false});
  // // chassis.turnToHeading(90, 750);
  // // chassis.moveToPoint(
  // //     -10, 0,1000,
  // //     {.forwards = false, .maxSpeed = 50, .minSpeed = 40, .earlyExitRange = 2},
  // //     false);
  // // chassis.moveToPoint(50, 12, 2500, {.forwards = false, .minSpeed = 100},
  // //                     false);
  // // while (true) {
  // //   chassis.moveToPoint(
  // //       chassis.getPose().x + 2, chassis.getPose().y, 500,
  // //       {.forwards = false, .minSpeed = 60, .earlyExitRange = 0.5}, false);
  // //   if (lookoutB.get_distance() < 1100) {
  // //     chassis.turnToHeading(180, 1000);
  // //     break;
  // //   }
  // // }
  // // // chassis.moveToPoint(chassis.getPose().x, chassis.getPose().y - 10, 1000);
  // // /*
  
  // //   */
  // // // chassis.moveToPose(80, -10, 90, 1000);
  // // // chassis.moveToPoint(50,-3,1000,{.forwards = false});
  // hoodlum.move(127);
  // matcher.set_value(1);
  chassis.setPose(0,0,90);
  pros::delay(1500);
  hoodlum.move(-40);
  chassis.moveToPoint(120, chassis.getPose().y, 1400,{.maxSpeed=50},false);
  pros::delay(1000);
  chassis.moveToPoint(chassis.getPose().x-60,chassis.getPose().y,1400,{.forwards=false,.maxSpeed=55},false);
  matcher.set_value(0);
  hoodlum.move(127);
  chassis.moveToPose(chassis.getPose().x+33,chassis.getPose().y-25,170,3000,{.lead=.5,.earlyExitRange=1},false);
  hoodlum.move(-40);
  chassis.moveToPoint(chassis.getPose().x+3,chassis.getPose().y-30,2000,{.minSpeed=100});
  pros::delay(1500);
  matcher.set_value(1);
  pros::delay(500);
  chassis.moveToPoint(chassis.getPose().x,chassis.getPose().y-30,1600,{.minSpeed=60},false);
  chassis.turnToHeading(270,700,{},false);
  chassis.moveToPoint(chassis.getPose().x+30,chassis.getPose().y,1000,{.forwards=false,.maxSpeed=40},false);
  chassis.setPose(0,0,270);
  chassis.moveToPoint(10,0,800,{.earlyExitRange=1});
  chassis.turnToHeading(90,800,{},false);
  chassis.moveToPose(-50,15,41,3000,{.forwards=false,.lead=.69,.earlyExitRange=1},false);
  // /*

  //   pros::delay(100);
  //   chassis.moveToPoint(-20, -3, 500, {.maxSpeed = 70, .minSpeed = 50});
  //   chassis.moveToPoint(-15, 0, 1000, {.forwards = false, .minSpeed = 70});
  //   chassis.moveToPose(0, -10, 90, 1000, {.minSpeed = 70, .earlyExitRange = 2});
  //   chassis.moveToPoint(chassis.getPose().x + 76, chassis.getPose().y - 20,
  //   3000,
  //                       {.minSpeed = 80, .earlyExitRange = 18});
  //   chassis.moveToPose(86, -10, 0, 2000);
  //     while (true) {
  //     chassis.moveToPoint(chassis.getPose().x, chassis.getPose().y + 2, 500,
  //                         {.maxSpeed = 80, .minSpeed = 60, .earlyExitRange =
  //   0.5}, false); if (lookoutF.get_distance() < 790) { chassis.turnToHeading(90,
  //   10000); break;
  //     }
  //   }
  // */
  // /******************
  // SCORE LONG GOAL
  // *******************/
  // hoodlum.move(0);
  // chassis.turnToPoint(100, 7, 1000);
  // chassis.moveToPoint(50, chassis.getPose().y, 1000,
  //                     {.forwards = false, .maxSpeed = 70, .minSpeed = 50});
  // pros::delay(1000);
  // hoodlum.move(127);
  // pros::delay(2000);

  // /******************
  // CLEAR BLUE LEFT MATCHLOADER
  // *******************/
  // chassis.moveToPose(100, chassis.getPose().y, 90, 2000,
  //                    {.maxSpeed = 70, .minSpeed = 50});
  // pros::delay(2500);

  // /******************
  // SCORE LONG GOAL
  // *******************/
  // chassis.moveToPoint(50, chassis.getPose().y, 1000,
  //                     {.forwards = false, .maxSpeed = 70, .minSpeed = 50});
  // pros::delay(1000);
  // hoodlum.move(127);
  // pros::delay(2000);
  // hoodlum.move(0);

  // /******************
  // TRACK DISTANCE FROM WALL
  // *******************/
  // chassis.setPose(0, 0, 90);
  // pros::delay(100);
  // chassis.moveToPoint(10, 0, 1000);
  // chassis.turnToHeading(0, 1000);
  // chassis.moveToPose(10, -60, 0, 1500,
  //                    {.forwards = false, .minSpeed = 100, .earlyExitRange = 1},
  //                    false);
  // while (true) {
  //   int dist = lookoutB.get_distance();
  //   if ((dist == PROS_ERR) || dist > 750) {
  //     chassis.moveToPoint(chassis.getPose().x, chassis.getPose().y - 2, 1000,
  //                         {.forwards = false,
  //                          .maxSpeed = 40,
  //                          .minSpeed = 50,
  //                          .earlyExitRange = 0.5},
  //                         false);
  //   } else {
  //     chassis.turnToHeading(90, 1000, {}, false);
  //     break;
  //   }
  // }

  // /******************
  // SCORE LONG GOAL
  // *******************/
  // chassis.moveToPoint(-35, chassis.getPose().y, 1000,
  //                     {.forwards = false, .maxSpeed = 70, .minSpeed = 50});
  // pros::delay(1000);
  // hoodlum.move(127);
  // pros::delay(2000);

  // /******************
  // CLEAR BLUE RIGHT MATCHLOADER
  // *******************/
  // chassis.setPose(0, 0, chassis.getPose().theta);
  // pros::delay(100);
  // hoodlum.move(0);
  // chassis.moveToPoint(35, 2, 1000);
  // pros::delay(2500);
  // chassis.moveToPoint(-35, 0, 1000,
  //                     {.forwards = false, .maxSpeed = 70, .minSpeed = 50});
  // pros::delay(1000);

  // /******************
  // MOVE TO OTHER END OF LONG GOAL
  // *******************/
  // chassis.setPose(0, 0, chassis.getPose().theta);
  // pros::delay(100);
  // chassis.moveToPoint(20, 3, 500, {.maxSpeed = 70, .minSpeed = 50});
  // chassis.moveToPoint(15, 3, 1000, {.forwards = false, .minSpeed = 70});
  // chassis.moveToPose(-10, 20, -90, 1000, {.minSpeed = 70, .earlyExitRange = 2});
  // chassis.moveToPoint(chassis.getPose().x - 76, chassis.getPose().y + 20, 3000,
  //                     {.minSpeed = 80, .earlyExitRange = 18});
  // chassis.moveToPose(-86, -7, 90, 2000);
}
//
//
//
//
//
//
//
//
void run_solo_auto() {
  chassis.setPose(0, 0, 0);
  center.set_value(0);
  wingerL.set_value(1);
  matcher.set_value(1);
  sucker.move(127);
  
  chassis.moveToPoint(-9.5, 26, 850,{.earlyExitRange=.5});
  chassis.moveToPose(20, 28, 87, 1500,
                     {.horizontalDrift = 4, .maxSpeed = 100, .minSpeed = 50,.earlyExitRange=.1});
  chassis.waitUntilDone();

  hoodlum.move(-50);

  pros::delay(300);

  chassis.moveToPose(
      -38, 27.5, 90, 800,
      {.forwards = false, .horizontalDrift = 4, .maxSpeed = 100,.earlyExitRange=.1});

  chassis.waitUntilDone();
  hoodlum.move(127);

  pros::delay(1100);

  matcher.set_value(0);

  hoodlum.move(-40);
  chassis.moveToPoint(-11, 25, 1500, {.earlyExitRange = 5});
  hoodlum.move(127);
  chassis.moveToPose(-31, -45, 170, 2500, {.horizontalDrift = 4, .lead = 0.1,.maxSpeed=90,.minSpeed=30,.earlyExitRange=.1},false);
  matcher.set_value(1);
  hoodlum.move(-40);
  chassis.moveToPose(
      -53, -20, 130, 1000,
      {.forwards = false, .horizontalDrift = 4, .maxSpeed = 100,.minSpeed=50,.earlyExitRange=.1});
  center.set_value(1);

  pros::delay(1800);

  chassis.moveToPoint(-5, -64, 2000,{.earlyExitRange=.2},false);

  center.set_value(0);
  chassis.moveToPose(21.7, -65, 90, 1200,
                     {.forwards = true, .horizontalDrift = 4, .maxSpeed = 100,.minSpeed=40},false);

  chassis.moveToPose(
      -20.3, -67, 90, 1000,
      {.forwards=false,.horizontalDrift = 4, .maxSpeed = 100,.minSpeed=50});
  chassis.waitUntilDone();
  hoodlum.move(127);
}
//
//
//
//
//
//
void run_auto_left() {
  chassis.setPose(0, 0, 180);
  /******************
  CLEAR LEFT MATCH LOADER
  *******************/
  sucker.move(127);
  chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
  while (true) {
    chassis.moveToPoint(chassis.getPose().x, chassis.getPose().y + 2, 500,
                        {.forwards = false,
                         .maxSpeed = 40,
                         .minSpeed = 40,
                         .earlyExitRange = 0.5},
                        false);
    if (lookoutB.get_distance() < 800) {
      chassis.turnToHeading(270, 1000);
      break;
    }
  }
  pros::delay(1000);
  matcher.set_value(1);
  pros::delay(1000);
  chassis.moveToPoint(chassis.getPose().x - 30, chassis.getPose().y, 800,
                      {.maxSpeed = 50, .minSpeed = 30});
  pros::delay(2000);
  /******************
  SCORE LONG GOAL
  *******************/
  chassis.moveToPoint(chassis.getPose().x + 35, chassis.getPose().y, 1000,
                      {.forwards = false, .minSpeed = 50});
  pros::delay(1000);
  hoodlum.move(90);
  pros::delay(1000);
  hoodlum.move(0);
}
//
//
//
//
//
//
//
//
void run_auto_right() {
  chassis.setPose(0, 0, 180);
  /******************
  CLEAR RIGHT MATCH LOADER
  *******************/
  sucker.move(127);
  chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
  while (true) {
    chassis.moveToPoint(chassis.getPose().x, chassis.getPose().y + 2, 500,
                        {.forwards = false,
                         .maxSpeed = 40,
                         .minSpeed = 40,
                         .earlyExitRange = 0.5},
                        false);
    if (lookoutB.get_distance() < 800) {
      chassis.turnToHeading(90, 1000);
      break;
    }
  }
  pros::delay(1000);
  matcher.set_value(1);
  pros::delay(1000);
  chassis.moveToPoint(chassis.getPose().x - 10, chassis.getPose().y, 500,
                      {.maxSpeed = 50, .minSpeed = 30});
  pros::delay(2000);
  /******************
  SCORE LONG GOAL
  *******************/
  chassis.moveToPoint(chassis.getPose().x + 35, chassis.getPose().y, 1000,
                      {.forwards = false, .minSpeed = 50});
  pros::delay(1000);
  hoodlum.move(90);
  pros::delay(1000);
  hoodlum.move(0);
}