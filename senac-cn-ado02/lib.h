#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define PI 3.14159265359

typedef int bool;
#define true 1
#define false 0

void generateDat();
double cosseno(double x);
double seno(double x);
double fat(int x);
double absolutError(double x, double y);
double relativeError(double absolutError, double x);