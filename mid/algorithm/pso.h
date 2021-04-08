#ifndef PSO_H_
#define PSO_H_

#include "algo.h"

class PSO : Algorithm {
private:
    int population_size;
    double w;
    double c1;
    double c2;
    vector<double> objective_values;
    vector<double> individual_bests;
    vector<vector<double>> velocities;
    vector<vector<double>> individual_bests_pos;
    void evaluatePopulation();
    void updateVelocity();
    void updatePosition();
public:
    PSO(Function *evaluate_function,
        unsigned int randseed, 
        int dimension, 
        int population_size, 
        double w, 
        double c1, 
        double c2, 
        char const *seedfile);
    vector<double> run(int iterations);
};

#endif // PSO_H_
