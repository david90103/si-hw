#!/bin/bash

current_directory=$(pwd)

dims=( 30 100 )
pops=( 10 50 )

make clean dep all

for i in "${dims[@]}"
do
    for j in "${pops[@]}"
    do  
        dir=output/output_dim${i}_pop${j}
        mkdir $dir

        cp main $dir
        cp search.sh $dir
        cp plot.gp $dir

        cd $dir
        bash search.sh $i $j
        gnuplot -p plot.gp

        cd $current_directory
    done
done