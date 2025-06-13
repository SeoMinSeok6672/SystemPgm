
#include <stdio.h>
#include <unistd.h>

int main() {
    printf("현재 프로세스 ID: %d\n", getpid());
    // 간단 예시, 실제 ps 명령은 복잡하므로 getpid() 출력으로 대체
    return 0;
}
