#!/bin/bash

current_directory=$(pwd)

dims=( 40 )
pops=( 40 )

make clean dep all

for i in "${dims[@]}"
do
    for j in "${pops[@]}"
    do  
        dir=output/output_dim${i}_pop${j}
        mkdir -p $dir

        cp main $dir
        cp search.sh $dir
        cp plot.gp $dir

        cd $dir
        bash search.sh $i $j
        gnuplot -p plot.gp

        cd $current_directory
    done
done