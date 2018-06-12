#include "moving_platform.hpp"
#include "wrap-hwlib.hpp"
namespace MovingPlatform {
// Platform(? & leftMotor, ? & rightMotor):
// leftMotor(leftMotor), rightMotor(rightMotor)
Platform::Platform() {
    wheelsize = 60;
    offset = 0;
    smoothing = 15;
}

void Platform::move(short speed, short turn) {
    if (speed > 255 || speed < -255) {
        return;
    }
}

void Platform::rotate(short deg) {
    if (deg > 360 || deg < -360) {
        return;
    }
}

void Platform::rotate(short deg, short speed) {
    if (deg > 360 || deg < -360 || speed > 255 || speed < -255) {
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
