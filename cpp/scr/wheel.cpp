#include <iostream>
#include <string>

class Wheel {
    private:
     float pressure;
     int temperature;
     int rotation;
     int diameter;
     int profile;
     std::string vendor;

     public:
     Wheel(float pressure, int temperature, int rotation, int diameter, int profile, std::string vendor)
        : pressure(pressure), temperature(temperature), 
          rotation(rotation), diameter(diameter), 
          profile(profile), vendor(vendor) {};

     float getPressure() const {
        return pressure;
     }

     int getTemperature() const {
        return temperature;
     }

     int getRotation() const {
        return rotation;
     }

     int getDiameter() const {
        return diameter;
     }

     int getProfile() const {
        return profile;
     }

     const std::string& getVendor() const {
        return vendor;
     }

};

int main() {
    Wheel w(2, 30, 0, 18, 3, "Any");
    std::cout << "Pressure " << w.getPressure() << " Pa";

    return 0;
}