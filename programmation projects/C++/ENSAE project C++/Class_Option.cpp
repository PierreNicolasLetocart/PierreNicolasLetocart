#include "Class_Option.hpp"

//Initializes the attributes of the Option object with user-provided values 
Class_Option::Class_Option(double S0, double K, double T, double sigma, double r, bool type):
    S0(S0), K(K), T(T), sigma(sigma), r(r), type(type) {}


//Checks if the option satisfies the conditions for using the BSM model (positive volatility and time)
bool Class_Option::is_bsm_applicable() const {
    return (sigma > 0 && T > 0);
}
