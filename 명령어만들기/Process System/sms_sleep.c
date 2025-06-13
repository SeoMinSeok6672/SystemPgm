#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <seconds>\n", argv[0]);
        return 1;
    }

    int sec = atoi(argv[1]);
    printf("%d초 동안 대기합니다...\n", sec);
    sleep(sec);
    printf("대기 종료\n");
    return 0;
}
