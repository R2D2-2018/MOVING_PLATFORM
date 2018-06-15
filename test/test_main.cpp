#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "motor_interface.hpp"
#include "moving_platform.hpp"

TEST_CASE("Get and set") {
    MovingPlatform::Platform test;
    test.setSmoothing(10);
    test.setWheelSize(10);
    REQUIRE(test.getSmoothing() == 10);
    REQUIRE(test.getWheelSize() == 10);
    test.setSmoothing(2);
    test.setWheelSize(2);
    REQUIRE(test.getSmoothing() == 2);
    REQUIRE(test.getWheelSize() == 2);
}

TEST_CASE("MotorInterface: Default interface") {
    MotorController::MotorInterface motorInterface;
    REQUIRE(motorInterface.getSelectedInterface() == MotorController::MotorInterface::INTERFACE::DC);
    REQUIRE(motorInterface.getSelectedInterface() != MotorController::MotorInterface::INTERFACE::STEPPER);
}
