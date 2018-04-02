#include "lib.h"

//gcc -W -Wall -pedantic -lm -std=c11 euler.c lib.c -o euler
//https://docs.google.com/document/d/1iHlHrIqbzdTEm2iDiwuBjjT9_XHJyOqFQXrchjRcwW8/edit#

int main(){
    //printf("o resultado deu: %f", eulerNumber());
    //eulerNumber();
    generateFloatPlot();
    generateDoublePlot();
    generateLongDoublePlot();

    exit(0);
}
