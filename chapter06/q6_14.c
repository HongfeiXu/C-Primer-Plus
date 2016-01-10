#include <stdio.h>
int main (void)
{
    char line[100];
    int length;             // 记录数组实际长度，不包括'\n'
    int i;

    printf ("Please enter your line:\n") ;
    for (i = 0; scanf ("%c", &line[i]), line[i] != '\n'; i++);
    length = i;

    printf ("The line you just typed is:\n");
    for (i = 0; i < length; i++)  
        printf ("%c", line[i]);
    printf ("\n");

    printf ("The reverse of the line is:\n");
    for (i = length - 1; i >= 0; i--)  // 注意i != lenght 这是由于数组下标由0开始所致 
    {
        printf ("%c", line[i]);
    }
    printf ("\n");

    return 0;
}
