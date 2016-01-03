#include <stdio.h>
int main (void)
{
    float f;

    printf ("Please enter a float number:_____\b\b\b\b\b");
    scanf ("%f", &f);
    printf ("The input is %f or %e\n", f, f);

    return 0;
}


/*
 *WHY THIS HAPPENS,不是说好float至少保留6位有效数字吗？？为何最后出来了个1?
 *
 [alex@EX chapter03]$ ./a.out 
 Please enter a float number:21.29
 The input is 21.290001 or 2.129000e+01         

 *
 *
 *
 *
 * */
