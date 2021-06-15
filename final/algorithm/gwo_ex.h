#ifndef GWOEX_H_
#define GWOEX_H_

#include "gwo.h"

class GWOEX : public GWO {
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
    GWOEX(Function *evaluate_function,
       unsigned int randseed, 
       int dimension, 
       int population_size, 
       char const *seedfile) : GWO(evaluate_function, randseed, dimension, population_size, seedfile) {};
    vector<double> run(int iterations);
};

#endif // GWOEX_H_