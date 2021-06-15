#!/bin/bash

DIMENSION=${1:-30}
# DIMENSION=30
RUN=30
POPULATION=${2:-30}
# POPULATION=40
ITERATION=500

# ./main pso [function] [dimension] [runs] [iterations] [seedfile] [population size] [w] [c1] [c2]
./main pso Ackley $DIMENSION $RUN $ITERATION "" $POPULATION 0.4 0.8 0.8
./main pso Rastrigin $DIMENSION $RUN $ITERATION "" $POPULATION 0.4 0.8 0.8
./main pso Sphere $DIMENSION $RUN $ITERATION "" $POPULATION 0.4 0.8 0.8
./main pso Rosenbrock $DIMENSION $RUN $ITERATION "" $POPULATION 0.4 0.8 0.8
./main pso Michalewicz $DIMENSION $RUN $ITERATION "" $POPULATION 0.4 0.8 0.8

./main de Ackley $DIMENSION $RUN $ITERATION "" $POPULATION 0.4 0.6
./main de Rastrigin $DIMENSION $RUN $ITERATION "" $POPULATION 0.4 0.6
./main de Sphere $DIMENSION $RUN $ITERATION "" $POPULATION 0.4 0.6
./main de Rosenbrock $DIMENSION $RUN $ITERATION "" $POPULATION 0.4 0.6
./main de Michalewicz $DIMENSION $RUN $ITERATION "" $POPULATION 0.4 0.6

./main gwo Ackley $DIMENSION $RUN $ITERATION "" $POPULATION
./main gwo Rastrigin $DIMENSION $RUN $ITERATION "" $POPULATION
./main gwo Sphere $DIMENSION $RUN $ITERATION "" $POPULATION
./main gwo Rosenbrock $DIMENSION $RUN $ITERATION "" $POPULATION
./main gwo Michalewicz $DIMENSION $RUN $ITERATION "" $POPULATION

echo "Search script done."
