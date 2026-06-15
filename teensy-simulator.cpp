#include <iostream>
#include <sstream>
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

//dyno
void reader(const std::string& line) {
    double rpm;
    double torque;
    double temp;
    double horsepower;
    char comma1, comma2, comma3;

    std::stringstream ss(line);

    ss >> rpm >> comma1
       >> torque >> comma2
       >> temp >> comma3
       >> horsepower;

    std::cout << "Parsed:\n";
    std::cout << "RPM: " << rpm << '\n';
    std::cout << "Torque: " << torque << '\n';
    std::cout << "Temp: " << temp << '\n';
    std::cout << "Horsepower: " << horsepower << '\n';
    std::cout << "----------------\n";
}

// teensy
int main() {
    double rpm = 0; 
    double torque = 0;
    double temp = 0;

    while (rpm != 1000) {
        rpm += 50;
        torque += 0.1;
        temp += 0.05;

        double horsepower = torque * rpm / 5252.0;

        // simulates the teensy sending the output
        std::stringstream teensyOutput;
        teensyOutput
            << rpm << ","
            << torque << ","
            << temp << ","
            << horsepower;

        std::string line = teensyOutput.str();

        // simulates the dyno software recieving the teensy output
        reader(line);

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    return 0;
}

