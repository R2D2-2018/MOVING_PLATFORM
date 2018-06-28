/**
 * @file moving_platform.hpp
 * @brief     Moving platform class
 * @author    Olivier verwoerd, Maarten Wassenaar, Daniel van Vliet & Jasper Smienk.
 * @license   See LICENSE
 */
#include "qik_2s12v10.hpp"
#include "uart_lib.hpp"
#include "wrap-hwlib.hpp"

#ifndef MOVING_PLATFORM_HPP
#define MOVING_PLATFORM_HPP

namespace MovingPlatform {
/**
 * @brief Control the motors from the MotorController module.
 *
 * This class communicates with the motorcontroller to control multiple moters
 * With this class a platforms movement can be set with ease
 */
class Platform {
  private:
    UARTLib::UARTConnection &serialConnection;
    Qik2S12V10 motorController;
    hwlib::pin_in &hallSensorPinA;
    hwlib::pin_in &hallSensorPinB;

    int16_t currentSpeedLeft, currentSpeedRight;
    int16_t wheelSize;
    int16_t smoothing;
    int16_t speed;
    static constexpr uint32_t rotationsPerDegree = 24;
    static constexpr uint8_t radiusMm = 62;
    static constexpr uint16_t circumferenceMm = 2 * 3.14159265359 * radiusMm;
    static constexpr uint16_t umPerDegree = (circumferenceMm * 1000) / 360;
    static constexpr uint16_t countsPerRotation = 3200;

  public:
    enum class Direction { Forward, Backward };

  private:
    /**
     * @brief Moves the platform forward.
     *
     * Move the platform forward for *distanceMillimeters*.
     *
     * @param[in] distanceMillimeters The amount of millimeters the platform should move.
     */
    void movePlatformForward(int32_t distanceMillimeters);

    /**
     * @brief Moves the platform backward.
     *
     * Move the platform backward for *distanceMillimeters*.
     *
     * @param[in] distanceMillimeters The amount of millimeters the platform should move.
     */
    void movePlatformBackward(int32_t distanceMillimeters);

    /**
     * @brief Wait until a certain amount of rotations have passed.
     *
     * This function looks at the hall sensor and only returns after a certain amount of rotations of the hall sensor have passed.
     * This means that you have to be carefull to not give the wrong amount of rotations, otherwise it's stuck in the loops forever.
     *
     * @param[in] rotations The amount of rotations the hall sensor has to rotate.
     */
    void waitUntilRotations(int32_t rotations);

    /**
     * @brief Calculate the new amount of rotations.
     *
     * This function gets the new and old positions of the hall sensor and then figures out which direction the hall sensor is
     * moving and changed the count accordingly.
     *
     * @param[in] newA The new value of pin A of the hall sensor.
     * @param[in] newB The new value of pin B of the hall sensor.
     * @param[in] previousA The old value of pin A of the hall sensor.
     * @param[in] count The current amount of rotations.
     * @param[out] count The updated amount of rotations.
     */
    void caclulateNewCount(const int8_t &newA, const int8_t &newB, const int8_t &previousA, int32_t &count);

  public:
    Platform(UARTLib::UARTConnection &serialConnection, hwlib::pin_in &hallSensorPinA, hwlib::pin_in &hallSensorPinB);

    /**
     * @brief moves the platform
     *
     * Move the platform in *direction* for *distance* amount of centimeters.
     * Direction is forward or backward.
     *
     * @param[in] distance the distance the motor has to travel, in centimeters.
     * @param[in] Direction the direction the motor has to travel, forwards or backwards.
     * @param[out] set speed of motorcontrollers.
     */
    void move(const uint32_t &distance, const Direction &direction);

    /**
     * @brief Rotate the platform.
     *
     * Turn the platform a certain degrees.
     *
     * @param[in] angle The angle the platform has to turn from its current orientation.
     * @param[out] set speed of motorcontrollers.
     */
    void rotate(int16_t angle);

    /**
     * @brief Stops the platform immediately.
     *
     * Stops the motors without any smoothing as quick as possible.
     */
    void emergencyStop();

    /**
     * @brief Getter for WheelSize.
     *
     * returns Size of wheel in millimeters.
     */
    int16_t getWheelSize();

    /**
     * @brief Setter for WheelSize.
     *
     * @param[in] newWheelsize New wheelsize value in millimeters.
     */
    void setWheelSize(int16_t newWheelsize);

    /**
     * @brief Setter for Smoothing.
     *
     * @param[in] newSmoothing New smoothing value of motors in second/10.
     */
    void setSmoothing(int16_t newSmoothing);

    /**
     * @brief Setter for Speed.
     *
     * @param[in] newSpeed New speed value.
     */
    void setSpeed(int16_t newSpeed);

    /**
     * @brief Getter for Speed.
     *
     * @return Current speed of the motor.
     */
    int16_t getSpeed();

    /**
     * @brief Getter for Smoothing.
     *
     * @return Smoothing of motors in second/10.
     */
    int16_t getSmoothing();
};
} // namespace MovingPlatform

#endif // MOVING_PLATFORM_HPP
