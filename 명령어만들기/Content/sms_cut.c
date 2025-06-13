#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    char buf[1024];
    int field;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <field_num> <file>\n", argv[0]);
        return 1;
    }

    field = atoi(argv[1]);
    fp = fopen(argv[2], "r");
    if (!fp) {
        perror("fopen");
        return 1;
    }

    while (fgets(buf, sizeof(buf), fp)) {
        char *token;
        int count = 1;
        token = strtok(buf, "\t");
        while (token != NULL) {
            if (count == field) {
                printf("%s\n", token);
                break;
            }
            token = strtok(NULL, "\t");
            count++;
        }
    }

    fclose(fp);
    return 0;
}
