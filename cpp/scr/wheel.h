#ifndef WHEEL_CLASS_H
#define WHEEL_CLASS_H
#include <iostream>

class Wheel {
public:
    float getPressure();
    int getTemperature();
    int getRotation();
    int getDiameter();

    int getProfile();
    double getRpm();
    std::string& getVendor();
};

#endif 