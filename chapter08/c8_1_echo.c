/* echo.c -- echoing the input */
#include <stdio.h>
int main (void)
{
    char ch;
    
    while ((ch = getchar ()) != '#')
        putchar (ch);
    return 0;
}
