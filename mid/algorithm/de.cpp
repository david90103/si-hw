#include "de.h"


DE::DE(Function *evaluate_function, 
       unsigned int randseed, 
       int dimension, 
       int population_size, 
       double crossover_rate, 
       double f, 
       char const *seedfile) {
    srand(randseed);
    this->bestScore = DBL_MAX;
    this->population_size = population_size;
    this->dimension = dimension;
    this->crossover_rate = crossover_rate;
    this->f = f;
    this->evaluate_function = evaluate_function;
    // TODO: Seedfile
    // Initialize population
    vector<double> t;
    for (int i = 0; i < population_size; i++) {
        t.clear();
        for (int j = 0; j < dimension; j++)
            t.push_back(evaluate_function->lbound() + (double) rand() / RAND_MAX * (2 * evaluate_function->ubound()));
        population.push_back(t);
        objective_values.push_back(evaluate(t));
    }
}

vector<vector<double>> DE::mutation(vector<vector<double>> population) {
    vector<vector<double>> v_arr;
    for (int i = 0; i < population.size(); i++) {
        vector<double> temp;
        int r1 = rand() % population_size;
        int r2 = rand() % population_size;
        int r3 = rand() % population_size;
        for (int j = 0; j < dimension; j++)
            temp.push_back(population[r1][j] + f * (population[r2][j] - population[r3][j]));
        v_arr.push_back(temp);
    }
    return v_arr;
}

vector<vector<double>> DE::crossover(vector<vector<double>> population, vector<vector<double>> v_arr) {
    vector<vector<double>> u_arr;
    for (int i = 0; i < population.size(); i++) {
        vector<double> temp;
        for (int j = 0; j < dimension; j++) {
            if (i == j || (double) rand() / RAND_MAX <= crossover_rate) {
                temp.push_back(v_arr[i][j]);
            } else {
                temp.push_back(population[i][j]);
            }
        }
        u_arr.push_back(temp);
    }
    return u_arr;
}

vector<double> DE::run(int iterations) {
    for (int iter = 1; iter <= iterations; iter++) {
        vector<vector<double>> v_arr = mutation(population);
        vector<vector<double>> u_arr = crossover(population, v_arr);
        // Selection
        for (int i = 0; i < population_size; i++) {
            double eval = evaluate(u_arr[i]);
            if (eval <= objective_values[i]) {
                objective_values[i] = eval;
                population[i] = u_arr[i];
            }
            if (eval < bestScore) {
                bestScore = eval;
                global_best = u_arr[i];
            }
        }
        // Record and log
        result.push_back(bestScore);
    }

    cout << "Score: " << bestScore << endl;
    return result;
}
