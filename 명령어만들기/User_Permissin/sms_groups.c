#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <grp.h>
#include <stdlib.h>

int main() {
    gid_t groups[32];
    int ngroups = 32;

    if (getgroups(ngroups, groups) == -1) {
        perror("getgroups 실패");
        return 1;
    }

    printf("사용자 그룹 목록: ");
    for (int i = 0; i < ngroups; i++) {
        printf("%d ", groups[i]);
    }
    printf("\n");
    return 0;
}
