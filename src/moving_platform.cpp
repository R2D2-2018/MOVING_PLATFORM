#include "moving_platform.hpp"
#include "wrap-hwlib.hpp"

namespace MovingPlatform {
Platform::Platform(UARTLib::UARTConnection &serialCon, hwlib::pin_in &hallSensorPinA, hwlib::pin_in &hallSensorPinB)
    : serialCon(serialCon), motorController(Qik2S12V10(serialCon)), hallSensorPinA(hallSensorPinA), hallSensorPinB(hallSensorPinB) {
    wheelsize = 60;
    smoothing = 15;
}

void Platform::move(const uint32_t &distance, const Direction &direction) {
    if (direction == Direction::Forward) {
        movePlatformForward(distance * 10);
    } else {
        movePlatformBackward(distance * 10);
    }
}

void Platform::rotate(int16_t angle) {
    hwlib::cout << "rotating platform with  " << angle << " degrees." << hwlib::endl;
}

void Platform::emergencyStop() {
    hwlib::cout << "stopping platform right now." << hwlib::endl;
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

void Platform::movePlatformForward(int32_t distanceMilliMeters) {
    motorController.setMotorForward(20);
    uint16_t degrees = (distanceMilliMeters * 1000) / umPerDegree;
    // hwlib::cout << "moving the motor " << int(degrees) << " degrees" << hwlib::endl;
    waitUntilRotations(degrees * (countsPerRotation / 360));
    motorController.setMotorForward(0);
}

void Platform::movePlatformBackward(int32_t distanceMilliMeters) {
    motorController.setMotorReverse(20);
    int16_t degrees = -(distanceMilliMeters * 1000) / umPerDegree;
    waitUntilRotations(degrees * (countsPerRotation / 360));
    motorController.setMotorReverse(0);
}

void Platform::waitUntilRotations(int32_t rotations) {

    int32_t count = 0;
    int32_t previousA = hallSensorPinA.get();
    int32_t previousB = hallSensorPinB.get();
    int32_t newA = 0;
    int32_t newB = 0;

    while (rotations > 0 ? (count < rotations) : (count > rotations)) {
        newA = hallSensorPinA.get();
        newB = hallSensorPinB.get();

        if (newA == previousA && newB == previousB) {
            continue;
        }

        caclulateNewCount(newA, newB, previousA, count);

        previousA = newA;
        previousB = newB;
    }
}

void Platform::caclulateNewCount(const int32_t &newA, const int32_t &newB, const int32_t &previousA, int32_t &count) {
    if (newA != previousA) {
        if (newA == 1) {
            if (newB == 0) {
                count++;
            } else {
                count--;
            }
        } else {
            if (newB == 1) {
                count++;
            } else {
                count--;
            }
        }
    } else {
        if (newB == 1) {
            if (newA == 1) {
                count++;
            } else {
                count--;
            }
        } else {
            if (newA == 0) {
                count++;
            } else {
                count--;
            }
        }
    }
}

} // namespace MovingPlatform
