#include <stdio.h>
#include <unistd.h>

int main() {
    printf("현재 사용자 UID: %d\n", getuid());
    return 0;
}
