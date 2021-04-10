#!/bin/bash

DIMENSION=30
RUN=30
POPULATION=20
ITERATION=500

# ./main pso [function] [dimension] [runs] [iterations] [seedfile] [population size] [w] [c1] [c2]
./main pso ackley $DIMENSION $RUN $ITERATION "" $POPULATION 0.01 0.7 0.5
./main pso rastrigin $DIMENSION $RUN $ITERATION "" $POPULATION 0.01 0.7 0.5
./main pso sphere $DIMENSION $RUN $ITERATION "" $POPULATION 0.01 0.7 0.5
./main pso rosenbrock $DIMENSION $RUN $ITERATION "" $POPULATION 0.01 0.7 0.5
./main pso michalewicz $DIMENSION $RUN $ITERATION "" $POPULATION 0.01 0.7 0.5

./main de ackley $DIMENSION $RUN $ITERATION "" $POPULATION 0.7 0.4
./main de rastrigin $DIMENSION $RUN $ITERATION "" $POPULATION 0.7 0.4
./main de sphere $DIMENSION $RUN $ITERATION "" $POPULATION 0.7 0.4
./main de rosenbrock $DIMENSION $RUN $ITERATION "" $POPULATION 0.7 0.4
./main de michalewicz $DIMENSION $RUN $ITERATION "" $POPULATION 0.7 0.4

./main gwo ackley $DIMENSION $RUN $ITERATION "" $POPULATION
./main gwo rastrigin $DIMENSION $RUN $ITERATION "" $POPULATION
./main gwo sphere $DIMENSION $RUN $ITERATION "" $POPULATION
./main gwo rosenbrock $DIMENSION $RUN $ITERATION "" $POPULATION
./main gwo michalewicz $DIMENSION $RUN $ITERATION "" $POPULATION

echo "Search script done."
