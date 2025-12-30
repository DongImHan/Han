#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

/* 값 범위 제한 함수 */
double clip(double x, double min, double max)
{
    if (x < min) return min;
    if (x > max) return max;
    return x;
}

int main(void)
{
    double m;    // 총 질량 [kg]
    double Tm;   // 모터 정격 토크 [N·m]
    double Nm;   // 구동 모터 수
    double G;    // 감속비
    double eta;  // 구동 효율 (0~1)
    double r;    // 바퀴 반지름 [m]
    double c;    // 구름계수
    double SF;   // 안전계수 (>=1)

    double Tt;       // 총 구동 토크
    double Fa;       // 가용 견인력
    double sin0;     // sin(theta)
    double grade;    // 등판율 (%)

    const double g = 9.81;

    /* 입력 */
    printf("총 질량 m (kg) : ");
    scanf("%lf", &m);

    printf("모터 정격토크 Tm (N·m) : ");
    scanf("%lf", &Tm);

    printf("구동 모터 수 Nm : ");
    scanf("%lf", &Nm);

    printf("감속비 G : ");
    scanf("%lf", &G);

    printf("구동효율 eta (0~1) : ");
    scanf("%lf", &eta);

    printf("바퀴 반지름 r (m) : ");
    scanf("%lf", &r);

    printf("구름계수 c : ");
    scanf("%lf", &c);

    printf("안전계수 SF : ");
    scanf("%lf", &SF);

    /* ===== 계산 ===== */

    // 총 구동 토크
    Tt = Nm * Tm * G * eta;

    // 가용 견인력
    Fa = Tt / r;

    // sin(theta) 계산 (안전계수, 구름저항 포함)
    sin0 = (Fa / SF - c * m * g) / (m * g);
    sin0 = clip(sin0, 0.0, 1.0);

    // 각도 계산
    double theta_rad = asin(sin0);
    double theta_deg = theta_rad * 180.0 / PI;

    // 등판율 계산 (%)
    grade = tan(theta_rad) * 100.0;

    /* ===== 출력 ===== */
    printf("\n[결과]\n");
    printf("총 가용 견인력 : %.2f N\n", Fa);
    printf("안전계수 적용 최대 등판각 : %.2f deg\n", theta_deg);
    printf("등판율 : %.1f %%\n", grade);

    return 0;
}