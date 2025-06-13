#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <uid>\n", argv[0]);
        return 1;
    }

    uid_t uid = (uid_t)atoi(argv[1]);
    if (setuid(uid) == -1) {
        perror("setuid 실패");
        return 1;
    }
    printf("프로세스 사용자 ID를 %d로 변경 완료\n", uid);
    return 0;
}
