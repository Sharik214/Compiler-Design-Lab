#include <stdio.h>
#include <string.h>

int main() {
    FILE *file = fopen("program.c", "r");
    char line[1024];
    int comment_lines = 0;

    if (file == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "//") || strstr(line, "/*") || strstr(line, "*/")) {
            comment_lines++;
        }
    }

    fclose(file);
    printf("Number of comment lines: %d\n", comment_lines);
    return 0;
}
