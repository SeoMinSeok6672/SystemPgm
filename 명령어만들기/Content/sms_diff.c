#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *fp1, *fp2;
    char buf1[1024], buf2[1024];
    int line = 1;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file1> <file2>\n", argv[0]);
        return 1;
    }

    fp1 = fopen(argv[1], "r");
    fp2 = fopen(argv[2], "r");
    if (!fp1 || !fp2) {
        perror("fopen");
        return 1;
    }

    while (fgets(buf1, sizeof(buf1), fp1) && fgets(buf2, sizeof(buf2), fp2)) {
        if (strcmp(buf1, buf2) != 0)
            printf("Line %d differs:\n%s%s\n", line, buf1, buf2);
        line++;
    }

    fclose(fp1);
    fclose(fp2);
    return 0;
}
