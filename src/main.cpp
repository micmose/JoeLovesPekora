#include "main.h"
#include "auton/auton.h"    // IWYU pragma: keep
#include "drivercontrol.h"  // IWYU pragma: keep
#include "lemlib/api.hpp"   // IWYU pragma: keep
#include "lemlib/asset.hpp" // IWYU pragma: keep
#include "lemlib/chassis/trackingWheel.hpp"
// #include "lemlib/logger/telemetrySink.hpp"
#include "auton/auton.h"
//#include "auton/moveIt.h"
#include "pros/abstract_motor.hpp"
#include "pros/adi.hpp"    // IWYU pragma: keep
#include "pros/device.hpp" // IWYU pragma: keep
#include "pros/misc.h"
#include "pros/misc.hpp"
#include "pros/motor_group.hpp"
#include "pros/motors.h" // IWYU pragma: keep
#include "pros/rotation.hpp"
#include "pros/rtos.hpp"

using namespace pros;

// controller
Controller controller(pros::E_CONTROLLER_MASTER);
pros::Controller partner(pros::E_CONTROLLER_PARTNER);

// motor groups
pros::MotorGroup leftMotors({-19, -20, -18}, pros::MotorGearset::blue);

pros::MotorGroup rightMotors({8, 9, 10}, pros::MotorGearset::blue);

pros::Motor sucker(15, pros::MotorGearset::blue);

pros::Motor hoodlum(-14, pros::MotorGearset::blue);

pros::adi::DigitalOut matcher('a');

pros::adi::DigitalOut wingerL('f');

pros::adi::DigitalOut wingerR('f');

pros::adi::DigitalOut center('h');

// tracking wheels
pros::Imu imu(11);

// distance sensor
pros::Distance lookout(6);

// horizontal tracking wheel encoder. Rotation sensor
pros::Rotation horizontalEnc(-13);

// vertical tracking wheel encoders. Rotation sensors
pros::Rotation leftVerticalEnc(7);

pros::Rotation rightVerticalEnc(2);

// horizontal tracking wheel
lemlib::TrackingWheel horizontal(&horizontalEnc, lemlib::Omniwheel::NEW_2, 0.5);

// vertical tracking wheel
lemlib::TrackingWheel leftVertical(&leftVerticalEnc, lemlib::Omniwheel::NEW_2,
                                   0.5);

// vertical tracking wheel.
lemlib::TrackingWheel rightVertical(&rightVerticalEnc, lemlib::Omniwheel::NEW_2,
                                    0.75);

// drivetrain settings
lemlib::Drivetrain drivetrain(&leftMotors, &rightMotors, 12.55,
                              lemlib::Omniwheel::NEW_325, 360, 2);

// lateral motion controller
lemlib::ControllerSettings
    linearController(4,  // proportional gain (kP)
                     0,   // integral gain (kI)
                     .2,   // derivative gain (kD)
                     0,   // anti windup
                     0.1, // small error range, in inches
                     100, // small error range timeout, in milliseconds
                     3,   // large error range, in inches
                     500, // large error range timeout, in milliseconds
                     0    // maximum acceleration (slew)
    );

// angular motion controller
lemlib::ControllerSettings //
    angularController(10,  // proportional gain (kP)   8.5,  9,   10
                      0,   // integral gain (kI)
                      54,  // derivative gain (kD) 47.5, 50, 54
                      0,   // anti windup
                      0.1, // small error range, in degrees
                      100, // small error range timeout, in milliseconds
                      3,   // large error range, in degrees
                      500, // large error range timeout, in milliseconds
                      0    // maximum acceleration (slew)
    );

// sensors for odometry
lemlib::OdomSensors sensors(nullptr, &leftVertical, nullptr, nullptr, &imu);

// input curve for throttle input during driver control
lemlib::ExpoDriveCurve
    throttleCurve(3,    // joystick deadband out of 127
                  10,   // minimum output where drivetrain will move out of 127
                  1.019 // expo curve gain
    );

// input curve for steer input during driver control
lemlib::ExpoDriveCurve
    steerCurve(3,    // joystick deadband out of 127
               10,   // minimum output where drivetrain will move out of 127
               1.019 // expo curve gain
    );

// create the chassis
lemlib::Chassis chassis(drivetrain, linearController, angularController,
                        sensors, &throttleCurve, &steerCurve);

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
  chassis.calibrate();
  pros::lcd::initialize();
  pros::lcd::set_text(1, "Hello PROS User!");
  pros::Task screenTask([&]() {
    while (true) {
      lemlib::telemetrySink()->info("chassis pose: {}", chassis.getPose());
      std::cout << '\r' << std::setw(20) << "Theta " << chassis.getPose().theta
                << std::setw(20) << "Chassis x: " << chassis.getPose().x
                << std::setw(20) << "chassis y: " << chassis.getPose().y
                << std::flush;
      pros::delay(50);
    }
  });
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() { imu.reset(true); }

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
  run_auto_skills();
  //run_auto_left();
  //run_auto_right();
}

// arcade drive
void opcontrol() {
  drivetrain.leftMotors->set_brake_mode_all(pros::E_MOTOR_BRAKE_COAST);
  drivetrain.rightMotors->set_brake_mode_all(pros::E_MOTOR_BRAKE_COAST);
  pros::Task BUTTON_CONTROLS(buttonControls);
  while (true) {
    int Linear = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int Angular = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
    chassis.arcade(Linear, Angular, true, 0.5);
  }
}

// tank drive
/*void opcontrol() {
  drivetrain.leftMotors->set_brake_mode_all(pros::E_MOTOR_BRAKE_COAST);
  drivetrain.rightMotors->set_brake_mode_all(pros::E_MOTOR_BRAKE_COAST);
  pros::Task BUTTON_CONTROLS(buttonControls);
  while (true) {
    int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int rightY = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
    chassis.tank(leftY, rightY);
    pros::delay(25);
  }
}*/