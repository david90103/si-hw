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
public:
    string name = "Function";
    Function() { cout << "func ctor" << endl;}
    Function(int dimension);
    void setDimension(int dim);
    double evaluate(vector<double> inputs);
    virtual double _evaluate(vector<double> inputs);
};

class Ackley : public Function {
protected:
public:
    string name = "ackley";
    Ackley(int dimension) : Function(dimension) { cout << "ackley ctor" << endl;}
    double _evaluate(vector<double> inputs) override;
};

class Rastrigin : public Function {
protected:
    double _evaluate(vector<double> inputs);
public:
    Rastrigin(int dimension) : Function(dimension) {}
};

class Sphere : public Function {
protected:
    double _evaluate(vector<double> inputs);
public:
    Sphere(int dimension) : Function(dimension) {}
};

class Rosenbrock : public Function {
protected:
    double _evaluate(vector<double> inputs);
public:
    Rosenbrock(int dimension) : Function(dimension) {}
};

class Michalewicz : public Function {
protected:
    double _evaluate(vector<double> inputs);
public:
    Michalewicz(int dimension) : Function(dimension) {}
};

#endif // FUNCTIONS_H_