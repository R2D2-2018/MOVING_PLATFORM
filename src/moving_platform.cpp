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

void Platform::rotate(short angle) {
    if (angle > 360 || angle < -360) {
        return;
    }
}

void Platform::emergencyStop() {
}

// SET AND GET
void Platform::setWheelSize(short mm) {
    wheelsize = mm;
}

void Platform::setSmoothing(short value) {
    smoothing = value;
}

short Platform::getWheelSize() {
    return wheelsize;
}

short Platform::getSmoothing() {
    return smoothing;
}

void Platform::setSpeed(short newSpeed) {
    speed = newSpeed;
}

short Platform::getSpeed() {
    return speed;
}

} // namespace MovingPlatform
