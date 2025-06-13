#include <stdio.h>
#include <unistd.h>

int main() {
    printf("현재 그룹 GID: %d\n", getgid());
    return 0;
}
