#include "lib.h"

int convertBase(int numArguments, char **argument){
    checkArguments(numArguments, argument);
    


    return 0;
}

void checkArguments(int numArguments, char **argument){
    if(numArguments != 4){
        printf("ERROR: INVALID QUANTITY OF ARGUMENTS\n");
        exit(1);
    }

    checkBaseArguments(argument);
    checkNumberArgument(argument);

    printf("numero: %s\n"
            "base: %s\n"
            "nova Base: %s\n",
            argument[1],argument[2],argument[3]);
}
void checkBaseArguments(char **argument){
    unsigned int j = 0;
    while(j < strlen(argument[2])){
        if(isdigit(argument[2][j]) == false){
            printf("ERROR: BASES ONLY ACCEPT NUMBERS\n");
            exit(2);
        }    //testando se tem letra na base atual
        j++;
    }
    j = 0;
        while(j < strlen(argument[3])){
        if(isdigit(argument[3][j]) == false){
            printf("ERROR: BASES ONLY ACCEPT NUMBERS\n");
            exit(2);
        }    //testando se tem letra na base nova
        j++;
    }
    int base = atoi(argument[2]);
    int newBase = atoi (argument[3]);

    if( base < 2 || base > 32 || newBase < 2 || newBase > 32){
        printf("ERROR: ONLY BASES BETWEEN 2 AND 32\n");
        exit(3);
    }
}
void checkNumberArgument(char ** argument){
    int base = atoi(argument[2]);

    unsigned int i = 0;
    if(base <= 10){ //checa os simbolos validos ate base 10
        while (i < strlen(argument[1])){
            if(argument[1][i] < 48 || argument[1][i] > (49 + (base - 2))){
                printf("INVALID SYMBOL FOR NUMBER OR INVALID SYMBOL IN NUMBER FOR THIS BASE\n");
                exit(4);
            }
            i++;
        }
    }
    else{   //checa os simbolos válidos para bases maiores do que 10
        while(i < strlen(argument[1])){
            if(argument[1][i] < 48 || (argument[1][i] > 57 && argument[1][i] < 97) || argument[1][i] > (97 + base - 11)) {
                printf("INVALID SYMBOL FOR NUMBER OR INVALID SYMBOL IN NUMBER FOR THIS BASE\n");
                exit(4);
            }
            i++;
        }
    }
}
