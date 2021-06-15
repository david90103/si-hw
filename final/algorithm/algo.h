#ifndef ALGO_H_
#define ALGO_H_

#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cfloat>
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
#include "../function/functions.h"
using namespace std;

class Algorithm {
protected:
    double bestScore;
    int dimension;
    const double INTERVAL_RANGE = 30;
    Function *evaluate_function;
    vector<vector<double>> population;
    vector<double> objective_values;
    vector<double> global_best;
    vector<double> result;

public:
    Algorithm() {}
    double evaluate(vector<double> inputs);
    double get_best_score();
    virtual vector<double> run(int iterations) = 0;
};

#endif // ALGO_H_