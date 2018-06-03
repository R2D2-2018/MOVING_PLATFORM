/**
 * @file moving-platform.hpp
 * @brief     Moving platform class
 * @author    Olivier verwoerd & Maarten Wassenaar
 * @license   See LICENSE
 */

#ifndef MOVING_PLATFORM_HPP
#define MOVING_PLATFORM_HPP

namespace MovingPlatform{
    /**
     * @brief Platform
     * This class communicates with the motorcontroller to control multiple moters
     * With this class a platforms movement can be set with ease
     */
    class Platform{
        ///This is designed to break. waiting for motorcontroller to 
        //? & leftMotor;
        //? & rightMotor; 
        short currentSpeedLeft, currentSpeedRight;
        short wheelsize;
        short offset;
        short smoothing;
        public:
        //Platform(? & leftMotor, ? & rightMotor); 
        Platform();

        void move(short speed);
        /**
         * @brief move with turn
         * 
         * 
         * @param[in] speed in a range 255 to -255
         * @param[in] turn ratio devided by 10
         * @param[out] set speed of motorcontrollers.
         */
        void move(short speed, short turn);
      	/**
         * @brief move a certain distance if motor supports distance
         * 
         * @param[in] Distance in ##UNDEFINED
         * @param[in] speed in a range 255 to -255
         * @param[out] set speed of motorcontrollers.
         */
        void moveDistance(short distance, short speed);
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
        void stop();

        //SETTERS AND GETTERS
      	/**
         * @brief getWheelSize
         * 
         * @param[in] set wheelsize in mm
         */
        void setWheelSize(short mm);
      	/**
         * @brief getOffset
         * 
         * @param[in] set offset of motorcontroller in ##UNDEFINED.
         */
        void setOffset(short value);
      	/**
         * @brief getSmoothing
         * 
         * @param[in] set smoothing of motors in second/10.
         */
        void setSmoothing(short value);
      	/**
         * @brief getWheelSize
         * 
         * @return wheelsize in mm
         */
        short getWheelSize();
      	/**
         * @brief getOffset
         * 
         * @return offset of motorcontroller in ##UNDEFINED.
         */
        short getOffset();
      	/**
         * @brief getSmoothing
         * 
         * @return smoothing of motors in second/10.
         */
        short getSmoothing();
    };
}

#endif //MOVING_PLATFORM_HPP