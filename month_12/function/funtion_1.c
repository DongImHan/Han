#include <stdio.h>

int avg(int x, int y);

int main(void)
{
    int a , b;
    int result;

    printf("두 수를 입력하십시오 : ");
    scanf("%d %d", &a, &b);
    result = avg(a, b);
    printf("result : %d\n", result);

    return 0;
}

int avg(int x, int y)
{
    int temp;

    temp = (x + y)/2;

    return temp;
}