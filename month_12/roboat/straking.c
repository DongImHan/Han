#include <stdio.h>

#define MAX_SIZE 100

int main(void)
{
    int N;
    double speed[MAX_SIZE];
    double delta;

    int acc_count = 0;
    int dec_count = 0; 

    // 데이터 개수 입력
    printf("데이터 개수 N을 입력하세요 (최대 %d): ", MAX_SIZE);
    scanf("%d", &N);  // N 값 입력받기

    if (N > MAX_SIZE) {
        printf("최대 %d개까지만 입력 가능합니다.\n", MAX_SIZE);
        return 1;  // N이 MAX_SIZE보다 크면 프로그램 종료
    }
    
    // 속도 데이터 입력
    printf("%d개의 속도 데이터를 순서대로 입력하세요 : \n", N);
    for (int i = 0; i < N; i++) {
        scanf("%lf", &speed[i]);  // 배열에 속도 데이터 입력
    }
    
    // 급가속, 급제동 분석
    for (int i = 1; i < N; i++) {  // i는 1부터 시작, 이전 속도와 비교
        delta = speed[i] - speed[i-1];  // delta 계산

        if (delta >= 10.0) {
            acc_count++;
        } else if (delta <= -10.0) {
            dec_count++;
        }
    }

    // 분석 결과 출력
    printf("\n[분석결과]\n");
    printf("급가속 횟수 : %d\n", acc_count);
    printf("급제동 횟수 : %d\n", dec_count);
    
    return 0;
}