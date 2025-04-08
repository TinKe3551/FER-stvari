#include <stdio.h>


int main()
{
    char *a = "!123";

    int n = 0;

    for (int i = 1; a[i] != '\0';  i++) {

        n *= 10;

        n += (int)(a[i] - '0');

    }

    printf("%d\n", n);

    return 0;
}