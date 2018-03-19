#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef int bool;
#define true 1
#define false 0

int convertBase(int numArguments, char **arguments);
void checkArguments(int numArguments, char **argument);
void checkBaseArguments(char **argument);
void checkNumberArgument(char ** argument);