#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <gid>\n", argv[0]);
        return 1;
    }

    gid_t gid = (gid_t)atoi(argv[1]);
    if (setgid(gid) == -1) {
        perror("setgid 실패");
        return 1;
    }
    printf("프로세스 그룹 ID를 %d로 변경 완료\n", gid);
    return 0;
}
