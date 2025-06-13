#include <stdio.h>
#include <sys/utsname.h>

int main() {
    struct utsname info;
    if (uname(&info) == -1) {
        perror("uname 실패");
        return 1;
    }

    printf("시스템 정보:\n");
    printf("  운영체제: %s\n", info.sysname);
    printf("  노드 이름: %s\n", info.nodename);
    printf("  릴리즈: %s\n", info.release);
    printf("  버전: %s\n", info.version);
    printf("  머신: %s\n", info.machine);

    return 0;
}
