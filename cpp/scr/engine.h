#ifndef ENGINE_CLASS_H
#define ENGINE_CLASS_H
#include <iostream>

class Engine {
public:
    void start();
    void stop();
    double getTorque();
    std::string getType();

    void setRpm(double rpm);
    double getRpm();
    bool isRunning();
};

#endif 