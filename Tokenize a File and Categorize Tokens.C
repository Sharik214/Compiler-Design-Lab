#include <stdio.h>
#include <ctype.h>
#include <string.h>

int is_keyword(char *token) {
    char *keywords[] = {"int", "return", "if", "else"};
    for (int i = 0; i < 4; i++) {
        if (strcmp(token, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    FILE *file = fopen("program.c", "r");
    char token[256];
    int c;

    if (file == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    while (fscanf(file, "%s", token) != EOF) {
        if (is_keyword(token)) {
            printf("Keyword: %s\n", token);
        } else if (isalpha(token[0])) {
            printf("Identifier: %s\n", token);
        } else if (isdigit(token[0])) {
            printf("Constant: %s\n", token);
        }
    }

    fclose(file);
    return 0;
}
