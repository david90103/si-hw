#!/bin/bash

DIMENSION=${1:-30}
RUN=30
POPULATION=${2:-10}
ITERATION=1000

# ./main pso [function] [dimension] [runs] [iterations] [seedfile] [population size] [w] [c1] [c2]
./main pso ackley $DIMENSION $RUN $ITERATION "" $POPULATION 0.5 2 2 
./main pso rastrigin $DIMENSION $RUN $ITERATION "" $POPULATION 0.5 2 2 
./main pso sphere $DIMENSION $RUN $ITERATION "" $POPULATION 0.5 2 2 
./main pso rosenbrock $DIMENSION $RUN $ITERATION "" $POPULATION 0.5 2 2 
./main pso michalewicz $DIMENSION $RUN $ITERATION "" $POPULATION 0.5 2 2 

./main de ackley $DIMENSION $RUN $ITERATION "" $POPULATION 0.4 0.6
./main de rastrigin $DIMENSION $RUN $ITERATION "" $POPULATION 0.4 0.6
./main de sphere $DIMENSION $RUN $ITERATION "" $POPULATION 0.4 0.6
./main de rosenbrock $DIMENSION $RUN $ITERATION "" $POPULATION 0.4 0.6
./main de michalewicz $DIMENSION $RUN $ITERATION "" $POPULATION 0.4 0.6

./main gwo ackley $DIMENSION $RUN $ITERATION "" $POPULATION
./main gwo rastrigin $DIMENSION $RUN $ITERATION "" $POPULATION
./main gwo sphere $DIMENSION $RUN $ITERATION "" $POPULATION
./main gwo rosenbrock $DIMENSION $RUN $ITERATION "" $POPULATION
./main gwo michalewicz $DIMENSION $RUN $ITERATION "" $POPULATION


# cross_rate=( 0.3 0.4 )
# ff=( 0.6 0.7 )

# for i in "${cross_rate[@]}"
# do
#     for j in "${ff[@]}"
#     do
#         ./main de ackley $DIMENSION $RUN $ITERATION "" $POPULATION $i $j > output_de_cross${i}_f${j}.txt
#     done
# done

echo "Search script done."
