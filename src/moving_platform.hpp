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
    short offset;
    short smoothing;
    short speed;

  public:
    // Platform(? & leftMotor, ? & rightMotor);
    Platform();

    /**
     * @brief move with turn
     *
     * @param[in] speed in a range 255 to -255
     * @param[in] turn ratio devided by 10
     * @param[out] set speed of motorcontrollers.
     */
    void move(short speed, short turn);

    /**
     * @brief rotate
     *
     * Rotates the platform
     *
     * @param[in] rotation in ##UNDEFINED unless servo than deg.
     * @param[out] set speed of motorcontrollers.
     */
    void rotate(short deg);
    /**
     * @brief rotate
     *
     * @param[in] rotation in ##UNDEFINED unless servo than deg.
     * @param[in] Custom speed. otherwise half speed
     * @param[out] set speed of motorcontrollers.
     */
    void rotate(short deg, short speed);
    /**
     * @brief Stop
     *
     * Stops the motor without any smoothing.
     *
     * @param[out] speed of motors to direct 0;
     */
    void emergencyStop();

    // SETTERS AND GETTERS
    /**
     * @brief getWheelSize
     *
     * returns wheelSize as short
     */
    short getWheelSize();

    /**
     * @brief setWheelSize
     *
     * @param[in] set wheelsize in mm
     */
    void setWheelSize(short mm);
    /**
     * @brief getSmoothing
     *
     * @param[in] set smoothing of motors in second/10.
     */
    void setSmoothing(short value);

    /**
     * @brief setSpeed
     *
     * @param[in] set speed to new value
     */

    void setSpeed(short newSpeed);

    /**
     * @brief getSpeed
     *
     * @return speed
     */

    short getSpeed();

    /**
     * @brief getSmoothing
     *
     * @return smoothing of motors in second/10.
     */
    short getSmoothing();
};
} // namespace MovingPlatform

#endif // MOVING_PLATFORM_HPP
