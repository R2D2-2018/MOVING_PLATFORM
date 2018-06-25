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
    UARTLib::UARTConnection &serialCon;
    Qik2S12V10 motorController;
    hwlib::pin_in &hallSensorPinA;
    hwlib::pin_in &hallSensorPinB;

    int16_t currentSpeedLeft, currentSpeedRight;
    int16_t wheelsize;
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
    void movePlatformForward(int32_t distanceMilliMeters);
    void movePlatformBackward(int32_t distanceMilliMeters);
    void waitUntilRotations(int32_t rotations);
    void caclulateNewCount(const int32_t &newA, const int32_t &newB, const int32_t &previousA, int32_t &count);

  public:
    Platform(UARTLib::UARTConnection &serialCon, hwlib::pin_in &hallSensorPinA, hwlib::pin_in &hallSensorPinB);

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
