# Pricing European Call and Put Options

In this project, I explore a fast way to price an option using the **Black-Scholes model**. 

The mathematics used here is written in **C** and wrapped in **Python** for user convenience. 

### Dependencies


### For macOS & Linux
```sh
python3 -m pip install --upgrade setuptools wheel

# Ensure Python development headers are installed (for macOS)
xcode-select --install
```

or

```sh
python -m pip install --upgrade setuptools wheel
```

### For Windows
```sh
pip install setuptools wheel
```

### Clone Repo
```sh
git clone https://github.com/yourusername/black-scholes.git
cd black-scholes
```

### Necessities
```sh
python3 setup.py build
python3 setup.py install
```

or

```sh
python setup.py build
python setup.py install
```

## How to run
```python
import bs
```
If that doesn't work

```python3
import black_scholes
```
You can now enter numbers for the relevant parameters.

```
s = 147.30    # Current stock price
k = 150.0     # Strike price
r = 0.001     # Risk-free interest rate
t = 60/365    # Time to expiration (in years)
sigma = 0.45  # Volatility
```
Pricing a call option
```
bs.bs_call(s, k, r, t, sigma)
```
You should obtain 
```
9.518562265392394
```
For a put option with the same parameters
```
bs.bs_put(s, k, r, t, sigma)
```
You should obtain 
```
12.1939067576814
```
---

Understanding the math behind this is **crucial**. 

This project holds an MIT License.

---

Feel free to email me: adam.bouchenaf23@gmail.com

