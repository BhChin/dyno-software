#include <iostream>
#include <sstream>
#include <thread>
#include <chrono>
#include "dyno.hpp"

// teensy simulator
int main() {
    
    double rpm = 0; 
    double torque = 0;
    double temp = 0;

    while (rpm < 1000) {
        rpm += 50;
        torque += 0.1;
        temp += 0.05;

        double horsepower = torque * rpm / 5252.0;

    
        std::stringstream teensyOutput;
        teensyOutput << rpm << "," << torque << "," << temp << "," << horsepower;

        // simulates the teensy sending output and the dyno software recieving it
        reader(teensyOutput.str());

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    return 0;
}



