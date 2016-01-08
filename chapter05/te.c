#include <stdio.h>
int main (void)
{
    int count;
    count = printf ("hello");
    printf ("\ncount = %d\n", count);

    printf ("sizeof (long int) = %zd\n", sizeof (long int));
    printf ("sizeof (int) = %zd\n", sizeof (int));

    return 0;
}
