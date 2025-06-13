#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork 실패");
        return 1;
    } else if (pid == 0) {
        printf("자식 프로세스 실행 중...\n");
        sleep(2);
        return 42;
    } else {
        int status;
        wait(&status);
        if (WIFEXITED(status)) {
            printf("자식 종료, 상태 코드: %d\n", WEXITSTATUS(status));
        }
    }
    return 0;
}
