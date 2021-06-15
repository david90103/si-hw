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
    double shift_value = 0;
    virtual double _evaluate(vector<double> x);
public:
    Function() {}
    Function(int dimension);
    double lbound();
    double ubound();
    double evaluate(vector<double> x);
};

class Ackley : public Function {
protected:
    double _evaluate(vector<double> x) override;
public:
    Ackley(int dimension) : Function(dimension) { lower_bound = -40; upper_bound = 40; shift_value = 1; }
};

class Rastrigin : public Function {
protected:
    double _evaluate(vector<double> x) override;
public:
    Rastrigin(int dimension) : Function(dimension) { lower_bound = -5.12; upper_bound = 5.12; shift_value = 0.5; }
};

class Sphere : public Function {
protected:
    double _evaluate(vector<double> x) override;
public:
    Sphere(int dimension) : Function(dimension) { lower_bound = -5.12; upper_bound = 5.12; shift_value = 0.5; }
};

class Rosenbrock : public Function {
protected:
    double _evaluate(vector<double> x) override;
public:
    Rosenbrock(int dimension) : Function(dimension) { lower_bound = -2.048; upper_bound = 2.048; shift_value = 0.05; }
};

class Michalewicz : public Function {
protected:
    double _evaluate(vector<double> x) override;
public:
    Michalewicz(int dimension) : Function(dimension) { lower_bound = 0; upper_bound = M_PI; shift_value = M_PI / 10; }
};

class Griewank : public Function {
protected:
    double _evaluate(vector<double> x) override;
public:
    Griewank(int dimension) : Function(dimension) { lower_bound = -600; upper_bound = 600; shift_value = 30; }
};

class Schaffer : public Function {
protected:
    double _evaluate(vector<double> x) override;
public:
    Schaffer(int dimension) : Function(dimension) { lower_bound = -100; upper_bound = 100; shift_value = 5; }
};

class Schwefel : public Function {
protected:
    double _evaluate(vector<double> x) override;
public:
    Schwefel(int dimension) : Function(dimension) { lower_bound = -500; upper_bound = 500; shift_value = 25; }
};

class Bohachevsky_1 : public Function {
protected:
    double _evaluate(vector<double> x) override;
public:
    Bohachevsky_1(int dimension) : Function(dimension) { lower_bound = -100; upper_bound = 100; shift_value = 5; }
};

class Bohachevsky_2 : public Function {
protected:
    double _evaluate(vector<double> x) override;
public:
    Bohachevsky_2(int dimension) : Function(dimension) { lower_bound = -100; upper_bound = 100; shift_value = 5; }
};

class Bohachevsky_3 : public Function {
protected:
    double _evaluate(vector<double> x) override;
public:
    Bohachevsky_3(int dimension) : Function(dimension) { lower_bound = -100; upper_bound = 100; shift_value = 5; }
};

class SumSquares : public Function {
protected:
    double _evaluate(vector<double> x) override;
public:
    SumSquares(int dimension) : Function(dimension) { lower_bound = -10; upper_bound = 10; shift_value = 0.5; }
};

class Booth : public Function {
protected:
    double _evaluate(vector<double> x) override;
public:
    Booth(int dimension) : Function(dimension) { lower_bound = -10; upper_bound = 10; shift_value = 0.5; }
};

class Zakharov : public Function {
protected:
    double _evaluate(vector<double> x) override;
public:
    Zakharov(int dimension) : Function(dimension) { lower_bound = -5; upper_bound = 10; shift_value = 0.5; }
};

class ThreeHump : public Function {
protected:
    double _evaluate(vector<double> x) override;
public:
     ThreeHump(int dimension) : Function(dimension) { lower_bound = -5; upper_bound = 5; shift_value = 0.25; }
};

class DeJong : public Function {
protected:
    double _evaluate(vector<double> x) override;
public:
    DeJong(int dimension) : Function(dimension) { lower_bound = -65.536; upper_bound = 65.536; shift_value = 3; }
};

class Beale : public Function {
protected:
    double _evaluate(vector<double> x) override;
public:
    Beale(int dimension) : Function(dimension) { lower_bound = -4.5; upper_bound = 4.5; shift_value = 0.2; }
};

class Powell : public Function {
protected:
    double _evaluate(vector<double> x) override;
public:
    Powell(int dimension) : Function(dimension) { lower_bound = -4; upper_bound = 5; shift_value = 0.25; }
};

#endif // FUNCTIONS_H_
