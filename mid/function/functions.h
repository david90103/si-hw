#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#define _USE_MATH_DEFINES

#include <vector>
#include <cmath>
#include <cassert>
#include <iostream>
#include <exception>
using namespace std;

class Function {
protected:
    int dimension;
    virtual double _evaluate(vector<double> inputs);
public:
    Function() {}
    Function(int dimension);
    void setDimension(int dim);
    double evaluate(vector<double> inputs);
};

class Ackley : public Function {
protected:
    double _evaluate(vector<double> inputs) override;
public:
    Ackley(int dimension) : Function(dimension) {}
};

class Rastrigin : public Function {
protected:
    double _evaluate(vector<double> inputs) override;
public:
    Rastrigin(int dimension) : Function(dimension) {}
};

class Sphere : public Function {
protected:
    double _evaluate(vector<double> inputs) override;
public:
    Sphere(int dimension) : Function(dimension) {}
};

class Rosenbrock : public Function {
protected:
    double _evaluate(vector<double> inputs) override;
public:
    Rosenbrock(int dimension) : Function(dimension) {}
};

class Michalewicz : public Function {
protected:
    double _evaluate(vector<double> inputs) override;
public:
    Michalewicz(int dimension) : Function(dimension) {}
};

#endif // FUNCTIONS_H_