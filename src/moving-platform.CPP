#include "moving-platform.hpp"
#include "wrap-hwlib.hpp"
//namespace MovingPlatform{
	//Platform(? & leftMotor, ? & rightMotor):
	//leftMotor(leftMotor), rightMotor(rightMotor)
	Platform::Platform()
	{
		wheelsize = 60;
		offset = 0;
		smoothing = 15;
    }
	
	void Platform::move(int speed){
		if(speed > 255 || speed < -255){
			return;
		}

	}

	void Platform::move(int speed, int turn){
		if(speed > 255 || speed < -255){
			return;
		}
	}

	void Platform::moveDistance(int distance, int speed){
		if(speed > 255 || speed < -255){
			return;
		}
		if((distance > 0 && speed < 0) || (distance < 0 && speed > 0)){
			speed = speed *1;
		}
	}

	void Platform::rotate(int deg){
		if(deg > 360 || deg < -360){
			return;
		}
	}

	void Platform::rotate(int deg, int speed){
		if(deg > 360 || deg < -360 || speed > 255 || speed < -255){
			return;
		}
	}

	void Platform::stop(){
		
	}


	//SET AND GET
	void Platform::setWheelsize(int mm){
		wheelsize = mm;
	}

	void Platform::setOffset(int value){
		offset = value;
	}

	void Platform::setSmoothing(int value){
		smoothing = value;
	}

	int Platform::getWheelsize(){
		return wheelsize;
	}
	
	int Platform::getOffset(){
		return offset;
	}

	int Platform::getSmoothing(){
		return smoothing;
	}


//};