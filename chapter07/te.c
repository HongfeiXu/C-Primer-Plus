#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
int main (void)
{
    int a = 0;

laststep: a++;
    printf ("a = %d\n", a);
    goto laststep;

    return 0;
}
