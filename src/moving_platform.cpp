#include "moving_platform.hpp"
#include "wrap-hwlib.hpp"

namespace MovingPlatform {
// Platform(? & leftMotor, ? & rightMotor):
// leftMotor(leftMotor), rightMotor(rightMotor)
Platform::Platform() {
    wheelsize = 60;
    smoothing = 15;
}

void Platform::move(const uint32_t &distance, const Direction &direction) {
    if (direction == Direction::Forward) {
        hwlib::cout << "moving forward for " << distance << " cm." << hwlib::endl;
    } else {
        hwlib::cout << "moving backwards for " << distance << " cm." << hwlib::endl;
    }
}

void Platform::rotate(int16_t angle) {
    hwlib::cout << "rotating platform with  " << angle << " degrees." << hwlib::endl;
}

void Platform::emergencyStop() {
    hwlib::cout << "stoping platform right now." << hwlib::endl;
}

void Platform::setWheelSize(int16_t newWheelsize) {
    wheelsize = newWheelsize;
}

void Platform::setSmoothing(int16_t newSmoothing) {
    smoothing = newSmoothing;
}

int16_t Platform::getWheelSize() {
    return wheelsize;
}

int16_t Platform::getSmoothing() {
    return smoothing;
}

void Platform::setSpeed(int16_t newSpeed) {
    speed = newSpeed;
}

int16_t Platform::getSpeed() {
    return speed;
}

} // namespace MovingPlatform
