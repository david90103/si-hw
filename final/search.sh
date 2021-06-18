#!/bin/bash

DIMENSION=${1:-40}
RUN=30
POPULATION=${2:-30}
ITERATION=50000
EVALUATIONS=30000
FUNCTIONS=("Ackley" "Rastrigin" "Sphere" "Rosenbrock" "Griewank" "SumSquares" "Zakharov" "Powell")
FUNCTIONS_EVAL_100000=("Michalewicz" "Schwefel")
FUNCTIONS_TWO_DIM=("Schaffer" "Bohachevsky_1" "Bohachevsky_2" "Bohachevsky_3" "Booth" "ThreeHump" "DeJong" "Beale")

for f in "${FUNCTIONS[@]}"
do
    ./main gwoex $f $DIMENSION $RUN $ITERATION $EVALUATIONS "" $POPULATION
    ./main gwo   $f $DIMENSION $RUN $ITERATION $EVALUATIONS "" $POPULATION
    ./main pso   $f $DIMENSION $RUN $ITERATION $EVALUATIONS "" $POPULATION 0.4 0.8 0.8
    ./main de    $f $DIMENSION $RUN $ITERATION $EVALUATIONS "" $POPULATION 0.4 0.6
done

for f in "${FUNCTIONS_EVAL_100000[@]}"
do
    ./main gwoex $f $DIMENSION $RUN $ITERATION 100000 "" $POPULATION
    ./main gwo   $f $DIMENSION $RUN $ITERATION 100000 "" $POPULATION
    ./main pso   $f $DIMENSION $RUN $ITERATION 100000 "" $POPULATION 0.4 0.8 0.8
    ./main de    $f $DIMENSION $RUN $ITERATION 100000 "" $POPULATION 0.4 0.6
done

# for f in "${FUNCTIONS_TWO_DIM[@]}"
# do
#     ./main gwoex $f 2 $RUN $ITERATION $EVALUATIONS "" $POPULATION
#     ./main gwo   $f 2 $RUN $ITERATION $EVALUATIONS "" $POPULATION
#     ./main pso   $f 2 $RUN $ITERATION $EVALUATIONS "" $POPULATION 0.4 0.8 0.8
#     ./main de    $f 2 $RUN $ITERATION $EVALUATIONS "" $POPULATION 0.4 0.6
# done

echo "Search script done."
