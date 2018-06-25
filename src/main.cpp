#include "moving_platform.hpp"
#include "uart_lib.hpp"
#include "wrap-hwlib.hpp"
#include <stdint.h>

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;

    hwlib::wait_ms(1000);

    UARTLib::HardwareUART serialCon(115200, UARTLib::UARTController::TWO);
    UARTLib::HardwareUART bluetoothConnection(9600, UARTLib::UARTController::ONE);

    auto hallSensorPinA = hwlib::target::pin_in(hwlib::target::pins::d6);
    auto hallSensorPinB = hwlib::target::pin_in(hwlib::target::pins::d7);

    MovingPlatform::Platform platform(serialCon, hallSensorPinA, hallSensorPinB);
    platform.move(10, MovingPlatform::Platform::Direction::Forward);
    while (true) {
        if (bluetoothConnection.available() > 0) {
            const auto data = bluetoothConnection.receive();

            switch (data) {
            case 'F':
                hwlib::cout << "Motor forward" << hwlib::endl;
                platform.move(1, MovingPlatform::Platform::Direction::Forward);
                break;
            case 'B':
                hwlib::cout << "Motor backward" << hwlib::endl;
                break;
            case 'R':
                hwlib::cout << "Motor turn right" << hwlib::endl;
                break;
            case 'L':
                hwlib::cout << "Motor turn left" << hwlib::endl;
                break;
            default:
                hwlib::cout << "Received: " << data << hwlib::endl;
                break;
            }
        }
    }
    return 0;
}
