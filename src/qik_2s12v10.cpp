#include "qik_2s12v10.hpp"

Qik2S12V10::Qik2S12V10(UARTLib::UARTConnection &serialConnection) : serialConnection(serialConnection) {
    serialConnection.send(0xAA); // this command automaticly sets the baudrate on the motorcontroller
}

uint8_t Qik2S12V10::getFirmware() {
    serialConnection.send(static_cast<uint8_t>(Command::GetFirmwareVersion)); ///< 0x81 is the get firmware version command.
    auto timeout = hwlib::now_us() + 10000;
    while ((serialConnection.available() == 0) && (hwlib::now_us() < timeout)) {
    }
    return serialConnection.receive() - '0';
}

uint8_t Qik2S12V10::getErrorByte() {
    serialConnection.send(static_cast<uint8_t>(Command::GetErrorByte)); ///< 0x82 is the get error byte command.
    auto timeout = hwlib::now_us() + 10000;
    while ((serialConnection.available() == 0) && (hwlib::now_us() < timeout)) {
    }
    return serialConnection.receive();
}

uint8_t Qik2S12V10::getConfigParameter(ConfigParameters parameter) {
    uint8_t data[] = {static_cast<uint8_t>(Command::GetConfigParameter), static_cast<uint8_t>(parameter)};
    serialConnection.send(data, 2);
    auto timeout = hwlib::now_us() + 10000;
    while ((serialConnection.available() == 0) && (hwlib::now_us() < timeout)) {
    }
    return serialConnection.receive();
}

uint8_t Qik2S12V10::setConfigParameter(ConfigParameters parameter, uint8_t value) {
    uint8_t data[] = {static_cast<uint8_t>(Command::SetConfigParameter), static_cast<uint8_t>(parameter), value, 0x55,
                      0x2A}; // 0x55 and 0x2A are required to prevent accidental setting of this command.
    serialConnection.send(data, 5);
    auto timeout = hwlib::now_us() + 10000;
    while ((serialConnection.available() == 0) && (hwlib::now_us() < timeout)) {
    }
    return serialConnection.receive();
}

void Qik2S12V10::setMotorBrake(uint8_t value, Motors motor) {
    if (motor == Motors::Both || motor == Motors::M0) {
        serialConnection.send(static_cast<uint8_t>(Command::BrakeMotorM0));
        serialConnection.send(value);
    }
    if (motor == Motors::Both || motor == Motors::M1) {
        serialConnection.send(static_cast<uint8_t>(Command::BrakeMotorM1));
        serialConnection.send(value);
    }
}

void Qik2S12V10::setMotorForward(uint8_t speed, Motors motor) {
    setMotorData(speed, motor, static_cast<uint8_t>(Command::ForwardMotorM0), static_cast<uint8_t>(Command::ForwardMotorM1));
}

void Qik2S12V10::setMotorReverse(uint8_t speed, Motors motor) {
    setMotorData(speed, motor, static_cast<uint8_t>(Command::ReverseMotorM0), static_cast<uint8_t>(Command::ReverseMotorM1));
}

uint8_t Qik2S12V10::getMotorCurrent(Motors motor) {
    return getMotorInformation(motor, static_cast<uint8_t>(Command::GetMotorM0Current));
}

uint8_t Qik2S12V10::getMotorSpeed(Motors motor) {
    return getMotorInformation(motor, static_cast<uint8_t>(Command::GetMotorM0Speed));
}

uint8_t Qik2S12V10::getMotorInformation(Motors motor, uint8_t command) {
    if (motor == Motors::Both || motor == Motors::M0) {
        serialConnection.send(command);
    }
    auto timeout = hwlib::now_us() + 10000;
    while ((serialConnection.available() == 0) && (hwlib::now_us() < timeout)) {
    }
    uint8_t value = serialConnection.receive();
    if (motor == Motors::Both || motor == Motors::M1) {
        serialConnection.send(command + 1);
    }
    timeout = hwlib::now_us() + 10000;
    while ((serialConnection.available() == 0) && (hwlib::now_us() < timeout)) {
    }
    if (motor == Motors::Both) {
        return ((value + serialConnection.receive()) / 2);
    }
    return serialConnection.receive();
}

void Qik2S12V10::setMotorData(uint8_t speed, Motors motor, uint8_t command1, uint8_t command2) {
    if (speed > 127) {
        speed = 127;
    }
    uint8_t data[] = {command1, speed};
    if (motor == Motors::Both) {
        serialConnection.send(data, 2);
        data[0] = command2;
        serialConnection.send(data, 2);
    } else if (motor == Motors::M0) {
        serialConnection.send(data, 2);
    } else {
        data[0] = command2;
        serialConnection.send(data, 2);
    }
}
