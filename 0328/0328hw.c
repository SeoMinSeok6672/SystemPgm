#include <stdio.h>

int main() {
    char ch;

    while (1) {
        printf("���� �Է� : ");
        scanf(" %c", &ch); 
        
        if (ch == '0') { 
            break;
        }
        
        if (ch >= 'A' && ch <= 'Z') {
            printf("%c�� �ҹ��ڴ� %c\n", ch, ch + ('a' - 'A'));
        }
        else if (ch >= 'a' && ch <= 'z') {
            printf("%c�� �빮�ڴ� %c\n", ch, ch - ('a' - 'A'));
        }
        else {
            printf("�߸��� �Է�\n");
        }
    }

    printf("���α׷��� �����մϴ�.\n");
    return 0;
}

