/**
 * @file
 * @brief     Interface class for the Qik 2S12V10.
 * @author    Jasper Smienk, Daniel van Vliet & Nick Bout.
 * @license   See LICENSE
 */

#ifndef QIK_2S12V10_H
#define QIK_2S12V10_H

#include "UART_Lib/uart_lib.hpp"
#include "wrap-hwlib.hpp"
#include <stdint.h>

class Qik2S12V10 {
  public:
    enum class ConfigParameters {
        DeviceID = 0,                     ///< Default: 10
        PWMParameter = 1,                 ///< Default: 0
        ShutdownOnError = 2,              ///< Default: 1
        SerialTimeout = 3,                ///< Default: 0
        MotorM0Acceleration = 4,          ///< Default: 0
        MotorM1Acceleration = 5,          ///< Default: 0
        MotorM0BrakeDuration = 6,         ///< Default: 0
        MotorM1BrakeDuration = 7,         ///< Default: 0
        MotorM0CurrentLimit = 8,          ///< Default: 0
        MotorM1CurrentLimit = 9,          ///< Default: 0
        MotorM0CurrentLimitResponse = 10, ///< Default: 4
        MotorM1CurrentLimitResponse = 11  ///< Default: 4
    };

    enum class Motors { M0, M1, Both };

  private:
    UARTLib::UARTConnection &serialConnection;

    /**
     * @brief Sends 2 bytes, returns uint8_t.
     *
     * This method is used by getMotorSpeed and getMotorCurrent, because they differ only in the command they send.
     * Depending on which Motors enum is given it returns information of one of the two motors. If both motors are selected it
     * returns the average.
     *
     * @param[in]   motor     Which motor you want to change.
     * @param[in]   command   The command used by Qik.
     * @return byte information: either of one of the motors, or average of the two.
     */
    uint8_t getMotorInformation(Motors motor, uint8_t command);

    /**
     * @brief Move motor forwards or backwards.
     *
     * Set the motor to move forwards or backwards with a given speed.
     * The resolution is between 0 and 127.
     * The given Motors enum determines which motor(s) is controlled,
     * forwards or backwards is determined by the commands passed.
     *
     * @param[in]   speed      Speed to set the motor two.
     * @param[in]   motor      Which motor you want to change.
     * @param[in]   command1   Command for motor1, either 0x88 (forward motor 1) or 0x8A (backwards motor 1).
     * @param[in]   command2   Command for motor2, either 0x8C (forward motor 2) or 0x8E (backwards motor 2).
     */
    void setMotorData(uint8_t speed, Motors motor, uint8_t command1, uint8_t command2);

  public:
    /**
     * @brief Constructor for Qik motor controller.
     *
     * This is a constructor for the Qik2S12V10 motor controller class.
     *
     * @param[in]   serialConnection    A uart serial connection that communicates with the Qik motor controller.
     */
    Qik2S12V10(UARTLib::UARTConnection &serialConnection);

    /**
     * @brief Get the firmware version.
     *
     * Get the firmware version of the Qik 2S12V10 chip, it should either be 1 or 2.
     *
     * @return Firmware version.
     */
    uint8_t getFirmware();

    /**
     * @brief Get the error byte.
     *
     * This function returns the error byte from the chip.
     * Each bit stands for an error when set. Starting at the least-significant bit 0, the errors are as followed:
     * Bit 0: Motor 0 fault.
     * Bit 1: Motor 1 fault.
     * Bit 2: Motor 0 over current.
     * Bit 3: Motor 1 over current.
     * Bit 4: Serial Hardware error.
     * Bit 5: CRC error.
     * Bit 6: Format error.
     * Bit 7: Timeout.
     * For a more detailed description of these error checkout the data sheet.
     * https://www.pololu.com/docs/pdf/0J29/qik_2s12v10.pdf
     *
     * @return Error byte of the chip.
     */
    uint8_t getErrorByte();

    /**
     * @brief Get a config parameter.
     *
     * This function will return the value off the given config parameter.
     *
     * @param[in]   parameter   The config parameter that you want the value off.
     * @return Value of the config parameter.
     */
    uint8_t getConfigParameter(ConfigParameters parameter);

    /**
     * @brief Set a config parameter.
     *
     * This function will set the value off the given config parameter.
     *
     * @param[in]   parameter   The config parameter that you want to set the value off.
     * @param[in]   value       The new value for the parameter.
     * @return 0 for OK, 1 for bad parameter, 2 for bad value.
     */
    uint8_t setConfigParameter(ConfigParameters parameter, uint8_t value);

    /**
     * @brief Set the motor brake.
     *
     * The relative amount of braking, 0 being no braking at all, 127 being full braking.
     *
     * @param[in]   value   Value between 0 and 127 for the breaking amount.
     * @param[in]   motor   Which motor you want to change.
     */
    void setMotorBrake(uint8_t value, Motors motor = Motors::Both);

    /**
     * @brief Move motor forward.
     *
     * Set the motor to move forward with a given speed.
     * The resolution is between 0 and 127.
     *
     * @param[in]   speed   Speed to set the motor two.
     * @param[in]   motor   Which motor you want to change.
     */
    void setMotorForward(uint8_t speed, Motors motor = Motors::Both);

    /**
     * @brief Move motor backwards.
     *
     * Set the motor to move backwards with a given speed.
     * The resolution is between 0 and 127.
     *
     * @param[in]   speed   Speed to set the motor two.
     * @param[in]   motor   Which motor you want to change.
     */
    void setMotorReverse(uint8_t speed, Motors motor = Motors::Both);

    /**
     * @brief Get the motor current.
     *
     * Get the average motor currents over the last 5 ms.
     * The returned value should be multiplied by 150mA to get an approximate real value.
     * Please note that the actual current could differ from this value by as much as 20%
     *
     * If both motors are selected, an average value between the two is returned.
     *
     * @param[in]   motor   Which motor you want to get the value off.
     */
    uint8_t getMotorCurrent(Motors motor = Motors::Both);

    /**
     * @brief Get the motor speed.
     *
     * Get the PWM speed that the controller is trying to set the motors to.
     * This value could not be an accurate value as the motor could be stuck while still returning 255.
     *
     * If both motors are selected, an average value between the two is returned.
     *
     * @param[in]   motor   Which motor you want to get the value off.
     */
    uint8_t getMotorSpeed(Motors motor = Motors::Both);
};

#endif // QIK_2S12V10_H
