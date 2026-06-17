#include <iostream>

#ifndef PID_HPP
#define PID_HPP

double constexpr k_p = 0.0;
double constexpr k_i = 0.0;
double constexpr k_d = 0.0;

double computePID(double setpoint, double measured);
    
#endif