#include <stdio.h>

int main(void) {
    double dist[5]; // 거리센서 5개
    int i;
    printf("장애물 거리 입력 (cm 단위, 총 5개)\n");
    
    for (i = 0; i < 5; i++) {  // 5개의 센서 거리 입력
        printf("%d번째 센서 거리(cm): ", i + 1);
        scanf("%lf", &dist[i]);  // 각 센서 거리 입력
    }
    
    printf("\n[장애물 근접 경보 및 동작 결과]\n");
    
    for (i = 0; i < 5; i++) {  // 5개의 센서에 대해 경고 출력
        printf("센서 %d → ", i + 1);
        if (dist[i] <= 10.0) {
            printf(" 긴급정지 (%.1f cm) → 동작: 즉시 정지 후 후진\n", dist[i]);
        }
        else if (dist[i] <= 30.0) {
            printf("️ 경고 (%.1f cm) → 동작: 속도 50%% 감속\n", dist[i]);
        }
        else if (dist[i] <= 50.0) {
            printf(" 주의 (%.1f cm) → 동작: 속도 80%% 감속\n", dist[i]);
        }
        else {
            printf(" 안전 (%.1f cm) → 동작: 정상 주행\n", dist[i]);
        }
    }
    return 0;
}


/*
#include <stdio.h>

int main(void)
{
    int sensor_num;
    int sensor_len;

    printf("센서 수 : ");
    scanf("%d", &sensor_num);
    
    for (int i = 0; i < sensor_num; i++)
    {
        printf("각 센서의 거리 : ");
        scanf("%d", &sensor_len);
        if (sensor_len < 10) printf("긴급정지 / 후진\n");
        else if (10 < sensor_len && sensor_len < 30) printf("경고 / 속도 50%%감속\n");
        else if (30 < sensor_len && sensor_len < 50) printf("주의 / 속도 80%%감속\n");
        else printf("안전 / 정상 주행\n");
    }    

    return 0;
}
*/