#include <stdio.h>
#include <unistd.h>

int main() {
    char hostname[256];
    if (gethostname(hostname, sizeof(hostname)) == -1) {
        perror("gethostname 실패");
        return 1;
    }
    printf("호스트 이름: %s\n", hostname);
    return 0;
}
