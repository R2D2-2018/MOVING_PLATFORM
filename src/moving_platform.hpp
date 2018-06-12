/**
 * @file moving_platform.hpp
 * @brief     Moving platform class
 * @author    Olivier verwoerd & Maarten Wassenaar
 * @license   See LICENSE
 */

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
    // Platform(? & leftMotor, ? & rightMotor);
    Platform();

    /**
     * @brief moves the platform
     *
     * Move the platform in *direction* for *distance* amount of cm.
     * Direction is forward or backward.
     * @param[in] speed in a range 255 to -255
     * @param[in] turn ratio devided by 10
     * @param[out] set speed of motorcontrollers.
     */
    void move(short speed, short turn);

    /**
     * @brief rotate the platform
     *
     * Turn the platform a certain angle. The range is between -360 and 360.
     *
     * @param[in] rotation in ##UNDEFINED unless servo than deg.
     * @param[out] set speed of motorcontrollers.
     */
    void rotate(short deg);

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
     * @param[in] set wheelsize in mm
     */
    void setWheelSize(short mm);
    /**
     * @brief getter for Smoothing
     *
     * @param[in] set smoothing of motors in second/10.
     */
    void setSmoothing(short value);

    /**
     * @brief setter for Speed
     *
     * @param[in] set speed to new value
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
