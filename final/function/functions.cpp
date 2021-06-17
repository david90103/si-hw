#include "functions.h"


Function::Function(int dimension) {
    this->dimension = dimension;
}

double Function::evaluate(vector<double> x) {
    assert(dimension == x.size());
    // Shift every dimension
    // if (abs(shift_value) > 0.0000001)
    //     for (int i = 0; i < x.size(); i++)
    //         x[i] -= shift_value;
    return _evaluate(x);
}

double Function::_evaluate(vector<double> x) {
    throw logic_error("Implementation of evaluate function is not defined.");
}

double Function::lbound() {
    return lower_bound;
}

double Function::ubound() {
    return upper_bound;
}

double Ackley::_evaluate(vector<double> x) {
    double sum1 = 0, sum2 = 0, exp1, exp2;

    for (int i = 0; i < dimension; i++) {
        sum1 += x[i] * x[i];
        sum2 += cos(2 * M_PI * x[i]);
    }

    exp1 = exp((-0.2) * sqrt(sum1 / dimension));
    exp2 = exp(sum2 / dimension);

    // Add 20 before exp2 to get accurate 0
    return -20 * exp1 + 20 - exp2 + exp(1);
}

double Rastrigin::_evaluate(vector<double> x) {
    double sum = 0;
    for (int i = 0; i < dimension; i++)
        sum += pow(x[i], 2) - 10 * cos(2 * M_PI * x[i]);

    return 10 * dimension + sum;
}

double Sphere::_evaluate(vector<double> x) {
    double sum = 0;
    for (int i = 0; i < dimension; i++)
        sum += pow(x[i], 2);

    return sum;
}

double Rosenbrock::_evaluate(vector<double> x) {
    double sum = 0;
    for (int i = 0; i < dimension - 1; i++)
        sum += 100 * pow(x[i + 1] - pow(x[i], 2), 2) + pow(x[i] - 1, 2);

    return sum;
}

double Michalewicz::_evaluate(vector<double> x) {
    double sum = 0;
    int m = 10;
    for (int i = 0; i < dimension; i++)
        sum -= sin(x[i]) * pow(sin((i + 1) * pow(x[i], 2) / M_PI), 2 * m);

    return sum;
}

double Griewank::_evaluate(vector<double> x) {
    double sum = 0;
    double pruduct = 0;
    for (int i = 0; i < dimension; i++) {
        sum += pow(x[i], 2) / 4000;
        pruduct *= cos(x[i] / sqrt(i + 1));
    }
    return sum - pruduct + 1;
}

double Schaffer::_evaluate(vector<double> x) {
    assert(dimension == 2);
    double a, b;
    a = pow(sin(pow(x[0], 2) - pow(x[1], 2)), 2) - 0.5;
    b = pow(1 + 0.001 * (pow(x[0], 2) + pow(x[1], 2)), 2);

    return 0.5 + a / b;
}

double Schwefel::_evaluate(vector<double> x) {
    double sum = 0;
    for (int i = 0; i < dimension; i++)
        sum += x[i] * sin(sqrt(abs(x[i])));

    return 418.9829 * dimension - sum;
}

double Bohachevsky_1::_evaluate(vector<double> x) {
    assert(dimension == 2);
    return pow(x[0], 2) + 2 * pow(x[1], 2) - 0.3 * cos(3 * M_PI * x[0]) - 0.4 * cos(4 * M_PI * x[1]) + 0.7;
}

double Bohachevsky_2::_evaluate(vector<double> x) {
    assert(dimension == 2);
    return pow(x[0], 2) + 2 * pow(x[1], 2) - 0.3 * cos(3 * M_PI * x[0]) * cos(4 * M_PI * x[1]) + 0.3;
}

double Bohachevsky_3::_evaluate(vector<double> x) {
    assert(dimension == 2);
    return pow(x[0], 2) + 2 * pow(x[1], 2) - 0.3 * cos(3 * M_PI * x[0] + 4 * M_PI * x[1]) + 0.7;
}

double SumSquares::_evaluate(vector<double> x) {
    double sum = 0;
    for (int i = 0; i < dimension; i++)
        sum += i * pow(x[i], 2);

    return sum;
}

double Booth::_evaluate(vector<double> x) {
    assert(dimension == 2);
    return pow(x[0] + 2 * x[1] - 7, 2) + pow(2 * x[0] + x[1] - 5, 2);
}

double Zakharov::_evaluate(vector<double> x) {
    double sum_1 = 0;
    double sum_2 = 0;
    for (int i = 0; i < dimension; i++) {
        sum_1 += pow(x[i], 2);
        sum_2 += 0.5 * i * x[i];
    }
    return sum_1 + pow(sum_2, 2) + pow(sum_2, 4);
}

double ThreeHump::_evaluate(vector<double> x) {
    assert(dimension == 2);
    return 2 * pow(x[0], 2) - 1.05 * pow(x[0], 4) + pow(x[0], 6) / 6 + x[0] * x[1] + pow(x[1], 2);
}

double DeJong::_evaluate(vector<double> x) {
    assert(dimension == 2);
    int a1[25] = {-32, -16, 0, 16, 32, -32, -16, 0, 16, 32, -32, -16, 0, 16, 32, -32, -16, 0, 16, 32, -32, -16, 0, 16, 32};
    int a2[25] = {-32, -32, -32, -32, -32, -16, -16, -16, -16, -16, 0, 0, 0, 0, 0, 16, 16, 16, 16, 16, 32, 32, 32, 32, 32};
    double sum = 0;
    for (int i = 0; i < 25; i++)
        sum += 1 / (i + pow(x[0] - a1[i], 6) + pow(x[1] - a2[2 * i], 6));

    return 1 / (0.002 + sum);
}

double Beale::_evaluate(vector<double> x) {
    assert(dimension == 2);
    double p1 = 1.5 - x[0] + x[0] * x[1];
    double p2 = 2.25 - x[0] + x[0] * pow(x[1], 2);
    double p3 = 2.65 - x[0] + x[0] * pow(x[1], 3);

    return pow(p1, 2) + pow(p2, 2) + pow(p3, 2);
}

double Powell::_evaluate(vector<double> x) {
    assert(dimension % 4 == 0);
    double sum = 0;
    double p1, p2, p3, p4;
    for (int i = 0; i < dimension / 4; i++) {
        p1 = x[4 * i - 3] + 10 * x[4 * i - 2];
        p2 = x[4 * i - 1] - x[4 * i];
        p3 = x[4 * i - 2] - 2 * x[4 * i - 1];
        p4 = x[4 * i - 3] - x[4 * i];
        sum += pow(p1, 2) + 5 * pow(p2, 2) + pow(p3, 4) + 10 * pow(p4, 4);
    }
    return sum;
}
