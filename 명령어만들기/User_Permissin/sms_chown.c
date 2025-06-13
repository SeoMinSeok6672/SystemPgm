#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <user> <group> <file>\n", argv[0]);
        return 1;
    }

    struct passwd *pwd = getpwnam(argv[1]);
    struct group *grp = getgrnam(argv[2]);

    if (!pwd || !grp) {
        fprintf(stderr, "사용자 또는 그룹 이름이 잘못됨\n");
        return 1;
    }

    if (chown(argv[3], pwd->pw_uid, grp->gr_gid) == -1) {
        perror("chown 실패");
        return 1;
    }

    printf("파일 '%s' 소유자 %s, 그룹 %s로 변경 완료\n", argv[3], argv[1], argv[2]);
    return 0;
}
