#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file> <mode>\n", argv[0]);
        fprintf(stderr, "mode: R_OK(4), W_OK(2), X_OK(1), F_OK(0)\n");
        return 1;
    }

    int mode = atoi(argv[2]);
    if (access(argv[1], mode) == 0) {
        printf("파일 '%s'에 접근 가능\n", argv[1]);
    } else {
        perror("access 실패");
        return 1;
    }
    return 0;
}
