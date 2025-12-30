#include <stdio.h>
#include <math.h>

#define PI 3.1415926535  // PI 값 정의

// deg -> rad 변환 함수
float deg_rad(float x) {
    float result = x * (PI / 180.0);  // deg -> rad 변환
    return result;
}

// rad -> deg 변환 함수
float rad_deg(float y) {
    float result = y * (180.0 / PI);  // rad -> deg 변환
    return result;
}

int main(void)
{
    int a;
    float b;

    // 모드 선택
    printf("모드를 선택해주세요: 1.deg -> rad / 2.rad -> deg : ");
    scanf("%d", &a);  // 사용자 입력

    // 변환할 값 입력
    printf("변환할 값을 입력 : ");
    scanf("%f", &b);  // 값 입력

    if (a == 1)
    {
        // deg -> rad 변환
        float x = deg_rad(b);
        printf("%.2f deg는 %.4f rad입니다.\n", b, x);  // 출력 시 소수점 자리수 조정
    }
    else if (a == 2)
    {
        // rad -> deg 변환
        float x = rad_deg(b);
        printf("%.2f rad는 %.4f deg입니다.\n", b, x);  // 출력 시 소수점 자리수 조정
    }
    else
    {
        printf("잘못된 선택입니다.\n");  // 잘못된 입력 처리
    }

    return 0;
}