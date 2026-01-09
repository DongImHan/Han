#include <stdio.h>

typedef struct {
    int x;
    int y;
} Position;

void move(Position *p, int dx, int dy) {
    p -> x += dx;
    p -> y += dy;
}

int main(void) {
    Position robot = {0, 0};
    int n;
    int dx, dy;

    printf("이동할 횟수를 입력 : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("%d번째 이동 (dx, dy) : ", i + 1);
        scanf("%d %d", &dx, &dy);
        move(&robot, dx, dy);
    }
    printf("로봇 위치 : (%d, %d)", robot.x, robot.y);

    return 0;
}


/*
int main(void) {
    Position robot = {0, 0};

    move(&robot, +5, +3);
    move(&robot, -2, +4);

    printf("로봇 최종 위치 : (%d, %d)\n", robot.x, robot.y);

    return 0;
}
*/