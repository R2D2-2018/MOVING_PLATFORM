/**
 * @file moving-platform.hpp
 * @brief     Moving platform class
 * @author    Olivier verwoerd & Maarten Wassenaar
 * @license   See LICENSE
 */

#ifndef MOVING_PLATFORM_HPP
#define MOVING_PLATFORM_HPP

//namespace MovingPlatform{
    class Platform{
        ///This is designed to break. waiting for motorcontroller to 
        //? & leftMotor;
        //? & rightMotor; 
        int currentSpeedLeft, currentSpeedRight;
        int wheelsize;
        int offset;
        int smoothing;
        public:
        //Platform(? & leftMotor, ? & rightMotor);
        Platform();
        void move(int speed);
        void move(int speed, int turn);
        void moveDistance(int distance, int speed);
        void rotate(int deg);
        void rotate(int deg, int speed);
        void stop();

        //SET AND GET
        void setWheelsize(int mm);
        void setOffset(int value);
        void setSmoothing(int value);
        int getWheelsize();
        int getOffset();
        int getSmoothing();
    };
//}

#endif //MOVING_PLATFORM_HPP