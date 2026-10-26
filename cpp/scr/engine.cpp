#include <iostream>
#include <string>

class Engine {
    protected:
    double max_power_hp;   
    double current_rpm;   
    bool is_running;  

    public:
    Engine(double power) : max_power_hp(power), current_rpm(0), is_running(false) {}
    virtual ~Engine() = default;

    virtual void start() = 0;
    virtual void stop() = 0;
    virtual double getTorque() const = 0; 
    virtual std::string getType() const = 0;

    void setRpm(double rpm) { current_rpm = rpm; }
    double getRpm() const { return current_rpm; }
    bool isRunning() const { return is_running; }
};

class PetrolEngine: public Engine  {};

class DieselEngine: public Engine  {};

class HybridEngine: public Engine  {};

class ElectricEngine: public Engine  {};

class GasEngine: public Engine  {};