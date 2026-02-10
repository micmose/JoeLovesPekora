
#include "auton.h"         // IWYU pragma: keep
#include "driverControl.h" // IWYU pragma: keep
#include "main.h"          // IWYU pragma: keep
#include "pros/error.h"
// #include <ios>
void run_auto_skills() {
  // chassis.setPose(0, 0, 0);
  // wingerL.set_value(1);
  // wingerR.set_value(1);
  // /******************
  // CLEAR PARKING ZONE
  // *******************/
  // sucker.move(127);
  // chassis.moveToPoint(0, -5, 500, {.forwards = false, .minSpeed = 50});
  // chassis.moveToPoint(0, 16, 5000, {.minSpeed = 100});

  // /******************
  // TRACK DISTANCE FROM WALL
  // *******************/
  // chassis.turnToHeading(90, 1000);
  // chassis.moveToPoint(12, chassis.getPose().y, 1000, {});
  // chassis.turnToHeading(180, 1000);
  // chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
  // while (true) {
  //   chassis.moveToPoint(chassis.getPose().x, chassis.getPose().y + 2, 500,
  //                       {.forwards = false,
  //                        .maxSpeed = 40,
  //                        .minSpeed = 40,
  //                        .earlyExitRange = 0.5},
  //                       false);
  //   if (lookout.get_distance() < 750) {
  //     chassis.turnToHeading(270, 1000);
  //     break;
  //   }
  // }

  // /******************
  // SCORE LONG GOAL
  // *******************/
  // chassis.moveToPoint(35, chassis.getPose().y + 8, 2500,
  //                     {.forwards = false, .maxSpeed = 70, .minSpeed = 50});
  // pros::delay(1000);
  // hoodlum.move(127);
  // pros::delay(1000);

  // /******************
  // CLEAR RED LEFT MATCH LOADER
  // *******************/
  // chassis.setPose(0, 0, chassis.getPose().theta);
  // matcher.set_value(1);
  // chassis.moveToPose(-50, -3, 270, 2000, {.maxSpeed = 70, .minSpeed = 50});
  // hoodlum.move(0);
  // pros::delay(2500);

  // /******************
  // SCORE LONG GOAL
  // *******************/
  // chassis.moveToPoint(chassis.getPose().x + 30, chassis.getPose().y + 2, 2500,
  //                     {.forwards = false, .maxSpeed = 70, .minSpeed = 50});
  // pros::delay(1000);
  // hoodlum.move(127);
  // pros::delay(1500);

  // /******************
  // MOVE TO OTHER END OF LONG GOAL
  // *******************/
  // chassis.setPose(0, 0, chassis.getPose().theta);
  // pros::delay(100);
  // chassis.moveToPoint(-20, -3, 500, {.maxSpeed = 70, .minSpeed = 50});
  // chassis.moveToPoint(-15, 0, 1000, {.forwards = false, .minSpeed = 70});
  // chassis.moveToPose(0, -10, 90, 1000, {.minSpeed = 70, .earlyExitRange = 2});
  // chassis.moveToPoint(chassis.getPose().x + 76, chassis.getPose().y - 20, 3000,
  //                     {.minSpeed = 80, .earlyExitRange = 18});
  // chassis.moveToPose(86, 7, 90, 2000);

  // /******************
  // CLEAR BLUE LEFT MATCHLOADER
  // *******************/
  // hoodlum.move(0);
  // chassis.turnToPoint(100, 7, 1000);
  // chassis.moveToPoint(50, chassis.getPose().y - 4, 1000,
  //                     {.forwards = false, .maxSpeed = 70, .minSpeed = 50});
  // chassis.moveToPose(100, chassis.getPose().y - 3, 90, 2000,
  //                    {.maxSpeed = 70, .minSpeed = 50});
  // pros::delay(2500);
  // /******************
  // SCORE LONG GOAL
  // *******************/
  // chassis.moveToPoint(50, chassis.getPose().y, 1000, // y: 3 >> 5 >> 0
  //                     {.forwards = false, .maxSpeed = 70, .minSpeed = 50});
  // pros::delay(1000);
  // hoodlum.move(127);
  // pros::delay(1500);

  /******************
  TRACK DISTANCE FROM WALL
  *******************/
  chassis.setPose(0, 0, 90);
  pros::delay(100);
  chassis.moveToPoint(10, 0, 1000);
  chassis.turnToHeading(0, 1000);
  chassis.moveToPose(10, -60, 0, 1500, {.forwards = false, .minSpeed = 100, .earlyExitRange=1},false);
  while (true) {
    int dist = lookout.get_distance();
    if((dist == PROS_ERR)|| dist>750){
    chassis.moveToPoint(chassis.getPose().x, chassis.getPose().y - 2, 1000,
                        {.forwards = false,
                         .maxSpeed = 40,
                         .minSpeed = 50,
                         .earlyExitRange = 0.5},
                        false);
    }else {
      chassis.turnToHeading(90, 1000,{},false);
      break;
    }
  }

  /******************
  SCORE LONG GOAL
  *******************/
  // chassis.moveToPoint(35, chassis.getPose().y + 8, 2500,
  //                     {.forwards = false, .maxSpeed = 70, .minSpeed = 50});
  // pros::delay(1000);
  // hoodlum.move(127);
  // pros::delay(1000);
}
//
//
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
    if (lookout.get_distance() < 800) {
      chassis.turnToHeading(270, 1000);
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
    if (lookout.get_distance() < 800) {
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