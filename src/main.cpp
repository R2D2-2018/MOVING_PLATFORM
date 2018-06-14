#include "moving_platform.hpp"
#include "motor_interface.hpp"
#include "wrap-hwlib.hpp"

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;

    hwlib::wait_ms(1000);
    MovingPlatform::Platform test;
    hwlib::cout << "Hello world!" << test.getWheelSize() << hwlib::endl;

    return 0;
}
