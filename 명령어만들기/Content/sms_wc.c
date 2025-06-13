#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    int c, lines = 0, words = 0, in_word = 0;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (!fp) {
        perror("fopen");
        return 1;
    }

    while ((c = fgetc(fp)) != EOF) {
        if (c == '\n') lines++;
        if (isspace(c)) in_word = 0;
        else if (!in_word) {
            in_word = 1;
            words++;
        }
    }

    printf("Lines: %d Words: %d\n", lines, words);
    fclose(fp);
    return 0;
}
