
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <mode(8진수)> <file>\n", argv[0]);
        return 1;
    }

    mode_t mode = strtol(argv[1], NULL, 8);
    if (chmod(argv[2], mode) == -1) {
        perror("chmod 실패");
        return 1;
    }

    printf("파일 '%s' 권한을 %o(8진수)로 변경 완료\n", argv[2], mode);
    return 0;
}
