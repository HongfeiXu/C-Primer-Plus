/* count.c -- 使用标准 I/O */
#include <stdio.h>
#include <stdlib.h> // ANSI C 的exit () 原型
#define SIZE 20

int main (void)
{
    int ch;     // 读取时存储每个字符的位置
    FILE *fp;   // 文件指针
    char name[SIZE];
    long count = 0;

    printf ("Enter the filename: \n");
    gets (name);
    if ((fp = fopen (name, "r")) == NULL)
    {
    	printf ("Can't open %s\n", name);
    	exit (1);
    }
    while ((ch = getc (fp)) != EOF)
    {
    	putc (ch, stdout);	// 相当于 putchar (ch)
        count ++;
    }
    if(fclose (fp) != 0)
    	printf ("Error in closing file %s\n", name);
    printf ("File %s has %ld characters\n", name, count);

    return 0;
}
