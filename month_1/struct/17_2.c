#include <stdio.h>

struct MyStruct {
    double grade;   // 8 바이트
    int score;      // 4 바이트
    short num;      // 2 바이트
    char ch1;       // 1 바이트
    char ch2;       // 1 바이트
    char ch3;       // 1 바이트
};

int main() {
    printf("구조체 크기: %zu 바이트\n", sizeof(struct MyStruct));
    return 0;
}
