#include "BlackScholesMerton.hpp"
#include <cmath>


BlackScholesMerton::BlackScholesMerton(double S0, double K, double T, double sigma, double r, bool type)
             : Class_Option(S0, K, T, sigma, r, type) {};

BlackScholesMerton::~BlackScholesMerton() {}

double BlackScholesMerton::callPrice() const {
    double d1 = (std::log(S0 / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * std::sqrt(T));
    double d2 = d1 - sigma * std::sqrt(T);
    return S0 * std::erfc(-d1 / std::sqrt(2)) / 2 - K * std::exp(-r * T) * std::erfc(-d2 / std::sqrt(2)) / 2;
} //Je vais expliquer le erfc dans le comte-rendu en gros on a CDF_Norm(x)=0,5*erfc(-x/sqrt(2))

double BlackScholesMerton::putPrice() const {
    double d1 = (std::log(S0 / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * std::sqrt(T));
    double d2 = d1 - sigma * std::sqrt(T);
    return K * std::exp(-r * T) * std::erfc(d2 / std::sqrt(2)) / 2 - S0 * std::erfc(d1 / std::sqrt(2)) / 2;
}

double BlackScholesMerton::price() const {
  if ((*this).type==1){return (*this).callPrice();}
  else {return (*this).putPrice();}
}