#include <stdio.h>

int main(void)
{
    int sensor_N;        // 센서 개수
    int sensor_vol;      // 센서로부터 받을 값 (0 ~ N-1)
    int threshold;       // 임계값
    int black_count = 0; // 검정 센서의 개수
    int sum_index = 0;   // 검정 센서들의 인덱스를 합산
    int index_avg;       // 평균 인덱스 계산

    printf("임계값 설정 : ");
    if (scanf("%d", &threshold) != 1) return 1;

    printf("센서 개수 입력 : ");
    if (scanf("%d", &sensor_N) != 1) return 1;

    printf("센서값 입력 : ");    
    for (int i = 0; i < sensor_N; i++)
    {
        scanf("%d", &sensor_vol);

        // 임계값을 기준으로 검정 센서를 분류
        if (sensor_vol < threshold) {
            // 검정 센서일 경우
            black_count += 1;
            sum_index += i; // 검정 센서의 인덱스를 합산
        }
    }

    // 평균 인덱스를 계산
    if (black_count == 0) {
        printf("라인 없음\n");
    } else {
        index_avg = sum_index / black_count; // 평균 인덱스 계산
        printf("index_avg = %d\n", index_avg); // 결과 출력
    }

    return 0;
}