#include <iostream>
#include <cmath>

// Constants for tuning, change these values to modify the performance
const float STOCK_BOOST = 10.0f;  // Stock boost pressure (psi)
const float MAX_BOOST = 35.0f;   // Maximum safe boost pressure (psi)
const float STOCK_TIMING = 10.0f; // Stock ignition timing (degrees)
const float MAX_TIMING_ADVANCE = 25.0f; // Maximum timing advance (degrees)
const float FUEL_EFFICIENCY = 1.0f;  // Fuel efficiency multiplier

class EngineControlUnit {
public:
    // Variables representing tuning parameters
    float boostPressure;  // Boost pressure in psi
    float ignitionTiming; // Ignition timing in degrees
    float fuelFlowRate;   // Fuel flow rate in cc/min
    
    EngineControlUnit() : boostPressure(STOCK_BOOST), ignitionTiming(STOCK_TIMING), fuelFlowRate(2184.0f) {}

    // Method to apply Stage 2 tuning
    void applyStage2Tune() {
        // Increase boost pressure for more power
        boostPressure = STOCK_BOOST + (MAX_BOOST - STOCK_BOOST) * 0.8f; // Increase 80% of the max boost range

        // Advanced ignition timing for aggressive power
        ignitionTiming = STOCK_TIMING + MAX_TIMING_ADVANCE * 0.7f; // Increase 70% of the max timing advance

        // Adjust fuel flow rate for better fuel delivery under boost
        fuelFlowRate *= FUEL_EFFICIENCY * 1.2f; // Increase fuel flow by 20% to support extra air/fuel demand
        
        std::cout << "Stage 2 Tuning Applied:" << std::endl;
        std::cout << "Boost Pressure: " << boostPressure << " psi" << std::endl;
        std::cout << "Ignition Timing: " << ignitionTiming << " degrees" << std::endl;
        std::cout << "Fuel Flow Rate: " << fuelFlowRate << " cc/min" << std::endl;
    }

    // Simulate the engine behavior after tuning
    void simulateEngine() {
        // Simulate engine performance after tuning
        float powerOutput = (boostPressure * ignitionTiming) / 10.0f;
        float fuelEfficiency = fuelFlowRate / 500.0f;

        std::cout << "Engine Power Output: " << powerOutput << " hp" << std::endl;
        std::cout << "Fuel Efficiency: " << (fuelEfficiency * 100) << "%" << std::endl;
    }
};

int main() {
    EngineControlUnit ecu;
    
    std::cout << "Initial ECU Setup:" << std::endl;
    std::cout << "Boost Pressure: " << ecu.boostPressure << " psi" << std::endl;
    std::cout << "Ignition Timing: " << ecu.ignitionTiming << " degrees" << std::endl;
    std::cout << "Fuel Flow Rate: " << ecu.fuelFlowRate << " cc/min" << std::endl;

    // Apply Stage 2 tuning
    ecu.applyStage2Tune();

    // Simulate engine behavior after tuning
    ecu.simulateEngine();

    return 0;
}






