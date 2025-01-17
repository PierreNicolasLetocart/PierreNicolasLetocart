#include "Class_Option.hpp"
#include <random>
#include <algorithm>

class Class_MonteC : public Class_Option {
private:
    int num_simulations; // number of Monte Carlo simulation 

public:
    Class_MonteC(double S0, double K, double T, double sigma, double r, bool type, int num_simulations);
    double price() const override;   //Monte Carlo pricing method 
};
