#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

int main(void)
{
    double r, W;
    double epsL_pct, epsR_pct;
    double L;

    // 입력
    printf("바퀴 반지름 r(m): ");
    if (scanf("%lf", &r) != 1) return 1;

    printf("트랙폭 W(m): ");
    if (scanf("%lf", &W) != 1) return 1;

    printf("좌측 바퀴 오차율 εL(%%): ");
    if (scanf("%lf", &epsL_pct) != 1) return 1;

    printf("우측 바퀴 오차율 εR(%%): ");
    if (scanf("%lf", &epsR_pct) != 1) return 1;

    printf("주행 거리 L(m): ");
    if (scanf("%lf", &L) != 1) return 1;

    // 퍼센트 → 비율
    double epsL = epsL_pct / 100.0;
    double epsR = epsR_pct / 100.0;

    // 좌/우 바퀴 반경
    double rL = r * (1.0 + epsL);
    double rR = r * (1.0 + epsR);

    // 곡률반경 (슬라이드 핵심 식)
    double Rc = (W / 2.0) * (rL + rR) / (rR - rL);

    // 편류각
    double delta_rad = L / Rc;
    double delta_deg = delta_rad * 180.0 / PI;

    // 편류거리
    double drift = Rc * (1.0 - cos(delta_rad));

    // 출력
    printf("\n[결과]\n");
    printf("좌/우 바퀴 반경 : %.4f m / %.4f m\n", rL, rR);
    printf("곡률 반경 Rc = %.2f m\n", Rc);
    printf("편류각 δ = %.2f deg\n", delta_deg);
    printf("편류거리 d_drift = %.2f m\n", drift);

    return 0;
}