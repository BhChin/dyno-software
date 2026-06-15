#include <iostream>
#include <thread>
#include <chrono>

// a program that simulates output from the teensy 4.1
// typically the teensy will use Serial.print() instead of cout
// and we'll use loop() instead of a while (True)

// sensors: hall sensor (rpm), temp reader (temperature), load cell (torque)
// teensy: prints some format of rpm, torque, temp, horsepower
// dyno software: parses what the teensy sends, does calculations

// data flow:
// sensors -> teensy -> dyno software


int main() {
    double rpm = 0; 
    double torque = 0;
    double temp = 0;

    while (rpm != 1000) {
        rpm += 50;
        torque += 0.1;
        temp += 0.05;

        double horsepower = torque * rpm / 5252.0;

        std::cout << rpm << "," << torque << "," << temp << "," << horsepower << '\n';

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    return 0;
}




