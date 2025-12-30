#include <stdio.h>

int main(void)
{
    int i, j;
    printf("계산할 구구단을 숫자를 입력하십시오 : ");
    scanf("%d", &j);

    for (i = 0; i <= 9; i++)
    {
        printf("%d * %d = %d\n", j, i, j * i);
    }
    
}