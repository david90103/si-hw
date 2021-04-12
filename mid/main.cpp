#include <cstdio>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include "function/functions.h"
#include "algorithm/de.h"
#include "algorithm/pso.h"
#include "algorithm/gwo.h"
using namespace std;

bool exist(const std::string& name) {
    if (FILE *file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    }
    return false;
}

Function* get_function(char* func, int dimension) {
    if (strcmp(func, "ackley") == 0)
        return new Ackley(dimension);
    if (strcmp(func, "rastrigin") == 0)
        return new Rastrigin(dimension);
    if (strcmp(func, "sphere") == 0)
        return new Sphere(dimension);
    if (strcmp(func, "rosenbrock") == 0)
        return new Rosenbrock(dimension);
    if (strcmp(func, "michalewicz") == 0)
        return new Michalewicz(dimension);
    
    throw "Function not found.";
}

int main(int argc, char *argv[]) {
    FILE *fp;
    int file_index = 0;
    string filename;
    vector<vector<double>> results;
    vector<double> avg;

    srand(time(NULL));

    string algorithm = "";
    Function *function;
    int runs = 30;
    int bits = 100;
    int iterations = 100;
    int dimension = 2;
    string seedfile = "";

    // PSO parameters
    int population_size = 10;
    double w = 1.0;
    double c1 = 1.0;
    double c2= 1.0;

    double crossover_rate = 1.0;
    double f = 1.0;

    /**
     * Parameters:
     * pso [function] [dimension] [runs] [iterations] [seedfile] [population size] [w] [c1] [c2]
     * de  [function] [dimension] [runs] [iterations] [seedfile] [population size] [crossover rate] [f]
     * gwo [function] [dimension] [runs] [iterations] [seedfile] [population size]
     * 
     */
    algorithm = argv[1];
    function = get_function(argv[2], atoi(argv[3]));
    dimension = atoi(argv[3]);
    runs = atoi(argv[4]);
    iterations = atoi(argv[5]);
    seedfile = argv[6];

    if (strcmp(algorithm.c_str(), "pso") == 0) {
        population_size = atoi(argv[7]);
        w = atof(argv[8]);
        c1 = atof(argv[9]);
        c2 = atof(argv[10]);
        for (int run = 0; run < runs; run++) {
            PSO pso(function, rand(), dimension, population_size, w, c1, c2, seedfile.c_str());
            results.push_back(pso.run(iterations));
            cout << "RUN " << run + 1 << " Done." << endl;
        }
    }

    if (strcmp(algorithm.c_str(), "de") == 0) {
        population_size = atoi(argv[7]);
        crossover_rate = atof(argv[8]);
        f = atof(argv[9]);
        for (int run = 0; run < runs; run++) {
            DE de(function, rand(), dimension, population_size, crossover_rate, f, seedfile.c_str());
            results.push_back(de.run(iterations));
            cout << "RUN " << run + 1 << " Done." << endl;
        }
    }

    if (strcmp(algorithm.c_str(), "gwo") == 0) {
        population_size = atoi(argv[7]);
        for (int run = 0; run < runs; run++) {
            GWO gwo(function, rand(), dimension, population_size, seedfile.c_str());
            results.push_back(gwo.run(iterations));
            cout << "RUN " << run + 1 << " Done." << endl;
        }
    }

    // Process results
    for (int i = 0; i < results.size(); i++) {
        for (int j = 0; j < results[i].size(); j++) {
            if (avg.size() < j + 1) {
                avg.push_back(0);
            }
            avg[j] += results[i][j];
        }
    }
    for (int i = 0; i < avg.size(); i++) {
        avg[i] /= results.size();
    }

    // Output to file
    do {
        file_index++;
        filename = "output_" + algorithm + "_" + to_string(file_index) + ".txt";
    } while (exist(filename));
    fp = fopen(filename.c_str(), "w+");
    for (int i = 0; i < avg.size(); i++) {
        fprintf(fp, "%d %.20e\n", i + 1, avg[i]);
    }
    fclose(fp);

    return 0;
}