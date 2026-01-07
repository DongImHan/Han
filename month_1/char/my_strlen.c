#include <stdio.h>

int my_strlen(const char *str);

int main(void)
{
    char dest[50] = "Hello ";
    char src[] = "World!";

    int len = my_strlen(dest);
    printf("length: %d\n", len);

    return 0;
}

int my_strlen(const char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }

    return i;
}
