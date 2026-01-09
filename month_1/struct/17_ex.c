#include <stdio.h>
#include <string.h>

// 1. 구조체 (Structure)
struct student {
    int num;         // 학번
    char name[30];   // 이름
    double grade;    // 학점
};

// 2. 공용체 (Union)
union data {
    int num;
    float f;
    char str[20];
};

// 3. 열거형 (Enumeration)
enum week {
    SUN = 1,  // 일요일
    MON = 2,  // 월요일
    TUE = 3,  // 화요일
    WED = 4,  // 수요일
    THU = 5,  // 목요일
    FRI = 6,  // 금요일
    SAT = 7   // 토요일
};

int main(void)
{
    // 1. 구조체 사용 예시
    struct student s1 = {215, "홍길동", 4.2};
    printf("=== 구조체 (student) ===\n");
    printf("학번 : %d\n", s1.num);
    printf("이름 : %s\n", s1.name);
    printf("학점 : %.1lf\n\n", s1.grade);

    // 2. 공용체 사용 예시
    union data d1;
    d1.num = 10;
    printf("=== 공용체 (data) ===\n");
    printf("num: %d\n", d1.num);
    
    // 공용체는 덮어쓰므로 str 값은 덮어써짐
    strcpy(d1.str, "Hello");
    printf("str: %s\n", d1.str);
    
    // 공용체에서 마지막 저장된 값만 유효
    d1.f = 3.14;
    printf("f: %.2f\n\n", d1.f);
    
    // num 값은 덮어쓰여지므로 예측 불가능
    printf("num: %d\n\n", d1.num);

    // 3. 열거형 사용 예시
    enum week today = WED;
    printf("=== 열거형 (week) ===\n");
    printf("오늘은 %d일입니다.\n", today);  // WED는 4일
    printf("오늘은 수요일입니다.\n");

    return 0;
}
