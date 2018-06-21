#define _USE_MATH_DEFINES

#include "moving_platform.hpp"
#include "modules/MOTOR_CONTROLLER/motor_interface.hpp"
#include "wrap-hwlib.hpp"
#include <math.h>

namespace MovingPlatform {
// Platform(? & leftMotor, ? & rightMotor):
// leftMotor(leftMotor), rightMotor(rightMotor)
Platform::Platform() {
    wheelsize = 60;
    smoothing = 15;
}

MotorInterface MotorInterface;

/**
* @brief Move should move in a direction for a certain amount of distance, we need to use the haul sensor to make this work.
* The haul sensor isn't implemented yet, to calculate the distance we need to have the number of rotations per second to calculate the distance travelled.
*/
void Platform::move(const uint32_t &distance, const Direction &direction) {
    direction = MotorController::MotorInterface::DIRECTION;
    // RotationsPerSecond doesn't the exist yet, which we need from the haul sensor.
    //distance = M_PI * wheelsize * RotationsPerSecond;

    if (direction == Direction::Forward) {
        hwlib::cout << "moving forward for " << distance << " cm." << hwlib::endl;
    } else {
        hwlib::cout << "moving backwards for " << distance << " cm." << hwlib::endl;
    }
    MotorInterface.setSpeed(5 - '0');
    //when the desired amount of rotations are excecuted we need to set the speed to zero again.
    MotorInterface.setSpeed(0 - '0');
}

/**
* @brief This should rotate the motor with a certain amount of degrees, but this hasn't been implemented yet in the motor interface.
* We need to use atleast two motors and the haul sensor to make this work.
*/
void Platform::rotate(int16_t angle) {
    /// one motor has to rotate backwards while the other rotates forward.
    hwlib::cout << "rotating platform with  " << angle << " degrees." << hwlib::endl;
}

/**
* @brief emergencyStop sets the speed to zero which ofcourse makes it stop.
*/
void Platform::emergencyStop() {
    hwlib::cout << "stopping platform right now." << hwlib::endl;
    MotorInterface.setSpeed(0 - '0');
}

/**
* @brief setWheelsize is the setter for a new wheelsize.
*/
void Platform::setWheelSize(int16_t newWheelsize) {
    wheelsize = newWheelsize;
}

/**
* @brief setSmoothing is the setter for a new smoothing value.
*/
void Platform::setSmoothing(int16_t newSmoothing) {
    smoothing = newSmoothing;
}

/**
* @brief getWheelsize is the getter for the wheelsize.
*/
int16_t Platform::getWheelSize() {
    return wheelsize;
}

/**
* @brief getSmoothing is the getter for the smoothing value.
*/
int16_t Platform::getSmoothing() {
    return smoothing;
}

/**
* @brief setSpeed is the setter for a new speed value.
*/
void Platform::setSpeed(int16_t newSpeed) {
    speed = newSpeed;
}

/**
* @brief getSpeed is the getter for the speed value. 
*/
int16_t Platform::getSpeed() {
    return speed;
}

} // namespace MovingPlatform
