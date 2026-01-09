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

    move(&robot, +5, +3);
    move(&robot, -2, +4);

    printf("로봇 최종 위치 : (%d, %d)\n", robot.x, robot.y);

    return 0;
}