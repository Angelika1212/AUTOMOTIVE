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

class InternalCombustionEngine : public Engine {
protected:
    double displacement_l; 
public:
    InternalCombustionEngine(double power, double volume) 
        : Engine(power), displacement_l(volume) {}

    void start() override {
        is_running = true;
        current_rpm = 800; 
        std::cout << "ДВС запущен. Обороты: " << current_rpm << std::endl;
    }

    void stop() override {
        is_running = false;
        current_rpm = 0;
        std::cout << "ДВС заглушен." << std::endl;
    }

    double getTorque() const override {
        // Упрощенная формула: момент зависит от оборотов
        if (!is_running) return 0;
        return (max_power_hp * 5252) / (current_rpm > 0 ? current_rpm : 1); 
    }
};

class PetrolEngine : public InternalCombustionEngine {
public:
    PetrolEngine(double power, double volume) : InternalCombustionEngine(power, volume) {}
    std::string getType() const override { return "Petrol"; }
};

class DieselEngine : public InternalCombustionEngine {
public:
    DieselEngine(double power, double volume) : InternalCombustionEngine(power, volume) {}
    std::string getType() const override { return "Diesel"; }
};

class ElectricEngine : public Engine {
public:
    ElectricEngine(double power) : Engine(power) {}

    void start() override {
        is_running = true;
        current_rpm = 0; 
        std::cout << "Электромотор включен. Максимальный момент доступен сразу." << std::endl;
    }

    void stop() override {
        is_running = false;
        std::cout << "Электромотор выключен." << std::endl;
    }

    double getTorque() const override {
        return is_running ? (max_power_hp * 5252) / 5000.0 : 0; 
    }

    std::string getType() const override { return "Electric"; }
};

class HybridEngine : public Engine {
    private:
    PetrolEngine* petrol;     
    ElectricEngine* electric;
    bool using_electric;
    
    public:
    HybridEngine(double total_power) : Engine(total_power) {
        petrol = new PetrolEngine(total_power * 0.6, 2.0); // 60% мощности от ДВС
        electric = new ElectricEngine(total_power * 0.4);    // 40% от электромотора
        using_electric = true;
    }

    ~HybridEngine() {
        delete petrol;
        delete electric;
    }

    void switchToElectric() { using_electric = true; }
    void switchToPetrol() { using_electric = false; }

    void start() override {
        is_running = true;
        if (using_electric) electric->start();
        else petrol->start();
    }

    void stop() override {
        is_running = false;
        electric->stop();
        petrol->stop();
    }

    double getTorque() const override {
        if (!is_running) return 0;
        return using_electric ? electric->getTorque() : petrol->getTorque();
    }

    std::string getType() const override {
        return "Hybrid (" + std::string(using_electric ? "Electric" : "Petrol") + ")";
    }
};