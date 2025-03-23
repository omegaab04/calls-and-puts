#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <Python.h>

// Define PI if not already defined
#ifndef PI
#define PI 3.141592653589793238462643
#endif

// Normal distribution function
double n(double z) {
    return (1.0 / sqrt(2.0 * PI)) * exp(-0.5 * z * z);
}

// Cumulative normal distribution function
double N(double z) {
    if (z > 6.0) return 1.0;
    if (z < -6.0) return 0.0;

    double b1 =  0.31938153;
    double b2 = -0.356563782;
    double b3 =  1.781477937;
    double b4 = -1.821255978;
    double b5 =  1.330274429;
    double p  =  0.2316419;
    double c2 =  0.3989423;

    double a = fabs(z);
    double t = 1.0 / (1.0 + a * p);
    double b = c2 * exp(-z * z / 2.0);
    double n = ((((b5 * t + b4) * t + b3) * t + b2) * t + b1) * t;
    n = 1.0 - b * n;
    if (z < 0.0) n = 1.0 - n;

    return n;
}

// Black-Scholes Call Option Price
double _bs_call(double S, double K, double r, double t, double sigma) {
    double time_sqrt = sqrt(t);
    double d1 = (log(S / K) + r * t) / (sigma * time_sqrt) + 0.5 * sigma * time_sqrt;
    double d2 = d1 - (sigma * time_sqrt);
    return S * N(d1) - K * exp(-r * t) * N(d2);
}

// Black-Scholes Put Option Price
double _bs_put(double S, double K, double r, double t, double sigma) {
    double time_sqrt = sqrt(t);
    double d1 = (log(S / K) + r * t) / (sigma * time_sqrt) + 0.5 * sigma * time_sqrt;
    double d2 = d1 - (sigma * time_sqrt);
    return K * exp(-r * t) * N(-d2) - S * N(-d1);
}

// Python Wrapper Function for Call Option
static PyObject *bs_call(PyObject *self, PyObject *args) {
    double S, K, r, t, sigma;
    if (!PyArg_ParseTuple(args, "ddddd", &S, &K, &r, &t, &sigma))
        return NULL;
    return Py_BuildValue("d", _bs_call(S, K, r, t, sigma));
}

// Python Wrapper Function for Put Option
static PyObject *bs_put(PyObject *self, PyObject *args) {
    double S, K, r, t, sigma;
    if (!PyArg_ParseTuple(args, "ddddd", &S, &K, &r, &t, &sigma))
        return NULL;
    return Py_BuildValue("d", _bs_put(S, K, r, t, sigma));
}

// Module definition
static PyMethodDef methods[] = {
    {"bs_call", bs_call, METH_VARARGS, "Calculate Black-Scholes call option price"},
    {"bs_put", bs_put, METH_VARARGS, "Calculate Black-Scholes put option price"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef bsmodule = {
    PyModuleDef_HEAD_INIT,
    "bs",
    "bs_doc",
    -1,
    methods
};

// Module initialization function
PyMODINIT_FUNC PyInit_bs(void) {
    return PyModule_Create(&bsmodule);
}