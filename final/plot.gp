
reset

set terminal pngcairo size 1280,960 enhanced font 'Verdana,9'
set output 'plot.png'

#set terminal svg size 1280,960 enhanced font 'Verdana,12'
#set output 'plot.svg'

set style line 11 lc rgb '#808080' lt 1
set border 3 back ls 11
set tics nomirror

set style line 12 lc rgb '#808080' lt 0 lw 1
set grid back ls 12

# color definitions
set style line 1 lc rgb '#a4161a' pt 1 ps 1 lt 1 lw 2 # --- red
set style line 2 lc rgb '#5e9c36' pt 6 ps 1 lt 1 lw 2 # --- green
set style line 3 lc rgb '#316ad4' pt 6 ps 1 lt 1 lw 2 # --- blue
set style line 4 lc rgb '#9227cc' pt 6 ps 1 lt 1 lw 2 # --- purple
set style line 5 lc rgb '#f29122' pt 6 ps 1 lt 1 lw 2 # --- orange

set key top right
set key font ",12"

set xlabel 'Evaluations' font ",14"
set ylabel ' ' font ",16"

set size 1,1
set origin 0,0
set multiplot layout 3,4 scale 1.1,0.9

set xrange[1:30000]

set title "Ackley" font ",16"
set xrange[1:30000]
set yrange[0:25]
plot 'output_Ackley_gwo_1.txt'          t 'GWO'        w l ls 1,  \
     'output_Ackley_gwoex_1.txt'        t 'SRGWO'      w l ls 2,  \
     'output_Ackley_de_1.txt'           t 'DE'         w l ls 3,  \
     'output_Ackley_pso_1.txt'          t 'PSO'        w l ls 4

set title "Rastrigin" font ",16"
set xrange[1:30000]
set yrange[0:1000]
plot 'output_Rastrigin_gwo_1.txt'       t 'GWO'        w l ls 1,  \
     'output_Rastrigin_gwoex_1.txt'     t 'SRGWO'      w l ls 2,  \
     'output_Rastrigin_de_1.txt'        t 'DE'         w l ls 3,  \
     'output_Rastrigin_pso_1.txt'       t 'PSO'        w l ls 4

set title "Sphere" font ",16"
set xrange[1:30000]
set yrange[0:10]
plot 'output_Sphere_gwo_1.txt'          t 'GWO'        w l ls 1,  \
     'output_Sphere_gwoex_1.txt'        t 'SRGWO'      w l ls 2,  \
     'output_Sphere_de_1.txt'           t 'DE'         w l ls 3,  \
     'output_Sphere_pso_1.txt'          t 'PSO'        w l ls 4

set title "Rosenbrock" font ",16"
set xrange[1:30000]
set yrange[20:5000]
plot 'output_Rosenbrock_gwo_1.txt'      t 'GWO'        w l ls 1,  \
     'output_Rosenbrock_gwoex_1.txt'    t 'SRGWO'      w l ls 2,  \
     'output_Rosenbrock_de_1.txt'       t 'DE'         w l ls 3,  \
     'output_Rosenbrock_pso_1.txt'      t 'PSO'        w l ls 4

set title "Michalewicz" font ",16"
set xrange[1:100000]
set yrange[*:*]
plot 'output_Michalewicz_gwo_1.txt'     t 'GWO'        w l ls 1,  \
     'output_Michalewicz_gwoex_1.txt'   t 'SRGWO'      w l ls 2,  \
     'output_Michalewicz_de_1.txt'      t 'DE'         w l ls 3,  \
     'output_Michalewicz_pso_1.txt'     t 'PSO'        w l ls 4

set title "Griewank" font ",16"
set xrange[1:30000]
set yrange[0:600]
plot 'output_Griewank_gwo_1.txt'        t 'GWO'        w l ls 1,  \
     'output_Griewank_gwoex_1.txt'      t 'SRGWO'      w l ls 2,  \
     'output_Griewank_de_1.txt'         t 'DE'         w l ls 3,  \
     'output_Griewank_pso_1.txt'        t 'PSO'        w l ls 4

set title "Schwefel" font ",16"
set xrange[1:100000]
set yrange[:18000]
plot 'output_Schwefel_gwo_1.txt'        t 'GWO'        w l ls 1,  \
     'output_Schwefel_gwoex_1.txt'      t 'SRGWO'      w l ls 2,  \
     'output_Schwefel_de_1.txt'         t 'DE'         w l ls 3,  \
     'output_Schwefel_pso_1.txt'        t 'PSO'        w l ls 4

set title "SumSquares" font ",16"
set xrange[1:30000]
set yrange[0:10000]
plot 'output_SumSquares_gwo_1.txt'      t 'GWO'        w l ls 1,  \
     'output_SumSquares_gwoex_1.txt'    t 'SRGWO'      w l ls 2,  \
     'output_SumSquares_de_1.txt'       t 'DE'         w l ls 3,  \
     'output_SumSquares_pso_1.txt'      t 'PSO'        w l ls 4

set title "Zakharov" font ",16"
set xrange[1:30000]
set yrange[0:2000]
plot 'output_Zakharov_gwo_1.txt'        t 'GWO'        w l ls 1,  \
     'output_Zakharov_gwoex_1.txt'      t 'SRGWO'      w l ls 2,  \
     'output_Zakharov_de_1.txt'         t 'DE'         w l ls 3,  \
     'output_Zakharov_pso_1.txt'        t 'PSO'        w l ls 4

set title "Powell" font ",16"
set xrange[1:30000]
set yrange[0:20000]
plot 'output_Powell_gwo_1.txt'          t 'GWO'        w l ls 1,  \
     'output_Powell_gwoex_1.txt'        t 'SRGWO'      w l ls 2,  \
     'output_Powell_de_1.txt'           t 'DE'         w l ls 3,  \
     'output_Powell_pso_1.txt'          t 'PSO'        w l ls 4

unset multiplot
