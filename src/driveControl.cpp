#include "auton/auton.h" // IWYU pragma: keep
#include "driverControl.h"
#include "main.h"

bool isSucking = false;
bool isReverse = false;
bool isHooding = false;
bool isWinging = false;
bool isMatching = false;
bool isCentering = false;
bool isZooming = true;

void buttonControls() {
  while (true) {
    pros::delay(10);
    if (controller.get_digital_new_press(
            pros::E_CONTROLLER_DIGITAL_R1)) { // R1 toggle to store
      if (isSucking) {
        sucker.move(0);
        hoodlum.move(0);
        isSucking = false;
      } else if (!isSucking) {
        sucker.move(127);
        hoodlum.move(-40);
        isSucking = true;
      }
    }
    pros::delay(10);
    if (controller.get_digital_new_press(
            pros::E_CONTROLLER_DIGITAL_R2)) { // R2 toggle to score
      if (isReverse) {
        sucker.move(0);
        hoodlum.move(0);
        isReverse = false;
      } else if (!isReverse) {
        if (isZooming) {
          sucker.move(127);
          hoodlum.move(127);
        } else if (!isZooming) {
          sucker.move(80);
          hoodlum.move(80);
        }
        isReverse = true;
      }
    }
    if (controller.get_digital_new_press(
            pros::E_CONTROLLER_DIGITAL_L1)) { // L1 to activate wings
      if (isWinging) {
        wingerL.set_value(0);
        wingerR.set_value(0);
        isWinging = false;
      } else {
        wingerL.set_value(1);
        wingerR.set_value(1);
        isWinging = true;
      }
    }
    pros::delay(10);
    if (controller.get_digital_new_press(
            pros::E_CONTROLLER_DIGITAL_L2)) { // L2 to activate
                                              // matchloader
      if (isMatching) {
        matcher.set_value(0);
        isMatching = false;
      } else {
        matcher.set_value(1);
        isMatching = true;
      }
    }
    pros::delay(10);
    if (controller.get_digital_new_press(
            pros::E_CONTROLLER_DIGITAL_A)) { // A to activate center piston for
                                             // scoring
      if (isCentering) {
        center.set_value(0);
        isCentering = false;
      } else {
        center.set_value(1);
        isCentering = true;
      }
    }
    pros::delay(10);
    if (controller.get_digital_new_press(
            pros::E_CONTROLLER_DIGITAL_B)) { // B toggle to reverse intake
      if (isSucking) {
        sucker.move(0);
        isSucking = false;
      } else if (!isSucking) {
        sucker.move(-100);
        isSucking = true;
      }
    }
    pros::delay(10);
    if (controller.get_digital_new_press(
            pros::E_CONTROLLER_DIGITAL_X)) { // X toggle to change scoring
                                             // velocity
      if (isZooming) {
        isZooming = false;
      } else if (!isZooming) {
        isZooming = true;
      }
    }
  }
}