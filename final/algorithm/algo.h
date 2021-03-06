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
    int randseed;
    double bestScore;
    int dimension;
    int evaluations;
    const double INTERVAL_RANGE = 30;
    Function *evaluate_function;
    vector<vector<double>> population;
    vector<double> objective_values;
    vector<double> global_best;
    vector<double> result;

public:
    Algorithm() { evaluations = 0; }
    double evaluate(vector<double> inputs);
    double get_best_score();
    virtual vector<double> run(int iterations, int max_evaluation) = 0;
};

#endif // ALGO_H_