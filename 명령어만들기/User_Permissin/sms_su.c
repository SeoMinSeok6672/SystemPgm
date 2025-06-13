#include <stdio.h>
#include <unistd.h>

int main() {
    printf("현재 사용자 UID: %d\n", getuid());
    printf("이 프로그램은 실제 su 명령어 대체는 어렵고,\nUID 출력 예시입니다.\n");
    return 0;
}
