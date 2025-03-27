import bs

def call(s, k, r, t, sigma):
    """ Wrapper function for Black-Scholes call option pricing """
    return bs.bs_call(s, k, r, t, sigma)

def put(s, k, r, t, sigma):
    """ Wrapper function for Black-Scholes put option pricing """
    return bs.bs_put(s, k, r, t, sigma)