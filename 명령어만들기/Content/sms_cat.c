
#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    int c;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (!fp) {
        perror("fopen");
        return 1;
    }

    while ((c = fgetc(fp)) != EOF)
        putchar(c);

    fclose(fp);
    return 0;
}
