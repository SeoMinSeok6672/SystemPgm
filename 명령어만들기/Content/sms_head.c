#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    char buf[1024];
    int line = 0;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (!fp) {
        perror("fopen");
        return 1;
    }

    while (fgets(buf, sizeof(buf), fp) && line < 10) {
        printf("%s", buf);
        line++;
    }

    fclose(fp);
    return 0;
}
