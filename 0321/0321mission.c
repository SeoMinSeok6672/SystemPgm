#include <stdio.h>

int main() {
    char name[50];
    char studentID[20];

    printf("이름을 입력하세요: ");
    scanf("%s", name);

    printf("학번을 입력하세요: ");
    scanf("%s", studentID);

    printf("\n[출력 결과]\n");
    printf("이름: %s\n", name);
    printf("학번: %s\n", studentID);

    return 0;
}

