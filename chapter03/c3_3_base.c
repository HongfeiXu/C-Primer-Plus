/* 以十进制、八进制和十六进制形式输出100 */
#include <stdio.h>
int main (void)
{
    int x = 100;    // 十进制
//  int x = 0100;   // 8进制
//  int x = 0x100;  // 16进制
    printf ("dec = %d; octal = %o; hex = %x\n", x, x, x);
    printf ("dec = %d; octal = %#o; hex = %#x\n", x, x, x);

    return 0;
}
