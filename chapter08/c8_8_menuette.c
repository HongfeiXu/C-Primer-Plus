/* menuette.c */
#include <stdio.h>
char get_choice (void); // 从用户读取选择，a,b,c,q 如不是其中之一，则提示用户重新输入。
char get_first (void);  // 获取get_first遇到输入行的第一个字符，并跳过本行的剩余部分。
int get_int (void);     // 读取一个整型值。若不合法，则提示重新输入。
void count (void);      // just count, 小心处理最后的换行符。

int main (void)
{
    int choice;
    
    while ((choice = get_choice ()) != 'q')
    {
        switch (choice)
        {
            case 'a': printf ("Buy low, sell high.\n");
                      break;
            case 'b': putchar ('\a');
                      break;
            case 'c': count ();
                      break;
            default: printf ("Program error!\n");
        }
    }
    printf ("Bye.\n");

    return 0;
}


char get_choice (void)
{
    int ch;
    
    printf ("Enter the letter of your choice: \n");
    printf ("a. advice              b. bell\n");
    printf ("c. count               q. quit\n");
    ch = get_first ();
    while ((ch < 'a' || ch > 'c') && ch != 'q')
    {
        printf ("Please respond with a, b, c, or q.\n");
        ch = get_first ();
    }
    return ch;
}

char get_first (void)      
{
    int ch;

    ch = getchar ();
    while (getchar () != '\n')
        continue;

    return ch;
}

int get_int (void)
{
    int input;
    char ch;

    while (scanf ("%d", &input) != 1)
    {
        while ((ch = getchar ()) != '\n')
            putchar (ch);
        printf (" is not an integer.\nPlease enter an ");
        printf ("integer value, such as 25, -178, or 3: ");
    }
    return input;
}

void count (void)
{
    int n, i;

    printf ("Count how far? Enter an integer: ");
    n = get_int ();
    for (i = 1; i <= n; i++)
        printf ("%d\n", i);
    while (getchar () != '\n')
        continue;               // 负责处理换行符，防止换行符留在输入流中影响其他函数(getchar)的输入
}
