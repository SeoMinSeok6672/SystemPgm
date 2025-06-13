#include <stdio.h>
#include <string.h>

#define MAX_LINES 1024

int main(int argc, char *argv[]) {
    FILE *fp;
    char *lines[MAX_LINES];
    char buffer[1024];
    int count = 0, i;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (!fp) {
        perror("fopen");
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), fp)) {
        lines[count % 10] = strdup(buffer);
        count++;
    }

    int start = count > 10 ? count % 10 : 0;
    int total = count < 10 ? count : 10;

    for (i = 0; i < total; i++)
        printf("%s", lines[(start + i) % 10]);

    fclose(fp);
    return 0;
}
