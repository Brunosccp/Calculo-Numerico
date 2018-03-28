#include "lib.h"


void generatePlot(){
    FILE *euler_plot = popen("gnuplot -persistent", "w");

    fprintf(euler_plot, "set term png \n");
    fprintf(euler_plot, "set output 'euler.png' \n");
    fprintf(euler_plot, "set logscale x \n");
    fprintf(euler_plot, "set yrange [0:4] \n");

    fprintf(euler_plot, "plot '-' w l \n");
    double i;
    double result;
    for (i = 1; i <= 10e20; i *= 10){
        result = pow((1 + 1/i), i);
        fprintf(euler_plot, "%f %f\n", i, result);
        printf("valor %g de 1/i: %.23f\n", i,1/i);
    }

    fprintf(euler_plot, "e");

    fclose(euler_plot);
}