#include <stdio.h>
#include <string.h>
int main (void)
{
    char f_name[15];                            //名字
    int len;

    scanf ("%s", f_name);
    len = strlen(f_name);
    printf ("\"%s\"\n", f_name);
    printf ("\"%20s\"\n", f_name);
    printf ("\"%-20s\"\n", f_name);
    printf ("\"%*s\"\n", len + 3, f_name);      // 在比名字宽3个字符的字段内打印它

    return 0;
}
