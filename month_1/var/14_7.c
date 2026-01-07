#include <stdio.h>

int main(void)
{
    int arr[5][6] = {0};
    int i, j, num = 1;

    for (i = 0; i < 4; i++)
        for (j = 0; j < 5; j++)
            arr[i][j] = num++;

    for (i = 0; i < 4; i++)
        for (j = 0; j < 5; j++)
            arr[i][5] += arr[i][j];

    for (j = 0; j < 5; j++)
        for (i = 0; i < 4; i++)
            arr[4][j] += arr[i][j];

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 6; j++)
            printf("%4d", arr[i][j]);
        printf("\n");
    }

    return 0;
}