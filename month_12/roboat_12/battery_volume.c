#include <stdio.h>

int main(void)
{
    // 사전 선정 정보
    double l_load; // 평균전류[A]
    double vel; // 평균속도[km/h]
    double R; // 예비율[0~1]

    // 배터리 정보
    double V; // 공칭전압
    double C; // 용량
    double eta; // 시스템 효율
    
    printf("[사전 선정 정보 입력] : \n");
    printf("평균전류[A] : ");
    if (scanf("%lf", &l_load) != 1) return 1;
    printf("평균속도[km/h] : ");
    if (scanf("%lf", &vel) != 1) return 1;
    printf("예비율[0~1] : ");
    if (scanf("%lf", &R) != 1) return 1;


    printf("[배터리 정보 입력] : \n");
    printf("공칭전압[V] : ");
    if (scanf("%lf", &V) != 1) return 1;
    printf("용량[Ah] : ");
    if (scanf("%lf", &C) != 1) return 1;
    printf("시스템 효율[0~1] : ");
    if (scanf("%lf", &eta) != 1) return 1;

    // 계산 조건
    double E_usable = V * C * eta * (1 - R); // 사용 가능 에너지()
    double P = V * l_load / (eta); // 소비전련()
    double t = E_usable / P; // 런타임()
    double d = vel * t; // 주행거리()

    printf("[사용 가능 에너지] : ");
    printf("%.2lf[Wh]\n", E_usable);
    printf("[런타임] : ");
    printf("%.2lf[h]\n", t);
    printf("[주행거리] : ");
    printf("%.2lf[km]\n", d);

    return 0;
}