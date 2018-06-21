#include "UART_Lib/uart_lib.hpp"
#include "qik_2s12v10.hpp"
#include "wrap-hwlib.hpp"
#include <stdint.h>

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;

    hwlib::wait_ms(1000);

    UARTLib::HardwareUART serialCon(115200, UARTLib::UARTController::TWO);

    auto motorCon = Qik2S12V10(serialCon);

    hwlib::cout << static_cast<int>(motorCon.getErrorByte()) << hwlib::endl;
    hwlib::cout << static_cast<int>(motorCon.getConfigParameter(Qik2S12V10::ConfigParameters::DeviceID)) << hwlib::endl;
    hwlib::cout << static_cast<int>(motorCon.getFirmware()) << hwlib::endl;

    return 0;
}
