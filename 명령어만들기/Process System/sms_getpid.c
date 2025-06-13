#include <stdio.h>
#include <unistd.h>

int main() {
    printf("프로세스 ID: %d\n", getpid());
    return 0;
}
