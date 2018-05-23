#include "moving-platform.hpp"
namespace MovingPlatform{
	//Platform(? & leftMotor, ? & rightMotor):
	//leftMotor(leftMotor), rightMotor(rightMotor)
	Platform::Platform()
	{

		wheelsize = 60;
		offset = 0;
		smoothing = 15;
    }
	
	void Platform::move(int speed){};
	void Platform::move(int speed, int turn){};
	void Platform::moveDistance(int distance, int speed){};
	void Platform::rotate(int deg){};
	void Platform::rotate(int deg, int speed){};
	void Platform::stop(){};

	//SET AND GET
	void Platform::setWheelsize(int mm){};
	void Platform::setOffset(int value){};
	void Platform::setSmoothing(int value){};
	int Platform::getWheelsize(){};
	int Platform::getOffset(){};
	int Platform::getSmoothing(){};

};