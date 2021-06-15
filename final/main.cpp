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
#include "algorithm/gwo_ex.h"
using namespace std;

bool exist(const std::string& name) {
    if (FILE *file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    }
    return false;
}

Function* get_function(char* func, int dimension) {
    if (strcmp(func, "Ackley") == 0)
        return new Ackley(dimension);
    if (strcmp(func, "Rastrigin") == 0)
        return new Rastrigin(dimension);
    if (strcmp(func, "Sphere") == 0)
        return new Sphere(dimension);
    if (strcmp(func, "Rosenbrock") == 0)
        return new Rosenbrock(dimension);
    if (strcmp(func, "Michalewicz") == 0)
        return new Michalewicz(dimension);
    if (strcmp(func, "Griewank") == 0)
        return new Griewank(dimension);
    if (strcmp(func, "Schaffer") == 0)
        return new Schaffer(dimension);
    if (strcmp(func, "Schwefel") == 0)
        return new Schwefel(dimension);
    if (strcmp(func, "Bohachevsky_1") == 0)
        return new Bohachevsky_1(dimension);
    if (strcmp(func, "Bohachevsky_2") == 0)
        return new Bohachevsky_2(dimension);
    if (strcmp(func, "Bohachevsky_3") == 0)
        return new Bohachevsky_3(dimension);
    if (strcmp(func, "SumSquares") == 0)
        return new SumSquares(dimension);
    if (strcmp(func, "Booth") == 0)
        return new Booth(dimension);
    if (strcmp(func, "Zakharov") == 0)
        return new Zakharov(dimension);
    if (strcmp(func, "ThreeHump") == 0)
        return new ThreeHump(dimension);
    if (strcmp(func, "DeJong") == 0)
        return new DeJong(dimension);
    if (strcmp(func, "Beale") == 0)
        return new Beale(dimension);
    if (strcmp(func, "Powell") == 0)
        return new Powell(dimension);
    
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

    if (strcmp(algorithm.c_str(), "gwoex") == 0) {
        population_size = atoi(argv[7]);
        for (int run = 0; run < runs; run++) {
            GWOEX gwoex(function, rand(), dimension, population_size, seedfile.c_str());
            results.push_back(gwoex.run(iterations));
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