
reset

#set terminal pngcairo size 640,480 enhanced font 'Verdana,9'
#set output 'plot.png'

set terminal svg size 1280,960 enhanced font 'Verdana,12'
set output 'plot.svg'

set style line 11 lc rgb '#808080' lt 1
set border 3 back ls 11
set tics nomirror

set style line 12 lc rgb '#808080' lt 0 lw 1
set grid back ls 12

# color definitions
set style line 1 lc rgb '#5e9c36' pt 6 ps 1 lt 1 lw 2 # --- green
set style line 2 lc rgb '#a4161a' pt 1 ps 1 lt 1 lw 2 # --- red
set style line 3 lc rgb '#316ad4' pt 6 ps 1 lt 1 lw 2 # --- blue
set style line 4 lc rgb '#9227cc' pt 6 ps 1 lt 1 lw 2 # --- purple
set style line 5 lc rgb '#f29122' pt 6 ps 1 lt 1 lw 2 # --- orange

set key top right
set key font ",15"

set xlabel 'Iteration' font ",16"
set ylabel 'Objective Value' font ",16"

set size 1,1
set origin 0,0
set multiplot layout 2,3 columnsfirst scale 1.1,0.9

plot 'output_gwo_1.txt'     t 'GWO' 		w l ls 1, 	\
	 'output_de_1.txt' 	    t 'DE' 			w l ls 2, 	\
	 'output_pso_1.txt'     t 'PSO' 		w l ls 3
plot 'output_gwo_2.txt'     t 'GWO' 		w l ls 1, 	\
	 'output_de_2.txt' 	    t 'DE' 			w l ls 2, 	\
	 'output_pso_2.txt'     t 'PSO' 		w l ls 3
plot 'output_gwo_3.txt'     t 'GWO' 		w l ls 1, 	\
	 'output_de_3.txt' 	    t 'DE' 			w l ls 2, 	\
	 'output_pso_3.txt'     t 'PSO' 		w l ls 3
plot 'output_gwo_4.txt'     t 'GWO' 		w l ls 1, 	\
	 'output_de_4.txt' 	    t 'DE' 			w l ls 2, 	\
	 'output_pso_4.txt'     t 'PSO' 		w l ls 3
plot 'output_gwo_5.txt'     t 'GWO' 		w l ls 1, 	\
	 'output_de_5.txt' 	    t 'DE' 			w l ls 2, 	\
	 'output_pso_5.txt'     t 'PSO' 		w l ls 3


unset multiplot
