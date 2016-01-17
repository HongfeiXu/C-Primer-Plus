// file_eof.c -- 打开一个文件并显示其内容
#include <stdio.h>
#include <stdlib.h>     // 为了使用 exit ()
int main (void)
{
    int ch;
    FILE *fp;
    char fname[50];     // 用于存放文件名

    printf ("Enter the name of the file: \n");
    scanf ("%s", fname);
    fp = fopen(fname, "r");     // 打开文件以供读取
    if (fp == NULL)
    {
        printf ("Failed to open file. Bye\n");
        exit (1);
    }

    // getc (fp) 从打开的文件中获取一个字符
    while ((ch = getc (fp)) != EOF)
        putchar (ch);
    fclose (fp);        // 关闭文件

    return 0;
}
