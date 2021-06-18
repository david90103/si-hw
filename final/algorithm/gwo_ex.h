#ifndef GWOEX_H_
#define GWOEX_H_

#include "gwo.h"
#include <algorithm>
#include <random>

class GWOEX : public GWO {
protected:
    int begin_population_size;
    const int MAX_WOLF_NUM = 4;
    const int INIT_WOLF_NUM = 3;
    const double INIT_A = 1.0;
    const int MIN_POPULATION_SIZE = 10;
    const double F_MEAN = 0.5;
    const double F_STD = 0.3;
    const double C_STD = 0.05;
    const double CROSSOVER_STD = 0.1;           // Standard deviation for the DE crossover rate
    const double A_STD = 0.1;                   // Standard deviation for the a parameter
    vector<int> wolf_num_list;                  // The wolf_num used for each solution
    vector<int> prev_wolf_num_list;             // The wolf_num used for each solution in the last iteration
    vector<double> fitness_list;
    vector<double> prev_fitness_list;           // Keep a list of previous iteration's fitness list
    vector<double> top_wolf_score;
    vector<vector<double>> top_wolf_position;
    double crossover_rate_mean;
    double crossover_rate;                      // Crossover rate of DE transition
    double c;                                   // The C weight factor to control transition tendency
    double c_mean;
    default_random_engine generator;
    void update_c();
    void update_position();
    void update_de_crossover_rate();
    inline void update_a(int iter, int max_iter);
    double normal_distribute_f();
    vector<double> transition_de(vector<double> solution);
    vector<double> transition_gwo(vector<double> solution, int i);
    void reduce_population(int iter, int max_iter);
    void update_wolf_num_list();

public:
    GWOEX(Function *evaluate_function,
       unsigned int randseed, 
       int dimension, 
       int population_size, 
       char const *seedfile);
    vector<double> run(int iterations, int max_evaluation);
};

#endif // GWOEX_H_