#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#define _USE_MATH_DEFINES

#include <vector>
#include <cmath>
#include <cfloat>
#include <cassert>
#include <iostream>
#include <exception>
using namespace std;

class Function {
protected:
    int dimension;
    double lower_bound = -DBL_MAX;
    double upper_bound = DBL_MAX;
    double shift_value = 10;
    virtual double _evaluate(vector<double> inputs);
public:
    Function() {}
    Function(int dimension);
    double lbound();
    double ubound();
    double evaluate(vector<double> inputs);
};

class Ackley : public Function {
protected:
    double _evaluate(vector<double> inputs) override;
public:
    Ackley(int dimension) : Function(dimension) { lower_bound = -40; upper_bound = 40; shift_value = 1; }
};

class Rastrigin : public Function {
protected:
    double _evaluate(vector<double> inputs) override;
public:
    Rastrigin(int dimension) : Function(dimension) { lower_bound = -5.12; upper_bound = 5.12; shift_value = 0.5; }
};

class Sphere : public Function {
protected:
    double _evaluate(vector<double> inputs) override;
public:
    Sphere(int dimension) : Function(dimension) { lower_bound = -5.12; upper_bound = 5.12; shift_value = 0.5; }
};

class Rosenbrock : public Function {
protected:
    double _evaluate(vector<double> inputs) override;
public:
    Rosenbrock(int dimension) : Function(dimension) { lower_bound = -2.048; upper_bound = 2.048; shift_value = 0.05; }
};

class Michalewicz : public Function {
protected:
    double _evaluate(vector<double> inputs) override;
public:
    Michalewicz(int dimension) : Function(dimension) { lower_bound = 0; upper_bound = M_PI; shift_value = M_PI / 10; }
};

#endif // FUNCTIONS_H_