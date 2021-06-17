#!/bin/bash

DIMENSION=${1:-40}
RUN=30
POPULATION=${2:-40}
ITERATION=50000
FUNCTIONS=("Ackley" "Rastrigin" "Sphere" "Rosenbrock" "Michalewicz" "Griewank" "Schwefel" "SumSquares" "Zakharov" "Powell")
FUNCTIONS_TWO_DIM=("Schaffer" "Bohachevsky_1" "Bohachevsky_2" "Bohachevsky_3" "Booth" "ThreeHump" "DeJong" "Beale")

for f in "${FUNCTIONS[@]}"
do
    ./main gwoex $f $DIMENSION $RUN $ITERATION "" $POPULATION
    ./main gwo   $f $DIMENSION $RUN $ITERATION "" $POPULATION
    ./main pso   $f $DIMENSION $RUN $ITERATION "" $POPULATION 0.4 0.8 0.8
    ./main de    $f $DIMENSION $RUN $ITERATION "" $POPULATION 0.4 0.6
done

# for f in "${FUNCTIONS_TWO_DIM[@]}"
# do
#     ./main gwoex $f 2 $RUN $ITERATION "" $POPULATION
#     ./main gwo   $f 2 $RUN $ITERATION "" $POPULATION
#     ./main pso   $f 2 $RUN $ITERATION "" $POPULATION 0.4 0.8 0.8
#     ./main de    $f 2 $RUN $ITERATION "" $POPULATION 0.4 0.6
# done

echo "Search script done."
