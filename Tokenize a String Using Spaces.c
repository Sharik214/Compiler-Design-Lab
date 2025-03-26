#include <stdio.h>
#include <string.h>

int main() {
    char string[] = "int x = 10;";
    char *token = strtok(string, " ");

    while (token != NULL) {
        printf("Token: %s\n", token);
        token = strtok(NULL, " ");
    }

    return 0;
}
