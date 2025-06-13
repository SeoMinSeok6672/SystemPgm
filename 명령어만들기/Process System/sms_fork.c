#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork 실패");
        return 1;
    } else if (pid == 0) {
        printf("자식 프로세스: PID=%d\n", getpid());
    } else {
        printf("부모 프로세스: PID=%d, 자식 PID=%d\n", getpid(), pid);
    }
    return 0;
}
