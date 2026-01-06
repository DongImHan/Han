#include <stdio.h>
#include <math.h>

#define MAX_SIZE 100
#define g 9.81  // 중력 가속도 (m/s^2)
#define M_PI 3.14159265358979323846

int main(void) {
    // 물리적 변수들
    double m, Tm, G, eta, r, c, SF;
    int Nm;

    // 요구 사항 출력
    printf("1. 총 가용 견인력 Fa를 계산하라.\n");
    printf("2. 안전계수 적용 시 등판 가능 최대각 Om[deg]과 등판률[grade %%]를 구하라.\n");
    printf("3. (선택) 마찰한계는 무시한다는 가정으로 계산하라.\n");

    // 입력 받기
    printf("총 질량[kg] : ");
    if (scanf("%lf", &m) != 1 || m <= 0) return 1;

    printf("모터 정격토크[N|m] : ");
    if (scanf("%lf", &Tm) != 1 || Tm <= 0) return 1;

    printf("구동 모터 수[개] : ");
    if (scanf("%d", &Nm) != 1 || Nm <= 0) return 1;

    printf("감속비 : ");
    if (scanf("%lf", &G) != 1 || G <= 0) return 1;

    printf("구동 효율 (1~0) : ");
    if (scanf("%lf", &eta) != 1 || eta <= 0 || eta > 1) return 1;

    printf("바퀴 반지름[m] : ");
    if (scanf("%lf", &r) != 1 || r <= 0) return 1;

    printf("구름 계수[0~1] : ");
    if (scanf("%lf", &c) != 1 || c < 0) return 1;

    printf("안전계수 (1 <= ) : ");
    if (scanf("%lf", &SF) != 1 || SF < 1) return 1;

    // 수식 계산
    double Tt = Nm * Tm * G * eta;  // 총 구동 토크
    double Fa = Tt / r;              // 가용 견인력
    double mg = m * g;               // 중량

    // 등판 가능 각도 계산
    double sin_theta = (Fa / SF - c * mg) / mg;
    if (sin_theta < 0) sin_theta = 0;
    if (sin_theta > 1) sin_theta = 1;
    double theta_rad = asin(sin_theta);
    double theta_deg = theta_rad * 180.0 / M_PI;

    // 등판율 계산
    double grade = tan(theta_rad) * 100.0;

    // 결과 출력
    printf("\n[결과]\n");
    printf("총 구동 토크 T_tot   : %.2f N·m\n", Tt);
    printf("가용 견인력 F_avail  : %.2f N\n", Fa);
    printf("등판 가능 최대각 : %.2f deg\n", theta_deg);
    printf("등판율(grade)        : %.1f %%\n", grade);

    return 0;
}