#include <cstdio>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

inline bool exist(const std::string& name) {
    if (FILE *file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    }
    return false;
}

int main(int argc, char *argv[]) {
    FILE *fp;
    int file_index = 0;
    string filename;
    vector<vector<double>> results;
    vector<double> avg;

    string algorithm = "";
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

    // DE parameters
    int population_size_de = 10;
    double crossover_rate = 1.0;
    double f = 1.0;

    /**
     * Parameters:
     * pso [runs] [iterations] [dimension] [seedfile] [population size] [w] [c1] [c2]
     * de  [runs] [iterations] [dimension] [seedfile] [population size] [crossover rate] [f]
     */
    algorithm = argv[1];
    runs = atoi(argv[2]);
    iterations = atoi(argv[3]);
    dimension = atoi(argv[4]);
    seedfile = argv[5];

    if (strcmp(algorithm.c_str(), "pso") == 0) {
        population_size = atoi(argv[6]);
        w = atof(argv[7]);
        c1 = atof(argv[8]);
        c2 = atof(argv[9]);
        for (int run = 0; run < runs; run++) {
            // PSO pso = PSO(time(NULL) + run, dimension, population_size, w, c1, c2, seedfile.c_str());
            // results.push_back(pso.run(iterations));
            // cout << "RUN " << run + 1 << " Done." << endl;
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
        filename = "output_" + algorithm + "_" + std::to_string(file_index) + ".txt";
    } while (exist(filename));
    fp = fopen(filename.c_str(), "w+");
    for (int i = 0; i < avg.size(); i++) {
        fprintf(fp, "%d %.20f\n", i + 1, avg[i]);
    }
    fclose(fp);

    return 0;
}