#include <stdio.h>

int main(void)
{
    int floor;

    printf("몇 층을 쌓겠느냐? ");
    scanf("%d", &floor);

    for (int i = 0; i < floor; i++)
    {
        for (int j = i; j < floor; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < i; k++)
        {
            printf("*");
        }
        printf("\n");        
    }
    return 0;
}