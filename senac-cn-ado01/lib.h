#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LIMIT 4294967296

typedef int bool;
#define true 1
#define false 0

char* convertBase(int numArguments, char **arguments);
void checkArguments(int numArguments, char **argument);
void checkBaseArguments(char **argument);
void checkNumberArgument(char ** argument);
char* convertToBase(char *number, int base, int newBase);
int convertToBase10(char *number, int base);
char* convertToBaseX(int number, int newBase);
int poww(int number, int expoent);
int arrayLength(int number, int newBase);
char* invertArray(char* number, int length);
int intValue(char number);
char charValue(int number);