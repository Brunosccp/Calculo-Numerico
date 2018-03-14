#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertStringToInt(char **argv, int *numero, int *baseAtual, int *baseNova);

int main(int argc, char *argv[]){

    int numero, baseAtual, baseNova;

    printf("quantidade de argumentos: %d\n"
            "argumentos[0]: %s\n", argc, argv[1]);


    //para bases menores ou igual a 10
    convertStringToInt(argv, &numero, &baseAtual, &baseNova);

    printf("numero: %d\n"
            "baseAtual: %d\n"
            "baseNova: %d\n"
            , numero, baseAtual, baseNova);
    

    exit(0);
}
void convertStringToInt(char **argv, int *numero, int *baseAtual, int *baseNova){
    if(strcmp("0", argv[1]) == 0){
        *numero = atoi(argv[1]);     
    }
    *baseAtual = atoi(argv[2]);
    *baseNova = atoi(argv[3]);

    return;
}

