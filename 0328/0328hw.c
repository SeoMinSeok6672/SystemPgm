#include <stdio.h>

int main() {
    char ch;

    while (1) {
        printf("문자 입력 : ");
        scanf(" %c", &ch); 
        
        if (ch == '0') { 
            break;
        }
        
        if (ch >= 'A' && ch <= 'Z') {
            printf("%c의 소문자는 %c\n", ch, ch + ('a' - 'A'));
        }
        else if (ch >= 'a' && ch <= 'z') {
            printf("%c의 대문자는 %c\n", ch, ch - ('a' - 'A'));
        }
        else {
            printf("잘못된 입력\n");
        }
    }

    printf("프로그램을 종료합니다.\n");
    return 0;
}

