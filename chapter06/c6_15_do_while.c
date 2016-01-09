/* do_while.c -- 推出条件循环 */
#include <stdio.h>
int main (void)
{
    const int secret_code = 13;
    int code_entered;

    do
    {
        printf ("To enter the triskaidekaphobia therapy club, \n");
        printf ("please enter the secret code number: ");
        if (scanf ("%d", &code_entered ) != 1)      // 若输入的不是数字，终止程序，返回 -1
        {
            printf ("Sorry your input is not a number.\nBye!\n");
            return -1;
        }
    }while (code_entered != secret_code);
    printf ("Congratulations! You are cured!\n");

    return 0;
}
