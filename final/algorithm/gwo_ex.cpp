#include "gwo_ex.h"


GWOEX::GWOEX(Function *evaluate_function, 
        unsigned int randseed, 
        int dimension, 
        int population_size, 
        char const *seedfile) : GWO(evaluate_function, randseed, dimension, population_size, seedfile) {

    begin_population_size = population_size;
    c_mean = 0.5;
    crossover_rate_mean = 0.5;
    wolf_num_list = vector<int>(population_size, INIT_WOLF_NUM);
    prev_wolf_num_list = vector<int>(population_size, INIT_WOLF_NUM);
    fitness_list = vector<double>(population_size, DBL_MAX);
    prev_fitness_list = vector<double>(population_size, DBL_MAX);
    top_wolf_score = vector<double>(MAX_WOLF_NUM, DBL_MAX);
    top_wolf_position = vector<vector<double>>(MAX_WOLF_NUM, vector<double>(dimension, DBL_MAX));
}

inline void GWOEX::update_a(int iter, int max_iter) {
    a = 2 - iter * (2 / static_cast<double>(max_iter));
}

void GWOEX::update_c() {
    double prev_fitness_avg = 0;
    double fitness_avg = 0;
    for (int i = 0; i < fitness_list.size(); i++)
        fitness_avg += fitness_list[i];
    for (int i = 0; i < prev_fitness_list.size(); i++)
        prev_fitness_avg += prev_fitness_list[i];
    fitness_avg /= fitness_list.size();
    prev_fitness_avg /= prev_fitness_list.size();

    // Update mean if the solution is better
    if (fitness_avg < prev_fitness_avg)
        c_mean = c;

    normal_distribution<double> d(c_mean, C_STD);
    c = max(min(d(generator), 1.0), 0.0);
}

void GWOEX::update_de_crossover_rate() {
    double prev_fitness_avg = 0;
    double fitness_avg = 0;
    for (int i = 0; i < fitness_list.size(); i++)
        fitness_avg += fitness_list[i];
    for (int i = 0; i < prev_fitness_list.size(); i++)
        prev_fitness_avg += prev_fitness_list[i];
    fitness_avg /= fitness_list.size();
    prev_fitness_avg /= prev_fitness_list.size();

    // Update mean if the solution is better
    if (fitness_avg < prev_fitness_avg)
        crossover_rate_mean = crossover_rate;

    normal_distribution<double> d(crossover_rate_mean, CROSSOVER_STD);
    crossover_rate = max(min(d(generator), 1.0), 0.0);
}

double GWOEX::normal_distribute_f() {
    normal_distribution<double> d(F_MEAN, F_STD);
    return  max(min(d(generator), 2.0), 0.0);
}

vector<double> GWOEX::transition_de(vector<double> solution) {
    if (static_cast<double>(rand()) / RAND_MAX > crossover_rate)
        return solution;

    vector<double> v_arr;
    double t;
    int r1 = rand() % population_size;
    int r2 = rand() % population_size;
    int r3 = rand() % population_size;
    for (int j = 0; j < dimension; j++) {
        t = population[r1][j] + normal_distribute_f() * (population[r2][j] - population[r3][j]);
        if (t > evaluate_function->ubound())
            t = evaluate_function->ubound();
        if (t < evaluate_function->lbound())
            t = evaluate_function->lbound();
        v_arr.push_back(t);
    }
    return v_arr;
}

vector<double> GWOEX::transition_gwo(vector<double> solution, int i) {
    for (int j = 0; j < dimension; j++) {
        double sum = 0;
        double r1, r2, A, C, D, X;
        for (int w = 0; w < wolf_num_list[i]; w++) {
            r1 = static_cast<double>(rand()) / RAND_MAX;
            r2 = static_cast<double>(rand()) / RAND_MAX;
            A = 2 * a * r1 - a;
            C = 2 * r2;
            D = abs(C * top_wolf_position[w][j] - population[i][j]);
            X = top_wolf_position[w][j] - A * D;
            sum += X;
        }
        // Move the current solution towards the geometric center of the leading wolves
        solution[j] = sum / wolf_num_list[i];
        if (solution[j] > evaluate_function->ubound())
            solution[j] = evaluate_function->ubound();
        if (solution[j] < evaluate_function->lbound())
            solution[j] = evaluate_function->lbound();
    }
    return solution;
}

void GWOEX::update_position() {
    for (int i = 0; i < population_size; i++) {
        if (static_cast<double>(rand()) / RAND_MAX < c)
            population[i] = transition_de(population[i]);
        else
            population[i] = transition_gwo(population[i], i);
    }
}

void GWOEX::reduce_population(int evaluations, int max_evaluation) {
    // When the population size is reduced, 
    // the worst <remove_size> solution will be removed from the population.
    int prev_size = population_size;
    population_size = max(static_cast<int>((1.0 - static_cast<double>(evaluations) / max_evaluation) * begin_population_size), MIN_POPULATION_SIZE);
    int remove_size = prev_size - population_size;
    if (remove_size <= 0)
        return;
    // Create a remove list of worst solutions by running through the whole population
    vector<int> remove_idx_list = vector<int>(remove_size, INT32_MAX);
    vector<double> remove_value_list = vector<double>(remove_size, DBL_MAX);
    for (int i = 0; i < prev_size; i++) {
        for (int j = 0; j < remove_size; j++) {
            if (fitness_list[i] < remove_value_list[j] || isinf(fitness_list[i])) {
                // Move back worse values before insert
                for (int k = remove_size - 1; k > j; k--) {
                    remove_idx_list[k] = remove_idx_list[k - 1];
                    remove_value_list[k] = remove_value_list[k - 1];
                }
                remove_idx_list[j] = i;
                remove_value_list[j] = fitness_list[i];
                break;
            } 
        }
    }
    // Remove the solution from the back
    sort(remove_idx_list.begin(), remove_idx_list.end(), greater<int>());
    for (int i = 0; i < remove_size; i++) {
        population.erase(population.begin() + remove_idx_list[i]);
        fitness_list.erase(fitness_list.begin() + remove_idx_list[i]);
        prev_fitness_list.erase(prev_fitness_list.begin() + remove_idx_list[i]);
        wolf_num_list.erase(wolf_num_list.begin() + remove_idx_list[i]);
        prev_wolf_num_list.erase(prev_wolf_num_list.begin() + remove_idx_list[i]);
    }
}

void GWOEX::update_wolf_num_list() {
    for (int i = 0; i < population_size; i++) {
        // Random choose a wolf num if the new fitness is worse
        if (fitness_list[i] > prev_fitness_list[i] && wolf_num_list[i] == prev_wolf_num_list[i])
            wolf_num_list[i] = 1 + rand() % MAX_WOLF_NUM;
    }
}

vector<double> GWOEX::run(int iterations, int max_evaluation) {
    for (int iter = 1; iter <= iterations; iter++) {
        prev_fitness_list = fitness_list;
        prev_wolf_num_list = wolf_num_list;

        for (int i = 0; i < population_size; i++) {
            double fitness = evaluate(population[i]);
            fitness_list[i] = fitness;
            if (evaluations > max_evaluation)
                goto evaluation_exceeded;

            if (fitness < bestScore) {
                bestScore = fitness;
                global_best = population[i];
            }
            // Update the leading wolves
            for (int j = 0; j < MAX_WOLF_NUM; j++) {
                if (fitness < top_wolf_score[j]) {
                    // Move back worse wolves before insert current wolf
                    for (int k = MAX_WOLF_NUM - 1; k > j; k--) {
                        top_wolf_score[k] = top_wolf_score[k - 1];
                        top_wolf_position[k] = top_wolf_position[k - 1];
                    }
                    top_wolf_score[j] = fitness;
                    top_wolf_position[j] = population[i];
                    break;
                }
            }
        }
        // Linear reduce a
        update_a(evaluations, max_evaluation);
        // Self-adaptive thre
        update_c();
        // Self-adaptive DE crossover rate
        update_de_crossover_rate();
        // Transition
        update_position();
        // Self-adaptive wolf num
        update_wolf_num_list();
        // Linear reduce population
        reduce_population(evaluations, max_evaluation);
    }

    evaluation_exceeded:
    cout << "Score: " << bestScore << endl;
    return result;
}
