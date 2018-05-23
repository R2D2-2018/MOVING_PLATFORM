#include "wrap-hwlib.hpp"
#include "MovingPlatform.hpp"

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;

    hwlib::wait_ms(1000);
    hwlib::cout << "Hello world!" << hwlib::endl;

    return 0;
}
