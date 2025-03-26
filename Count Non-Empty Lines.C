#include <stdio.h>

int main() {
    FILE *file = fopen("program.c", "r");
    char line[1024];
    int non_empty_lines = 0;

    if (file == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file)) {
        if (line[0] != '\n' && line[0] != '\0') {
            non_empty_lines++;
        }
    }

    fclose(file);
    printf("Number of non-empty lines: %d\n", non_empty_lines);
    return 0;
}
