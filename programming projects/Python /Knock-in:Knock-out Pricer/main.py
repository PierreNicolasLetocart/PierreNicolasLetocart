from models.black_scholes import BlackScholes

def main():
    S = 100
    K = 110
    T = 1.0
    r = 0.05
    sigma = 0.2

    bsm = BlackScholes(S, K=K, T=T, r=r, sigma=sigma)
    european_call_price = bsm.price(option_type='call')
    european_put_price = bsm.price(option_type='put')
    print(f"Prix de l'option européenne (call): {european_call_price:.2f}")
    print(f"Prix de l'option européenne (put); {european_put_price:.2f}")
if __name__ == '__main__':
    main()