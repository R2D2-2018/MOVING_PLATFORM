/**
 * @file moving_platform.hpp
 * @brief     Moving platform class
 * @author    Olivier verwoerd & Maarten Wassenaar
 * @license   See LICENSE
 */
#include <stdint.h>

#ifndef MOVING_PLATFORM_HPP
#define MOVING_PLATFORM_HPP

namespace MovingPlatform {
/**
 * @brief Control the motors from the MotorController module.
 * This class communicates with the motorcontroller to control multiple moters
 * With this class a platforms movement can be set with ease
 */
class Platform {
    //? & leftMotor;
    //? & rightMotor;
    short currentSpeedLeft, currentSpeedRight;
    short wheelsize;
    short smoothing;
    short speed;

  public:
    enum class Direction { Forward, Backward };

    // Platform(? & leftMotor, ? & rightMotor);
    Platform();

    /**
     * @brief moves the platform
     *
     * Move the platform in *direction* for *distance* amount of cm.
     * Direction is forward or backward.
     *
     * @param[in] distance the distance the motor has to travel, in cm
     * @param[in] Direction the direction the motor has to travel, forwards or backwards
     * @param[out] set speed of motorcontrollers.
     */
    void move(const uint32_t &distance, const Direction &direction);

    /**
     * @brief rotate the platform
     *
     * Turn the platform a certain angle. The range is between -360 and 360.
     *
     * @param[in] angle : the angle the platform has to turn from its current orientation
     * @param[out] set speed of motorcontrollers.
     */
    void rotate(short angle);

    /**
     * @brief Stops the platform immediately
     *
     * Stops the motors without any smoothing as quick as possible.
     */
    void emergencyStop();

    // SETTERS AND GETTERS
    /**
     * @brief getter for WheelSize
     *
     * returns wheelSize as short
     */
    short getWheelSize();

    /**
     * @brief setter for WheelSize
     *
     * @param[in] mm : new wheelsize value in millimeters
     */
    void setWheelSize(short mm);
    /**
     * @brief setter for Smoothing
     *
     * @param[in] value : new smoothing value of motors in second/10.
     */
    void setSmoothing(short value);

    /**
     * @brief setter for Speed
     *
     * @param[in] newSpeed : new speed value
     */

    void setSpeed(short newSpeed);

    /**
     * @brief getter for Speed
     *
     * @return speed
     */

    short getSpeed();

    /**
     * @brief getter for Smoothing
     *
     * @return smoothing of motors in second/10.
     */
    short getSmoothing();
};
} // namespace MovingPlatform

#endif // MOVING_PLATFORM_HPP
