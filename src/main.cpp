#include "UART_Lib/uart_lib.hpp"
#include "qik_2s12v10.hpp"
#include "wrap-hwlib.hpp"
#include <stdint.h>

using MotorController = Qik2S12V10;

constexpr uint32_t rotations_per_degree = 24;
constexpr uint8_t radiusMm = 62;
constexpr uint16_t circumferenceMm = 2 * 3.14159265359 * radiusMm;
constexpr uint16_t umPerDegree = (circumferenceMm * 1000) / 360;
constexpr uint16_t counts_per_rotation = 3200;

void waitUntilRotations(int32_t rotations);

void rotatePlatformUntil(MotorController &ctrl, int32_t rotations) {
    if (rotations > 0) {
        ctrl.setMotorForward(20, MotorController::Motors::M1);
        ctrl.setMotorReverse(20, MotorController::Motors::M0);
        waitUntilRotations(rotations);
    } else {
        ctrl.setMotorForward(20, MotorController::Motors::M0);
        ctrl.setMotorReverse(20, MotorController::Motors::M1);
        waitUntilRotations(rotations);
    }
    ctrl.setMotorForward(0);
    ctrl.getMotorSpeed(MotorController::Motors::M0);
}

void movePlatformForward(MotorController &ctrl, int32_t distanceMilliMeters) {
    ctrl.setMotorForward(20);
    uint16_t degrees = (distanceMilliMeters * 1000) / umPerDegree;
    // hwlib::cout << "moving the motor " << int(degrees) << " degrees" << hwlib::endl;
    waitUntilRotations(degrees * (counts_per_rotation / 360));
}

void movePlatformBackward(MotorController &ctrl, int32_t distanceMilliMeters) {
    ctrl.setMotorReverse(20);
    int16_t degrees = -(distanceMilliMeters * 1000) / umPerDegree;
    waitUntilRotations(degrees * (counts_per_rotation / 360));
}

void caclulateNewCount(const int32_t &newA, const int32_t &newB, const int32_t &previousA, int32_t &count) {
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

void waitUntilRotations(int32_t rotations) {
    auto HallSensorPinA = hwlib::target::pin_in(hwlib::target::pins::d6);
    auto HallSensorPinB = hwlib::target::pin_in(hwlib::target::pins::d7);

    int32_t count = 0;
    int32_t previousA = HallSensorPinA.get();
    int32_t previousB = HallSensorPinB.get();
    int32_t newA = 0;
    int32_t newB = 0;

    while (rotations > 0 ? (count < rotations) : (count > rotations)) {
        newA = HallSensorPinA.get();
        newB = HallSensorPinB.get();

        if (newA == previousA && newB == previousB) {
            continue;
        }

        caclulateNewCount(newA, newB, previousA, count);

        if (count % 400 == 0) {
            hwlib::cout << count << hwlib::endl;
        }
        previousA = newA;
        previousB = newB;
    }
}

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;

    hwlib::wait_ms(1000);

    UARTLib::HardwareUART serialCon(115200, UARTLib::UARTController::TWO);

    hwlib::cout << "circumference in mm " << (int)circumferenceMm << hwlib::endl;
    hwlib::cout << "umPerDegree in um " << (int)umPerDegree << hwlib::endl;

    auto motorCon = Qik2S12V10(serialCon);
    auto HallSensorPinA = hwlib::target::pin_in(hwlib::target::pins::d6);
    auto HallSensorPinB = hwlib::target::pin_in(hwlib::target::pins::d7);

    // rotatePlatformUntil(motorCon, rotations_per_degree * 180);

    movePlatformForward(motorCon, 1000);
    movePlatformBackward(motorCon, 1000);
    // hwlib::wait_ms(1000);
    // motorCon.setMotorForward(30);
    // hwlib::wait_ms(1000);
    // motorCon.setMotorForward(0);
    // hwlib::wait_ms(1000);

    // rotatePlatformUntil(motorCon, rotations_per_degree * 180);
    hwlib::wait_ms(1000);
    motorCon.setMotorReverse(0);
    motorCon.setMotorReverse(0);
}
