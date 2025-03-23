from setuptools import setup, Extension
import sysconfig

python_include = "/Library/Frameworks/Python.framework/Versions/3.13/include/python3.13"

ext = Extension(
    'bs',
    sources=['black_scholes/bs.c'],
    include_dirs=[python_include]
)

setup(
    name="black_scholes",
    version="0.0.2",
    description="European Options Pricing Library with Call & Put Options",
    packages=['black_scholes'],
    ext_modules=[ext]
)