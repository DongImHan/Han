#include <stdio.h>

char *my_strcat(char *dest, char *src);

int main(void)
{
    char dest[50] = "Hello ";
    char src[] = "World!";

    my_strcat(dest, src);

    printf("%s\n", dest);

    return 0;
}

char *my_strcat(char *dest, char *src)
{
    int i = 0;
    int j = 0;

    while (dest[i] != '\0')
    {
        i++;
    }

    while (src[j] != '\0')
    {
        dest[i + j] = src[j];
        j++;
    }

    dest[i + j] = '\0';

    return dest;
}