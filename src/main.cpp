#include "wrap-hwlib.hpp"
#include "moving-platform.hpp"

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;

    hwlib::wait_ms(1000);
    MovingPlatform::Platform test;
    hwlib::cout << "Hello world!" << test.getWheelsize() << hwlib::endl;

    return 0;
}
