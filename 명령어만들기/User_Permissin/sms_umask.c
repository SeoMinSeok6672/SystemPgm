#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    mode_t old_umask = umask(0);
    printf("기존 umask 값: %03o (8진수)\n", old_umask);
    umask(old_umask); // 원래대로 복원
    return 0;
}
