#include "moving_platform.hpp"
#include "wrap-hwlib.hpp"

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;

    hwlib::wait_ms(1000);
    MovingPlatform::Platform test;
    hwlib::cout << test.getWheelSize() << hwlib::endl;

    return 0;
}
