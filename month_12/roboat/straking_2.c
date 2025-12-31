#include <stdio.h>

#define MAX_SIZE 100
#define MIN_KEEP 10

int main(void)
{
    int N;
    double speed[MAX_SIZE];

    int ans1 = 0, ans2 = 0, ans3 = 0;

    printf("데이터 개수 N 입력: ");
    scanf("%d", &N);

    if (N < 2 || N > MAX_SIZE) {
        printf("N 범위 오류\n");
        return 1;
    }

    /* 속도 데이터 입력 */
    for (int i = 0; i < N; i++) {
        scanf("%lf", &speed[i]);
    }

    /* ① 첫 번째 조건 판단 */
    if (speed[0] >= 0 && speed[0] <= 10)
        ans1 = 1;

    /* ② 두 번째 조건 판단 */
    if (speed[1] >= 0 && speed[1] <= 100)
        ans2 = 1;

    /* ③ 증감 유지 판단 */
    int direction;
    int keep_count = 1;

    if (speed[1] >= speed[0])
        direction = 1;
    else
        direction = -1;

    for (int i = 2; i < N; i++) {
        double diff = speed[i] - speed[i - 1];

        if ((diff > 0 && direction == 1) ||
            (diff < 0 && direction == -1)) {
            keep_count++;
        } else {
            break;  // 방향이 바뀌면 중단
        }

        if (keep_count >= MIN_KEEP) {
            ans3 = 1;
            break;
        }
    }

    /* 결과 출력 */
    printf("\n[조건 판단 결과]\n");
    printf("조건 1 (0~10): %s\n", ans1 ? "만족" : "불만족");
    printf("조건 2 (0~100): %s\n", ans2 ? "만족" : "불만족");
    printf("조건 3 (증감 10회 유지): %s\n", ans3 ? "만족" : "불만족");

    return 0;
}