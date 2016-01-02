#include <stdio.h>
void say1 (void);
void say2 (void);
int main (void)
{   
    say1();
    say2();

    return 0;
}

void say1 (void)
{
    printf ("For he's a jolly good fellow!\n");
    printf ("For he's a jolly good fellow!\n");
    printf ("For he's a jolly good fellow!\n");
}

void say2 (void)
{
    printf ("Which nobody can deny!\n");
}

