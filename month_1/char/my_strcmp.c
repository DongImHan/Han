#include <stdio.h>

int my_strcmp(const char *s1, const char *s2);

int main(void)
{
    printf("%d\n", my_strcmp("apple", "apple"));   // 0
    printf("%d\n", my_strcmp("apple", "banana")); // -1
    printf("%d\n", my_strcmp("zoo", "ant"));      // 1

    return 0;
}

int my_strcmp(const char *s1, const char *s2)
{
    int i = 0;

    while (s1[i] != '\0' || s2[i] != '\0')
    {
        if (s1[i] > s2[i]) {
            return 1;     // s1이 더 큼
        }
        else if (s1[i] < s2[i]) {
            return -1;    // s1이 더 작음
        }
        i++;
    }

    return 0;   // 완전히 같음
}