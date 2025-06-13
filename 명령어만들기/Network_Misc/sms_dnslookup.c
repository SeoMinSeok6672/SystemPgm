
#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <domain>\n", argv[0]);
        return 1;
    }

    struct hostent *host = gethostbyname(argv[1]);
    if (!host) {
        fprintf(stderr, "DNS 조회 실패\n");
        return 1;
    }

    char *ip = inet_ntoa(*(struct in_addr *)host->h_addr);
    printf("도메인 %s의 IP 주소: %s\n", argv[1], ip);
    return 0;
}
