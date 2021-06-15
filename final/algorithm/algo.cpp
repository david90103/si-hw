#include "algo.h"

double Algorithm::get_best_score() {
    return bestScore;
}

double Algorithm::evaluate(vector<double> inputs) {
    return evaluate_function->evaluate(inputs);
}