# pragma once
#include "Class_Option.hpp"

class BlackScholesMerton : public Class_Option {
private:
    double callPrice() const;
    double putPrice() const;

public:
    BlackScholesMerton(double S0, double K, double T, double sigma, double r, bool type);
    ~BlackScholesMerton();
    virtual double price() const;
};
