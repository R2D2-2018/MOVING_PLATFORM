#include "UART_Lib/uart_lib.hpp"
#include "qik_2s12v10.hpp"
#include "wrap-hwlib.hpp"
#include <stdint.h>

using MotorController = Qik2S12V10;

void waitUntilRotations(int32_t rotations);

void rotateUntil(MotorController &ctrl, int32_t rotations) {
    if (rotations > 0) {
        ctrl.setMotorForward(30, MotorController::Motors::M1);
        ctrl.setMotorReverse(30, MotorController::Motors::M0);
        waitUntilRotations(rotations);
    } else {
        ctrl.setMotorForward(30, MotorController::Motors::M0);
        ctrl.setMotorReverse(30, MotorController::Motors::M1);
        waitUntilRotations(rotations);
    }

    ctrl.setMotorForward(0);
    ctrl.getMotorSpeed(MotorController::Motors::M0);
}

void waitUntilRotations(int32_t rotations) {
    auto HallSensorPinA = hwlib::target::pin_in(hwlib::target::pins::d6);
    auto HallSensorPinB = hwlib::target::pin_in(hwlib::target::pins::d7);

    int32_t count = 0;
    int32_t previousA = HallSensorPinA.get();
    int32_t previousB = HallSensorPinB.get();
    int32_t newA = 0;
    int32_t newB = 0;

    constexpr uint16_t counts_per_rotation = 3200;

    while (count < rotations) {
        newA = HallSensorPinA.get();
        newB = HallSensorPinB.get();

        if (newA == previousA && newB == previousB) {
            continue;
        }

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
        if (count % 400 == 0) {
            hwlib::cout << count << hwlib::endl;
        }
        previousA = newA;
        previousB = newB;
    }
}

constexpr uint32_t rotations_per_degree = 24;

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;

    hwlib::wait_ms(1000);

    UARTLib::HardwareUART serialCon(115200, UARTLib::UARTController::TWO);

    auto motorCon = Qik2S12V10(serialCon);
    auto HallSensorPinA = hwlib::target::pin_in(hwlib::target::pins::d6);
    auto HallSensorPinB = hwlib::target::pin_in(hwlib::target::pins::d7);
    rotateUntil(motorCon, rotations_per_degree * 180);
    hwlib::wait_ms(1000);
    motorCon.setMotorForward(120);
    hwlib::wait_ms(1000);
    motorCon.setMotorForward(0);
    hwlib::wait_ms(1000);

    rotateUntil(motorCon, rotations_per_degree * 180);
    hwlib::wait_ms(1000);
}
