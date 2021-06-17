#ifndef GWOEX_H_
#define GWOEX_H_

#include "gwo.h"
#include <algorithm>

class GWOEX : public GWO {
protected:
    int begin_population_size;
    const int MAX_WOLF_NUM = 4;
    const int INIT_WOLF_NUM = 3;
    const double INIT_A_VALUE = 1.0;
    const int MIN_POPULATION_SIZE = 10;
    vector<double> a_list;                      // List of self adaptive parameter a
    vector<int> wolf_num_list;                  // The wolf_num used for each solution
    vector<int> prev_wolf_num_list;             // The wolf_num used for each solution in the last iteration
    vector<double> fitness_list;
    vector<double> prev_fitness_list;           // Keep a list of previous iteration's fitness list
    vector<double> top_wolf_score;
    vector<vector<double>> top_wolf_position;
    void update_a(int iter, int max_iter);
    void update_position();
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