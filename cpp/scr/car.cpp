#include "engine.h"
#include "wheel.h"
#include <iostream>
#include <array>

class Car {
    protected:
    Engine* engine;
    std::array<Wheel, 4> wheels;
};
