#include "dyno.hpp"
#include <iostream>
#include <sstream>

void reader(const std::string& line) {
    double rpm, torque, temp, horsepower;
    char comma1, comma2, comma3;

    std::stringstream ss(line);
    ss >> rpm >> comma1 >> torque >> comma2 >> temp >> comma3 >> horsepower;

    std::cout << "RPM: "        << rpm        << '\n';
    std::cout << "Torque: "     << torque     << '\n';
    std::cout << "Temp: "       << temp       << '\n';
    std::cout << "Horsepower: " << horsepower << '\n';
    std::cout << "----------------\n";
}