/* printf ()的更多属性 */
#include <stdio.h>
int main (void)
{
    unsigned int un = 3000000000;
    short end = 200;
    long big = 65537; long long verybig = 12345678908642;
    printf ("un = %u and not %d\n", un, un);
    printf ("end = %hd and %d\n", end, end);
    printf ("big = %ld and not %hd\n", big, big);
    printf ("verybig = %lld and not %ld\n", verybig, verybig);      // 我电脑上 long 和 long long 同为 64 位，故未发生溢出
    
    return 0;
}
