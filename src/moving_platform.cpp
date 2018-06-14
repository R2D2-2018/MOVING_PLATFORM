#include "moving_platform.hpp"
#include "wrap-hwlib.hpp"
namespace MovingPlatform {
// Platform(? & leftMotor, ? & rightMotor):
// leftMotor(leftMotor), rightMotor(rightMotor)
Platform::Platform() {
    wheelsize = 60;
    smoothing = 15;
}

void Platform::move(const uint8_t &speed, const Direction &direction) {
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
