#include <stdio.h>

void print_month(int month[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", month[i]);

        if ((i + 1) % 5 == 0)
        {
            printf("\n");
        }
        
    }
    
}

int main(void)
{
    int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    print_month(month, 12);

    return 0;
}