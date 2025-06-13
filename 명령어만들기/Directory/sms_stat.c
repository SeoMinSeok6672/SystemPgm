#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    struct stat st;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    if (stat(argv[1], &st) == -1) {
        perror("stat");
        return 1;
    }

    printf("Size: %ld bytes\n", st.st_size);
    printf("Mode: %o\n", st.st_mode & 0777);
    printf("Inode: %ld\n", st.st_ino);
    printf("Device: %ld\n", st.st_dev);
    return 0;
}
