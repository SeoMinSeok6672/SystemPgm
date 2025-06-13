#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handler(int signum) {
    printf("알람 시그널(%d) 받음!\n", signum);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <seconds>\n", argv[0]);
        return 1;
    }

    signal(SIGALRM, handler);
    alarm(atoi(argv[1]));
    printf("알람 %d초 후에 설정됨\n", atoi(argv[1]));
    pause(); // 시그널 받을 때까지 대기

    return 0;
}
