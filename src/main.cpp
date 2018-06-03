#include "wrap-hwlib.hpp"
#include "moving-platform.hpp"

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;

    hwlib::wait_ms(1000);
    Platform test;
    hwlib::cout << "Hello world!" << hwlib::endl;
    return 0;
}
