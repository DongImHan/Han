#include <stdio.h>

int main(void) {
    double dist[360];  // 라이다 거리 값 배열 (360개)
    int i, min_index = 0;  // min_index는 가장 가까운 장애물의 인덱스
    double min_value;  // 최솟값을 저장할 변수

    // 사용자로부터 라이다 거리값 입력 받기
    printf("360° 라이다 거리값 입력 (테스트용으로 10개만 입력 가능)\n");
    for (i = 0; i < 10; i++) { // 실제는 360개지만 실습용으로 10개만 입력
        printf("%3d° 거리(cm): ", i);  // 각도별로 입력 안내 메시지
        scanf("%lf", &dist[i]);  // 각도에 해당하는 거리 입력
    }

    // 첫 번째 값을 최소 거리로 설정
    min_value = dist[0];

    // 1부터 9까지 배열을 탐색하면서 최소값을 찾음
    for (i = 1; i < 10; i++) {  // 10개만 탐색 (실제는 360개)
        if (dist[i] < min_value) {  // 현재 거리 값이 최소 값보다 작은 경우
            min_value = dist[i];  // 최소 거리 갱신x
            min_index = i;  // 해당 인덱스를 최소 거리의 각도로 저장
        }
    }

    // 최종 결과 출력
    printf("\n[라이다 최소 거리 탐색 결과]\n");
    printf("가장 가까운 거리: %.1f cm\n", min_value);  // 최소 거리 출력
    printf("장애물 방향: %d°\n", min_index);  // 최소 거리의 방향(각도) 출력

    return 0;
}