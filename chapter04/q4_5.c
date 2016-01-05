#include <stdio.h>
#include <string.h>
int main (void)
{
    char f_name[20], l_name[20];        // 名，姓
    int f_len, l_len;                   // 名字长度，姓氏长度
    
    printf ("Please your first name: \n");
    scanf ("%s", f_name);
    printf ("Please your last name: \n");
    scanf ("%s", l_name);
 
    f_len = strlen(f_name);
    l_len = strlen(l_name);
    
    printf ("%s %s\n", f_name, l_name);
    printf ("%*d %*d\n", f_len, f_len, l_len, l_len);
    printf ("%s %s\n", f_name, l_name);
    printf ("%-*d %-*d\n", f_len, f_len, l_len, l_len);

    return 0;
}
