#include "lib.h"

//gcc -W -Wall -pedantic -std=c11 n2m.c lib.c -o n2m
//https://docs.google.com/document/d/1iHlHrIqbzdTEm2iDiwuBjjT9_XHJyOqFQXrchjRcwW8/edit#


int main(int argc, char *argv[]){

        char *result = convertBase(argc, argv);
        
        printf("%s\n", result);
        exit(0);
}

