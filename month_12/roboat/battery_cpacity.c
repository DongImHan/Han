#include <stdio.h>

int main(void)
{
    double l_load; //평균 전류[A]
    double vel; //평균 속력[km/h]
    double r; //예비율[0~1]
    double v; //공칭전압[A]
    double cap; //용량[Ah]
    double eta; //시스템 효율[0~1]
    double eusable; //사용 가능 에너지[Wh]
    double p; //소비전력[W]
    double t; //런타임[h]
    double d; //주행거리[km]

    printf("평균 전류 : ");
    scanf("%lf", &l_load);
    printf("평균 속력 : ");
    scanf("%lf", &vel);
    printf("예비율 : ");
    scanf("%lf", &r);
    printf("공칭전압 : ");
    scanf("%lf", &v);
    printf("용량 : ");
    scanf("%lf", &cap);
    printf("시스템 효율 : ");
    scanf("%lf", &eta);

    eusable = v*cap*eta*(1-r);//사용 가능 에너지 계산식
    p = (v*l_load)/eta;//소비전력 계산식
    t = eusable/p;//런타임 계산식
    d = vel*t;//주행거리 계산식

    printf("소비전력 : %lf(W)\n", p);
    printf("런타임 : %lf(h)\n", t);
    printf("주행거리 : %lf(km)", d);

    return 0;
}