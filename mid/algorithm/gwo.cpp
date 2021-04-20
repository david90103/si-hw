#include "gwo.h"


GWO::GWO(Function *evaluate_function, 
       unsigned int randseed, 
       int dimension, 
       int population_size, 
       char const *seedfile) {
    srand(randseed);
    this->bestScore = DBL_MAX;
    this->population_size = population_size;
    this->dimension = dimension;
    this->evaluate_function = evaluate_function;
    this->alpha_score = DBL_MAX;
    this->beta_score = DBL_MAX;
    this->delta_score = DBL_MAX;
    this->gamma_score = DBL_MAX;
    this->alpha_position = vector<double>(dimension, 0);
    this->beta_position = vector<double>(dimension, 0);
    this->delta_position = vector<double>(dimension, 0);
    this->gamma_position = vector<double>(dimension, 0);
    this->a = 2;
    // TODO: Seedfile
    // Initialize population
    vector<double> t;
    for (int i = 0; i < population_size; i++) {
        t.clear();
        for (int j = 0; j < dimension; j++)
            t.push_back(evaluate_function->lbound() + (double) rand() / RAND_MAX * (2 * evaluate_function->ubound()));
        population.push_back(t);
    }
}

inline void GWO::update_a(int iter, int max_iter) {
    a = 2 - iter * (2 / static_cast<double>(max_iter));
}

void GWO::update_position() {
    for (int i = 0; i < population_size; i++) {
        for (int j = 0; j < dimension; j++) {
            // alpha
            double r1 = static_cast<double>(rand()) / RAND_MAX;
            double r2 = static_cast<double>(rand()) / RAND_MAX;
            double A1 = 2 * a * r1 - a;
            double C1 = 2 * r2;
            double D_alpha = abs(C1 * alpha_position[j] - population[i][j]);
            double X1 = alpha_position[j] - A1 * D_alpha;

            // beta
            r1 = static_cast<double>(rand()) / RAND_MAX;
            r2 = static_cast<double>(rand()) / RAND_MAX;
            double A2 = 2. * a * r1 - a;
            double C2 = 2 * r2;
            double D_beta = abs(C2 * beta_position[j] - population[i][j]);
            double X2 = beta_position[j] - A2 * D_beta;

            // delta
            r1 = static_cast<double>(rand()) / RAND_MAX;
            r2 = static_cast<double>(rand()) / RAND_MAX;
            double A3 = 2. * a * r1 - a;
            double C3 = 2 * r2;
            double D_delta = abs(C3 * delta_position[j] - population[i][j]);
            double X3 = delta_position[j] - A3 * D_delta;

            // gamma
            // r1 = static_cast<double>(rand()) / RAND_MAX;
            // r2 = static_cast<double>(rand()) / RAND_MAX;
            // double A4 = 2. * a * r1 - a;
            // double C4 = 2 * r2;
            // double D_gamma = abs(C4 * gamma_position[j] - population[i][j]);
            // double X4 = gamma_position[j] - A4 * D_gamma;

            population[i][j] = (X1 + X2 + X3) / 3;
        }
    }
}

vector<double> GWO::run(int iterations) {
    for (int iter = 1; iter <= iterations; iter++) {
        for (int i = 0; i < population_size; i++) {
            double fitness = evaluate(population[i]);

            if (fitness < bestScore) {
                bestScore = fitness;
                global_best = population[i];
            }

            if (fitness < alpha_score) {
                alpha_score = fitness;
                alpha_position = population[i];
            }

            if (fitness > alpha_score && fitness < beta_score) {
                beta_score = fitness;
                beta_position = population[i];
            }

            if (fitness > alpha_score && fitness > beta_score && fitness < delta_score) {
                delta_score = fitness;
                delta_position = population[i];
            }

            // if (fitness > alpha_score && fitness > beta_score && fitness > delta_score && fitness < gamma_score) {
            //     gamma_score = fitness;
            //     gamma_position = population[i];
            // }
        }
        update_a(iter, iterations);
        update_position();
        
        // Record and log
        result.push_back(bestScore);
    }

    // for (int i = 0 ; i < dimension; i++) 
    //     cout << global_best[i] << " ";
    // cout << endl;
    cout << "Score: " << bestScore << endl;
    return result;
}
