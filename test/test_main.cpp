#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../src/moving-platform.hpp"

TEST_CASE( "Get and set" ) {
    MovingPlatform::Platform test;
    test.setOffset(10);
    test.setSmoothing(10);
    test.setWheelSize(10);
    REQUIRE(test.getOffset() == 10);
    REQUIRE(test.getSmoothing() == 10);
    REQUIRE(test.getWheelSize() == 10);
    test.setOffset(2);
    test.setSmoothing(2);
    test.setWheelSize(2);
    REQUIRE(test.getOffset() == 2);
    REQUIRE(test.getSmoothing() == 2);
    REQUIRE(test.getWheelSize() == 2);
}

