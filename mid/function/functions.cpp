#include "functions.h"


Function::Function(int dimension) {
    this->dimension = dimension;
}

double Function::evaluate(vector<double> inputs) {
    assert(dimension == inputs.size());
    return _evaluate(inputs);
}

double Function::_evaluate(vector<double> inputs) {
    throw logic_error("Implementation of evaluate function is not defined.");
}

double Ackley::_evaluate(vector<double> inputs) {
    double sum1 = 0, sum2 = 0, exp1, exp2;

    for (int i = 0; i < dimension; i++) {
        sum1 += inputs[i] * inputs[i];
        sum2 += cos(2 * M_PI * inputs[i]);
    }

    exp1 = exp((-0.2) * sqrt(sum1 / dimension));
    exp2 = exp(sum2 / dimension);

    // Add 20 before exp2 to get accurate 0
    return -20 * exp1 + 20 - exp2 + exp(1);
}

double Rastrigin::_evaluate(vector<double> inputs) {
    double sum = 0;
    for (int i = 0; i < dimension; i++)
        sum += pow(inputs[i], 2) - 10 * cos(2 * M_PI * inputs[i]);

    return 10 * dimension + sum;
}

double Sphere::_evaluate(vector<double> inputs) {
    double sum = 0;
    for (int i = 0; i < dimension; i++)
        sum += pow(inputs[i], 2);

    return sum;
}

double Rosenbrock::_evaluate(vector<double> inputs) {
    double sum = 0;
    for (int i = 0; i < dimension - 1; i++)
        sum += 100 * pow(inputs[i + 1] - pow(inputs[i], 2), 2) + pow(inputs[i] - 1, 2);

    return sum;
}

double Michalewicz::_evaluate(vector<double> inputs) {
    double sum = 0;
    int m = 10;
    for (int i = 0; i < dimension; i++)
        sum -= sin(inputs[i]) * pow(sin((i + 1) * pow(inputs[i], 2) / M_PI), 2 * m);

    return sum;
}