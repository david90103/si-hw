#ifndef DE_H_
#define DE_H_

#include "algo.h"

class DE : Algorithm {
private:
    int population_size;
    double crossover_rate;
    double f;
    vector<vector<double>> mutation(vector<vector<double>> population);
    vector<vector<double>> crossover(vector<vector<double>> population, vector<vector<double>> arr);

public:
    DE(Function *evaluate_function,
       unsigned int randseed, 
       int dimension, 
       int population_size, 
       double crossover_rate, 
       double f, 
       char const *seedfile);
    vector<double> run(int iterations);
};

#endif // DE_H_