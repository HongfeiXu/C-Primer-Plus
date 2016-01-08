#include <stdio.h>
int main (void)
{
    int count = 0, sum = 0, fina;        
    
    printf ("Enter a positive integer number: ");
    scanf ("%d", &fina);
        
    while (count++ < fina)  
        sum = sum + count * count;
    printf ("sum = %d\n", sum);

    return 0;
}
