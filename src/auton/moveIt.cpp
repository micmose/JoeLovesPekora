#include "main.h" // IWYU pragma: keep
#include "pros/abstract_motor.hpp" // IWYU pragma: keep
#include "pros/misc.h" // IWYU pragma: keep
#include "pros/motors.h" // IWYU pragma: keep
#include "auton/auton.h" // IWYU pragma: keep

void redRight() {
    // set position to x:0, y:0, heading:0
    chassis.setPose(0, 0, 0);
    // turn to face heading 90 with a very long timeout
    chassis.turnToHeading(90, 100000);
}