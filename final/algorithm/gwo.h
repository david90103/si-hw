#ifndef GWO_H_
#define GWO_H_

#include "algo.h"

class GWO : public Algorithm {
protected:
    int population_size;
    double alpha_score;
    double beta_score;
    double delta_score;
    double gamma_score;
    vector<double> alpha_position;
    vector<double> beta_position;
    vector<double> delta_position;
    vector<double> gamma_position;
    double a;
    inline void update_a(int iter, int max_iter);
    void update_position();

public:
    GWO(Function *evaluate_function,
       unsigned int randseed, 
       int dimension, 
       int population_size, 
       char const *seedfile);
    vector<double> run(int iterations, int max_evaluation);
};

#endif // GWO_H_