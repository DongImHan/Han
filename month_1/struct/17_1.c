#include <stdio.h>

struct studemt
{
    int num;
    double grade;
};

int main(void)
{
    struct studemt s1;

    s1.num = 2;
    s1.grade = 2.7;
    printf("학번 : %d\n", s1.num);
    printf("학점 : %.1lf\n", s1.grade);
}
