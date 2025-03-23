# 📘 Black-Scholes Python/C Hybrid

A high-performance Black-Scholes option pricing model written in **C** and wrapped in **Python** for fast execution.

## 🚀 Installation

### 1️⃣ Clone the Repository
```sh
git clone https://github.com/yourusername/black-scholes.git
cd black-scholes
```

### 2️⃣ Build & Install the Module
```sh
python3 setup.py build
python3 setup.py install
```

## ⚡ Usage
```python
import black_scholes

# Example: Calculate Call Option Price
price = black_scholes.call(S=147.30, K=150.0, r=0.001, t=60/365, sigma=0.45)
print(price)
```

## 🔧 Development

### Rebuild After Changes
```sh
rm -rf build
touch black_scholes/bs.c  # Ensure the C file is present
python3 setup.py build_ext --inplace
python3 setup.py install
```

### Test Installation
```sh
python3 -c "import black_scholes; print(black_scholes.__file__)"
```

## 💡 Troubleshooting

- **`ModuleNotFoundError: No module named 'black_scholes'`**
  - Ensure installation was successful:  
    ```sh
    python3 setup.py install
    ```
  - Check Python path:
    ```sh
    python3 -c "import site; print(site.getsitepackages())"
    ```

- **`error: 'Python.h' file not found`**
  - Install Python development headers:  
    ```sh
    xcode-select --install
    ```

## 📜 License
MIT License

