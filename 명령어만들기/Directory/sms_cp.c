#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int src, dest;
    char buf[BUF_SIZE];
    ssize_t n;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }

    src = open(argv[1], O_RDONLY);
    if (src < 0) {
        perror("open source");
        return 1;
    }

    dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest < 0) {
        perror("open dest");
        close(src);
        return 1;
    }

    while ((n = read(src, buf, BUF_SIZE)) > 0) {
        write(dest, buf, n);
    }

    close(src);
    close(dest);
    return 0;
}
