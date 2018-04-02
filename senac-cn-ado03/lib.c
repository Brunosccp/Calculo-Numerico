#include "lib.h"

void generateFloatPlot(){
    FILE *euler_plot = popen("gnuplot -persistent", "w");

    fprintf(euler_plot, "set term png \n");
    fprintf(euler_plot, "set output 'FloatEuler.png' \n");
    fprintf(euler_plot, "set logscale x \n");
    fprintf(euler_plot, "set yrange [0:4] \n");
    fprintf(euler_plot, "set title 'Euler Approximation with Float' \n");

    fprintf(euler_plot, "plot '-' w l \n");
    float i;
    float result;
    for (i = 1; i <= 10e20; i *= 10){
        result = powf((1 + 1/i), i);
        fprintf(euler_plot, "%g %f\n", i, result);
        //printf("valor %f de %f\n", i, result);
    }
    fprintf(euler_plot, "e");

    fclose(euler_plot);
}

void generateDoublePlot(){
    FILE *euler_plot = popen("gnuplot -persistent", "w");

    fprintf(euler_plot, "set term png \n");
    fprintf(euler_plot, "set output 'DoubleEuler.png' \n");
    fprintf(euler_plot, "set logscale x \n");
    fprintf(euler_plot, "set yrange [0:4] \n");
    fprintf(euler_plot, "set title 'Euler Approximation with Double' \n");

    fprintf(euler_plot, "plot '-' w l \n");
    double i;
    double result;
    for (i = 1; i <= 10e20; i *= 10){
        result = pow((1 + 1/i), i);
        fprintf(euler_plot, "%g %f\n", i, result);
        //printf("valor %f de %f\n", i, result);
    }

    fprintf(euler_plot, "e");

    fclose(euler_plot);
}

void generateLongDoublePlot(){
    FILE *euler_plot = popen("gnuplot -persistent", "w");

    fprintf(euler_plot, "set term png \n");
    fprintf(euler_plot, "set output 'LongDoubleEuler.png' \n");
    fprintf(euler_plot, "set logscale x \n");
    fprintf(euler_plot, "set yrange [0:4] \n");
    fprintf(euler_plot, "set title 'Euler Approximation with Long Double' \n");

    fprintf(euler_plot, "plot '-' w l \n");
    long double i;
    long double result;
    for (i = 1; i <= 10e20; i *= 10){
        result = powl((1 + 1/i), i);
        fprintf(euler_plot, "%Lf %Lf\n", i, result);
        //printf("valor %Lg de %Lf\n", i, result);
    }

    fprintf(euler_plot, "e");

    fclose(euler_plot);
}