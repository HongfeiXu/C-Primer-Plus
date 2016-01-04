/* 打印较长的字符串 */
#include <stdio.h>
int main (void)
{
    printf ("Here is one way to print a ");
    printf ("long string.\n");
    printf ("Here's another way to print a \        //用'\'来结束这一行，下一行必须从最左边开始
long string.\n");
    printf ("Here's the newest way to print a "
            "long string.\n");  /* ANSCI C*/

    return 0;
}
