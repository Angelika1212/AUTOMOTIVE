#include <iostream>
#include <string>

class Wheel {
    private:
     float pressure;
     int temperature;
     int rotation;
     int diameter;
     int profile;
     int speedIndex;
     int loadIndex;
     std::string vendor;

     public:
     Wheel() = default;

     Wheel(float pressure, int temperature, int rotation, int diameter, int profile, 
      int speedIndex, int loadIndex, std::string vendor)
        : pressure(pressure), temperature(temperature), 
          rotation(rotation), diameter(diameter), 
          profile(profile), speedIndex(speedIndex),
          loadIndex(loadIndex), vendor(vendor) {};

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
    Wheel w();
    std::cout << "Created wheel";

    return 0;
}