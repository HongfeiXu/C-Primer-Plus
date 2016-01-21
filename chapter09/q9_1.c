#include <stdio.h>
double min (double n1, double n2);

int main (void)
{
    printf ("%.2lf is the small one between %.2lf and %.2lf.\n", min (12.3, 3.2), 12.3, 3.2);
}

double min (double n1, double n2)
{
    return n1 < n2 ? n1 : n2;
}
