/* 输入名字和姓名， 然后以“名字，姓氏”打印 */
#include <stdio.h>
int main (void)
{
    char f_name[15];    // 名字
    char l_name[15];    // 姓氏

    printf ("Please enter your name: \n");
    scanf ("%s %s", f_name, l_name);
    printf ("Your name is:\n");
    printf ("%s, %s\n", f_name, l_name);

    return 0;
}
