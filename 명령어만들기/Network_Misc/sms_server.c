#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket 실패");
        return 1;
    }

    struct sockaddr_in addr = {0};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind 실패");
        return 1;
    }

    if (listen(server_fd, 5) < 0) {
        perror("listen 실패");
        return 1;
    }

    printf("서버가 8080 포트에서 대기 중...\n");
    int client_fd = accept(server_fd, NULL, NULL);
    if (client_fd < 0) {
        perror("accept 실패");
        return 1;
    }

    char buffer[1024];
    int n = read(client_fd, buffer, sizeof(buffer)-1);
    if (n > 0) {
        buffer[n] = '\0';
        printf("클라이언트 메시지: %s\n", buffer);
        write(client_fd, "메시지 받음\n", 10);
    }

    close(client_fd);
    close(server_fd);
    return 0;
}
