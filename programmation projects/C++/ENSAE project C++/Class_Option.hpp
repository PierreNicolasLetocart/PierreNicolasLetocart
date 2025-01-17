#ifndef CLASS_OPTION_HPP  // Vérifie si la macro CLASS_OPTION_HPP n'est pas définie
#define CLASS_OPTION_HPP  // Si non, la définit

class Class_Option {
    protected:
        double S0;    // initial price 
        double K;     // Strike Price 
        double T;     // Maturity 
        double sigma; // Volatility 
        double r;     // risk-free interest rate
        bool type;  // call=1 and put=0
    
    public:
        Class_Option(double S0, double K, double T, double sigma, double r, bool type); //Constructor definition
        virtual double price() const =0;          //any derived class must implement this method to calculate the price of the option  
        virtual bool is_bsm_applicable() const;   //method providing a way to check whether or not BSM is applicable
        virtual ~Class_Option() = default;        //Ensures proper cleanup of derived objects when deleted through a base class pointer
    
};

#endif 