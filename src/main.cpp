#include "qik_2s12v10.hpp"
#include "uart_lib.hpp"
#include "wrap-hwlib.hpp"
#include <stdint.h>

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;

    hwlib::wait_ms(1000);

    UARTLib::HardwareUART serialCon(115200, UARTLib::UARTController::TWO);

    auto motorCon = Qik2S12V10(serialCon);

    motorCon.setConfigParameter(Qik2S12V10::ConfigParameters::DeviceID, 10);
    hwlib::cout << static_cast<int>(motorCon.getConfigParameter(Qik2S12V10::ConfigParameters::DeviceID)) << hwlib::endl;
    hwlib::cout << static_cast<int>(motorCon.getErrorByte()) << hwlib::endl;

    return 0;
}
