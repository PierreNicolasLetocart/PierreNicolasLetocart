import numpy as np 
from scipy.stats import norm 

class BlackScholes:
    def __init__(self, S, K, T, r, sigma):
        self.S = S      #Prix du sous-jacent (price of the underlying)
        self.K = K      #Prix d'exercice (strike price)
        self.T = T      #Temps à l'échéance (time to maturity)
        self.r = r      #Taux d'intérêt sans risque (risk-free interest rate)
        self.sigma = sigma  #Volatilité (Volatility)

    def price(self, option_type='call'):
        d1 = (np.log(self.S / self.K) + (self.r + 0.5 * self.sigma**2)*self.T) / (self.sigma * np.sqrt(self.T))
        d2 = d1 - self.sigma * np.sqrt(self.T)
        if option_type == 'call':
            return self.S * norm.cdf(d1) - self.K * np.exp(-self.r *self.T) * norm.cdf(d2)
        elif option_type == 'put':
            return self.K * np.exp(-self.r * self.T) * norm.cdf(-d2) - self.S * norm.cdf(-d1)