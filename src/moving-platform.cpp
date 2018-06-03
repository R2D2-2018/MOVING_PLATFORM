#include "moving-platform.hpp"
#include "wrap-hwlib.hpp"
namespace MovingPlatform{

	Platform::Platform(MotorController::MotorInterface & leftMotor, MotorController::MotorInterface & rightMotor):
	leftMotor(leftMotor), rightMotor(rightMotor)
	{
		wheelsize = 60;
		offset = 0;
		smoothing = 15;
    }
	
	void Platform::move(uint8_t speed){
		if(speed > 100 || speed < -100){
			return;
		}

	}

	void Platform::move(uint8_t speed, uint8_t turn){
		if(speed > 100 || speed < -100){
			return;
		}
	}

	void Platform::moveDistance(uint8_t distance, uint8_t speed){
		if(speed > 100 || speed < -100){
			return;
		}
		if((distance > 0 && speed < 0) || (distance < 0 && speed > 0)){
			speed = speed *1;
		}
	}

	void Platform::rotate(uint8_t deg){
		if(deg > 360 || deg < -360){
			return;
		}
	}

	void Platform::rotate(uint8_t deg, uint8_t speed){
		if(deg > 360 || deg < -360 || speed > 100 || speed < -100){
			return;
		}
	}

	void Platform::stop(){
		
	}


	//SET AND GET
	void Platform::setWheelsize(uint8_t mm){
		wheelsize = mm;
	}

	void Platform::setOffset(uint8_t value){
		offset = value;
	}

	void Platform::setSmoothing(uint8_t value){
		smoothing = value;
	}

	uint8_t Platform::getWheelsize(){
		return wheelsize;
	}
	
	uint8_t Platform::getOffset(){
		return offset;
	}

	uint8_t Platform::getSmoothing(){
		return smoothing;
	}


};
