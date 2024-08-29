#include <stdio.h>
#include <stdlib.h>

extern char **environ;

void displayEnvVariables() {

    char **current_env = environ;
    
    while (*currEnv != NULL) {
        printf("%s\n", *currEnv);
        currEnv++;
    }
}

int main() {
    displayEnvVariables();
    return 0;
}
