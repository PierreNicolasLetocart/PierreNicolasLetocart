#include "Class_MonteC.hpp"

Class_MonteC::Class_MonteC(double S0, double K, double T, double sigma, double r, bool type, int num_simulations)
    : Class_Option(S0, K, T, sigma, r, type), num_simulations(num_simulations) {}

double Class_MonteC::price() const {
    std::mt19937 generator(std::random_device{}());
    std::normal_distribution<double> normal(0.0, 1.0);

    double sum_payoffs = 0.0;
    for (int i = 0; i < num_simulations; ++i) {
        double Z = normal(generator);
        double ST = S0 * std::exp((r - 0.5 * sigma * sigma) * T + sigma * std::sqrt(T) * Z);

        double payoff = 0.0;
        if (type) {
            payoff = std::max(ST - K, 0.0);
        } else {
            payoff = std::max(K - ST, 0.0);
        }

        sum_payoffs += payoff;
    }

    return std::exp(-r * T) * (sum_payoffs / num_simulations);
}
