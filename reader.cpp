#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string line;

    while (std::getline(std::cin, line)) {
        double rpm;
        double torque;
        double temp;
        char comma1;
        char comma2;

        std::stringstream ss(line);

        ss >> rpm >> comma1 >> torque >> comma2 >> temp;

        std::cout << "RPM: " << rpm << "\n";
        std::cout << "Torque: " << torque << "\n";
        std::cout << "Temp: " << temp << "\n";
        std::cout << "------\n";
    }
}