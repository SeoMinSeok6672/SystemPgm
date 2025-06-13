#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP> <port>\n", argv[0]);
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket 실패");
        return 1;
    }

    struct sockaddr_in addr = {0};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &addr.sin_addr) <= 0) {
        perror("inet_pton 실패");
        close(sock);
        return 1;
    }

    int res = connect(sock, (struct sockaddr *)&addr, sizeof(addr));
    if (res == 0) {
        printf("포트 %s 열려있음\n", argv[2]);
    } else {
        printf("포트 %s 닫혀있거나 접근 불가\n", argv[2]);
    }

    close(sock);
    return 0;
}
