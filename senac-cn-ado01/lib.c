#include "lib.h"

char* convertBase(int numArguments, char **argument){
    checkArguments(numArguments, argument);
    int base = atoi(argument[2]);
    int newBase = atoi(argument[3]);

    char *result = convertToBase(argument[1], base, newBase);


    return result;
}
void checkArguments(int numArguments, char **argument){
    if(numArguments != 4){
        //printf("ERROR: INVALID QUANTITY OF ARGUMENTS\n");
        exit(1);
    }
    checkBaseArguments(argument);
    checkNumberArgument(argument);

    /*printf("numero: %s\n"
            "base: %s\n"
            "nova Base: %s\n",
            argument[1],argument[2],argument[3]);
            */
}
void checkBaseArguments(char **argument){
    unsigned int j = 0;
    while(j < strlen(argument[2])){
        if(isdigit(argument[2][j]) == false){
            //printf("ERROR: BASES ONLY ACCEPT NUMBERS\n");
            exit(1);
        }    //testando se tem letra na base atual
        j++;
    }
    j = 0;
        while(j < strlen(argument[3])){
        if(isdigit(argument[3][j]) == false){
            //printf("ERROR: BASES ONLY ACCEPT NUMBERS\n");
            exit(1);
        }    //testando se tem letra na base nova
        j++;
    }
    int base = atoi(argument[2]);
    int newBase = atoi (argument[3]);

    if( base < 2 || base > 36 || newBase < 2 || newBase > 36){
        //printf("ERROR: ONLY BASES BETWEEN 2 AND 36\n");
        exit(1);
    }
}
void checkNumberArgument(char ** argument){
    int base = atoi(argument[2]);

    unsigned int i = 0;
    if(base <= 10){ //checa os simbolos validos ate base 10
        while (i < strlen(argument[1])){
            if(argument[1][i] < 48 || argument[1][i] > (49 + (base - 2))){
                //printf("INVALID SYMBOL FOR NUMBER OR INVALID SYMBOL IN NUMBER FOR THIS BASE\n");
                exit(1);
            }
            i++;
        }
    }
    else{   //checa os simbolos válidos para bases maiores do que 10
        while(i < strlen(argument[1])){
            if((argument[1][i] < 48) || (argument[1][i] > 57 && argument[1][i] < 65) || (argument[1][i] > 90 && argument[1][i] < 97) || argument[1][i] > (97 + base - 11)) {
                //printf("INVALID SYMBOL FOR NUMBER OR INVALID SYMBOL IN NUMBER FOR THIS BASE\n");
                exit(1);
            }
            i++;
        }
    }
}
char* convertToBase(char *number, int base, int newBase){

    int numberBase10 = convertToBase10(number, base);

    char *result = convertToBaseX(numberBase10, newBase);

    return result;
}
int convertToBase10(char *number, int base){
    unsigned int i;
    unsigned long long int result = 0;
    int j = strlen(number) - 1;

    for (i = 0; i < strlen(number); i++){
        result += poww(base, j) * intValue(number[i]);
        j--;
        if(result > LIMIT){
            //printf("ERROR: NUMBER BIGGER THAN 2^32\n");
            exit(1);
        }
    }
    return result;
}
char* convertToBaseX(int number, int newBase){
    char *result;
    unsigned int i = 0;
    unsigned int length = 1;
    result = (char*) malloc (arrayLength (number, newBase) * sizeof(char));


    while(true){
        result[i] = charValue(number % newBase);

        if(number / newBase < 1){
            break;
        }
        number /= newBase;
        i++;
        length++;
    }
    result = invertArray(result, length);

    return result;
}
int poww(int number, int expoent){
    if(expoent == 0)    return 1;
    int result = number;

    int i;
    for (i = 1; i < expoent; i++){
        result *= number;
    }
    
    return result;
}
int arrayLength(int number, int newBase){
    int i = 0;
    while(number/newBase >= 1){
        i++;
        number /= newBase;
    }
    i++;
    return i;
}
char* invertArray(char* number, int length){
    char *result;
    result = (char*) malloc (length * sizeof(char));
    int i = 0;
    int j = length - 1;

    while(i < length){
        result[i] = number[j];

        j--;
        i++;
    }

    return result;
}
int intValue(char number){
    if(number >= 48 && number <= 57){
        return (number - 48);
    }
    else if(number >= 65 && number <= 90){
        return (number - 55);
    }
    else {
        return (number - 87);
    }
}
char charValue(int number){
    if(number >= 0 && number <= 9){
        return (number + 48);
    }
    else{
        return (number + 87);
    }
}
