/* echo_eof.c -- 重复输入，直到文件的结尾 
 *
 * 可以通过输入重定向来输入一个文件的内容来代替键盘输入，
 *  echo_eof < words  
 * 也可以通过键盘输入将输出重定向到文件，以文件代替屏幕,
 *  echo_eof > mywords      当然还可以 echo_eof >> mywords 实现在末尾追加数据
 * */
#include <stdio.h>

int main (void)
{
    int ch;

    while ((ch = getchar ()) != EOF)
        putchar (ch);

    return 0;
}
