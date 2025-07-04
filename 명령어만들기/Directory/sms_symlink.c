#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <target> <symlink>\n", argv[0]);
        return 1;
    }

    if (symlink(argv[1], argv[2]) == -1) {
        perror("symlink");
        return 1;
    }

    return 0;
}
