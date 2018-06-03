#include "moving-platform.hpp"
#include "wrap-hwlib.hpp"
namespace MovingPlatform{
	//Platform(? & leftMotor, ? & rightMotor):
	//leftMotor(leftMotor), rightMotor(rightMotor)
	Platform::Platform()
	{
		wheelsize = 60;
		offset = 0;
		smoothing = 15;
    }
	
	void Platform::move(uint16_t speed){
		if(speed > 255 || speed < -255){
			return;
		}

	}

	void Platform::move(uint16_t speed, uint16_t turn){
		if(speed > 255 || speed < -255){
			return;
		}
	}

	void Platform::moveDistance(uint16_t distance, uint16_t speed){
		if(speed > 255 || speed < -255){
			return;
		}
		if((distance > 0 && speed < 0) || (distance < 0 && speed > 0)){
			speed = speed *1;
		}
	}

	void Platform::rotate(uint16_t deg){
		if(deg > 360 || deg < -360){
			return;
		}
	}

	void Platform::rotate(uint16_t deg, uint16_t speed){
		if(deg > 360 || deg < -360 || speed > 255 || speed < -255){
			return;
		}
	}

	void Platform::stop(){
		
	}


	//SET AND GET
	void Platform::setWheelsize(uint16_t mm){
		wheelsize = mm;
	}

	void Platform::setOffset(uint16_t value){
		offset = value;
	}

	void Platform::setSmoothing(uint16_t value){
		smoothing = value;
	}

	uint16_t Platform::getWheelsize(){
		return wheelsize;
	}

	uint16_t Platform::getOffset(){
		return offset;
	}

	uint16_t Platform::getSmoothing(){
		return smoothing;
	}


}