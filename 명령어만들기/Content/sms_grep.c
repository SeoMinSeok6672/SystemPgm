#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    char buf[1024];

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <pattern> <file>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[2], "r");
    if (!fp) {
        perror("fopen");
        return 1;
    }

    while (fgets(buf, sizeof(buf), fp)) {
        if (strstr(buf, argv[1]))
            printf("%s", buf);
    }

    fclose(fp);
    return 0;
}
