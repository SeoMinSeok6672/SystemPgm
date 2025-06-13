#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    if (access(argv[1], R_OK) == 0)
        printf("파일 읽기 가능\n");
    else
        perror("access");

    return 0;
}
