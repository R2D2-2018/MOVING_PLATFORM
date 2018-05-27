#include "wrap-hwlib.hpp"
#include "moving-platform.hpp"

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;

    hwlib::wait_ms(1000);
    Platform test;
    int x = test.getOffset();
    hwlib::cout << "Hello world!" << hwlib::endl;
    hwlib::cout << x << hwlib::endl;
    return 0;
}
