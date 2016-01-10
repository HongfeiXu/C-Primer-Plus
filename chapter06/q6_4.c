#include <stdio.h>
int main (void)
{
    char user_ch;           // 存储用户输入字符
    int i, j, k, l;            
    int nlines;             // 记录要打印的行数

    printf ("Please enter a letter in captial: ");          // 未实现输入检错
    scanf ("%c", &user_ch);

    nlines = user_ch - 'A' + 1;
    for (i = 0; i < nlines; i++)
    {
        for (j = nlines - i - 1; j > 0; j--)    // 每行打印 nlines - i -1 个空格
            printf (" ");
        for (k = 0; k <= i; k++)                // 顺序打印 i+1 个字母
            printf ("%c", 'A' + k);
        for (l = i - 1; l >= 0; l--)            // 逆序打印 i 个字母
            printf ("%c", 'A' + l);
        printf ("\n");
    }


    return 0;
}
