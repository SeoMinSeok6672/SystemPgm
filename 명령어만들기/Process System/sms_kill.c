#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <pid>\n", argv[0]);
        return 1;
    }

    int pid = atoi(argv[1]);
    if (kill(pid, SIGTERM) == -1) {
        perror("kill");
        return 1;
    }
    printf("프로세스 %d에 SIGTERM 신호 전송\n", pid);
    return 0;
}
