#include <stdio.h>
#include <sys/resource.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <pid> <priority>\n", argv[0]);
        return 1;
    }

    int pid = atoi(argv[1]);
    int prio = atoi(argv[2]);

    if (setpriority(PRIO_PROCESS, pid, prio) == -1) {
        perror("setpriority 실패");
        return 1;
    }

    printf("프로세스 %d 우선순위 %d로 설정 완료\n", pid, prio);
    return 0;
}
