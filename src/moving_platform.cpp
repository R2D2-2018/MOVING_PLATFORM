#include "moving_platform.hpp"
#include "wrap-hwlib.hpp"

namespace MovingPlatform {
Platform::Platform(UARTLib::UARTConnection &serialConnection, hwlib::pin_in &hallSensorPinA, hwlib::pin_in &hallSensorPinB)
    : serialConnection(serialConnection), motorController(Qik2S12V10(serialConnection)), hallSensorPinA(hallSensorPinA),
      hallSensorPinB(hallSensorPinB) {
    wheelSize = 60;
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
    if (angle > 0) {
        motorController.setMotorForward(20, Qik2S12V10::Motors::M1);
        motorController.setMotorReverse(20, Qik2S12V10::Motors::M0);
        waitUntilRotations(angle * rotationsPerDegree);
    } else {
        motorController.setMotorForward(20, Qik2S12V10::Motors::M0);
        motorController.setMotorReverse(20, Qik2S12V10::Motors::M1);
        waitUntilRotations(angle * rotationsPerDegree);
    }
    motorController.setMotorForward(0);
    motorController.getMotorSpeed(Qik2S12V10::Motors::M0);
}

void Platform::emergencyStop() {
    motorController.setMotorForward(0);
}

void Platform::setWheelSize(int16_t newWheelsize) {
    wheelSize = newWheelsize;
}

void Platform::setSmoothing(int16_t newSmoothing) {
    smoothing = newSmoothing;
}

int16_t Platform::getWheelSize() {
    return wheelSize;
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

void Platform::movePlatformForward(int32_t distanceMillimeters) {
    motorController.setMotorForward(40);
    uint16_t degrees = (distanceMillimeters * 1000) / umPerDegree;
    waitUntilRotations(degrees * (countsPerRotation / 360));
    motorController.setMotorForward(0);
}

void Platform::movePlatformBackward(int32_t distanceMillimeters) {
    motorController.setMotorReverse(40);
    int16_t degrees = -(distanceMillimeters * 1000) / umPerDegree;
    waitUntilRotations(degrees * (countsPerRotation / 360));
    motorController.setMotorReverse(0);
}

void Platform::waitUntilRotations(int32_t rotations) {

    int32_t count = 0;
    int8_t previousA = hallSensorPinA.get();
    int8_t previousB = hallSensorPinB.get();
    int8_t newA = 0;
    int8_t newB = 0;

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

void Platform::caclulateNewCount(const int8_t &newA, const int8_t &newB, const int8_t &previousA, int32_t &count) {
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
