#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    char prev[1024] = "", curr[1024];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (!fp) {
        perror("fopen");
        return 1;
    }

    while (fgets(curr, sizeof(curr), fp)) {
        if (strcmp(prev, curr) != 0) {
            printf("%s", curr);
            strcpy(prev, curr);
        }
    }

    fclose(fp);
    return 0;
}
