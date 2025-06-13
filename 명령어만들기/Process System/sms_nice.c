#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <increment>\n", argv[0]);
        return 1;
    }

    int inc = atoi(argv[1]);
    int prio = nice(inc);

    if (prio == -1 && errno != 0) {
        perror("nice 실패");
        return 1;
    }

    printf("우선순위 증가 %d, 현재 우선순위: %d\n", inc, prio);
    return 0;
}
