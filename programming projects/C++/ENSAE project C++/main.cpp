#include <iostream>
#include "BlackScholesMerton.hpp"
#include "Class_MonteC.hpp"
using namespace std;

int main() {
    double S0 = 100.0;  // Initial price
    double K = 100.0;  // Strike price
    double T = 1.0;    // Time to maturity (1 year)
    double sigma = 0.2; // Volatility
    double r = 0.05;   // Risk-free rate
    bool type = true; // True: Call, False: Put
    int num_simulations = 100 ; //number of simulation 

    BlackScholesMerton bsmOption(S0, K, T, sigma, r, type);
    Class_MonteC mcOption(S0, K, T, sigma, r, type, num_simulations);

    if (bsmOption.is_bsm_applicable())
    {std::cout << "Price (BSM): " << bsmOption.price() << std::endl;}
    {std::cout << "Price (Monte Carlo): " << mcOption.price() << std::endl;}

 /*  Test de tous les prix possibles
   std::cout << "Black-Scholes-Merton Call Price: " << bsOption.callPrice() << std::endl;
    std::cout << "Black-Scholes Put Price: " << bsOption.putPrice() << std::endl;

    std::cout << "Monte Carlo Call Price: " << mcOption.callPrice() << std::endl;
    std::cout << "Monte Carlo Put Price: " << mcOption.putPrice() << std::endl; */

    return 0;
}