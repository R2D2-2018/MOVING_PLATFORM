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
        uint16_t currentSpeedLeft, currentSpeedRight;
        uint16_t wheelsize;
        uint16_t offset;
        uint16_t smoothing;
        public:
        //Platform(? & leftMotor, ? & rightMotor); 
        Platform();

        void move(uint16_t speed);
        /**
         * @brief move with turn
         * 
         * 
         * @param[in] speed in a range 255 to -255
         * @param[in] turn ratio devided by 10
         * @param[out] set speed of motorcontrollers.
         */
        void move(uint16_t speed, uint16_t turn);
      	/**
         * @brief move a certain distance if motor supports distance
         * 
         * @param[in] Distance in ##UNDEFINED
         * @param[in] speed in a range 255 to -255
         * @param[out] set speed of motorcontrollers.
         */
        void moveDistance(uint16_t distance, uint16_t speed);
      	/**
         * @brief rotate
         * 
         * Rotates the platform
         * 
         * @param[in] rotation in ##UNDEFINED unless servo than deg.
         * @param[out] set speed of motorcontrollers.
         */
        void rotate(uint16_t deg);
		/**
         * @brief rotate
         * 
         * @param[in] rotation in ##UNDEFINED unless servo than deg.
         * @param[in] Custom speed. otherwise half speed
         * @param[out] set speed of motorcontrollers.
         */
        void rotate(uint16_t deg, uint16_t speed);
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
        void setWheelSize(uint16_t mm);
      	/**
         * @brief getOffset
         * 
         * @param[in] set offset of motorcontroller in ##UNDEFINED.
         */
        void setOffset(uint16_t value);
      	/**
         * @brief getSmoothing
         * 
         * @param[in] set smoothing of motors in second/10.
         */
        void setSmoothing(uint16_t value);
      	/**
         * @brief getWheelSize
         * 
         * @return wheelsize in mm
         */
        uint16_t getWheelSize();
      	/**
         * @brief getOffset
         * 
         * @return offset of motorcontroller in ##UNDEFINED.
         */
        uint16_t getOffset();
      	/**
         * @brief getSmoothing
         * 
         * @return smoothing of motors in second/10.
         */
        uint16_t getSmoothing();
    };
}

#endif //MOVING_PLATFORM_HPP