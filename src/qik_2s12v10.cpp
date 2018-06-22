#include "qik_2s12v10.hpp"

Qik2S12V10::Qik2S12V10(UARTLib::UARTConnection &serialConnection) : serialConnection(serialConnection) {
    serialConnection.send(0xAA);
}

uint8_t Qik2S12V10::getFirmware() {
    serialConnection.send(0x81); ///< 0x81 is the get firmware version command.
    auto timeout = hwlib::now_us() + 10000;
    while ((serialConnection.available() == 0) && (hwlib::now_us() < timeout)) {
    }
    //hwlib::cout << "Available: " << serialConnection.available() << hwlib::endl;
    return serialConnection.receive() - '0';
}

uint8_t Qik2S12V10::getErrorByte() {
    serialConnection.send(0x82); ///< 0x82 is the get error byte command.
    auto timeout = hwlib::now_us() + 10000;
    while ((serialConnection.available() == 0) && (hwlib::now_us() < timeout)) {
    }
    //hwlib::cout << "Available: " << serialConnection.available() << hwlib::endl;
    return serialConnection.receive();
}

uint8_t Qik2S12V10::getConfigParameter(ConfigParameters parameter) {
    uint8_t data[] = {0x83, static_cast<uint8_t>(parameter)};
    serialConnection.send(data, 2);
    auto timeout = hwlib::now_us() + 10000;
    while ((serialConnection.available() == 0) && (hwlib::now_us() < timeout)) {
    }
    //hwlib::cout << "Available: " << serialConnection.available() << hwlib::endl;
    return serialConnection.receive();
}

uint8_t Qik2S12V10::setConfigParameter(ConfigParameters parameter, uint8_t value) {
    uint8_t data[] = {0x84, static_cast<uint8_t>(parameter), value, 0x55, 0x2A};
    serialConnection.send(data, 5);
    auto timeout = hwlib::now_us() + 10000;
    while ((serialConnection.available() == 0) && (hwlib::now_us() < timeout)) {
    }
    //hwlib::cout << "Available: " << serialConnection.available() << hwlib::endl;
    return serialConnection.receive();
}
