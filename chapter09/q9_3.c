#include <stdio.h>
void print_stuff (char ch, int times, int lines);

int main (void)
{
    print_stuff ('*', 3, 4);

    return 0;
}

void print_stuff (char ch, int times, int lines)
{
    int i, j;

    for (i = 0; i < lines; i++)
    {
        for (j = 0; j < times; j++)
        {
            putchar (ch);
        }
        putchar ('\n');
    }
}
