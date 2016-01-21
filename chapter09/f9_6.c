#include <stdio.h>
void alter (int * x, int *y);

int main (void)
{
    int a, b;
    a = 1, b = 2;
    printf ("a = %d\nb=%d\n", a, b);
    alter (&a, &b);
    printf ("a = %d\nb=%d\n", a, b);
    
    return 0;
}

void alter (int * x, int * y)
{
    *x = *x + *y;
    *y = *x - 2 * (*y);
}
