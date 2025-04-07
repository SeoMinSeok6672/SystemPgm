#include <stdio.h>

int main() {
    int num;
    printf("0~255 사이의 숫자를 입력하세요: ");
    scanf("%d", &num);

    if (num < 0 || num > 255) {
        printf("잘못된 입력입니다.\n");
        return 1;
    }

    // 2진수 출력
    printf("2진수: ");
    int count = 0;
    for (int i = 7; i >= 0; i--) {
        int bit = (num >> i) & 1;
        printf("%d", bit);
        if (bit == 1) count++;
    }
    printf("\n");

    // 1의 개수 출력
    printf("1의 개수: %d개\n", count);

    // 상위 4비트 출력
    int high4 = (num >> 4) & 0xF;
    printf("상위 4비트: ");
    for (int i = 3; i >= 0; i--) {
        printf("%d", (high4 >> i) & 1);
    }
    printf("\n");

    return 0;
}
