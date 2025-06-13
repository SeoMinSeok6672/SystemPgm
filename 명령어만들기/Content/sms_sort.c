#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000

int cmpstr(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char *lines[MAX_LINES], buf[1024];
    int count = 0;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (!fp) {
        perror("fopen");
        return 1;
    }

    while (fgets(buf, sizeof(buf), fp) && count < MAX_LINES) {
        lines[count++] = strdup(buf);
    }

    qsort(lines, count, sizeof(char *), cmpstr);

    for (int i = 0; i < count; i++) {
        printf("%s", lines[i]);
        free(lines[i]);
    }

    fclose(fp);
    return 0;
}
