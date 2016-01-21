#include <stdio.h>
#include <ctype.h>

int letter_pos (char ch);

int main (void)
{
    char ch;
    int pos;

    while ((ch = getchar ()) != EOF)
    {
        pos = letter_pos (ch);
        if (pos == -1)
            printf ("%c is not a letter.\n", ch);
        else
            printf ("%c is the %dth letter.\n", ch, pos);
    }

    return 0;
}


int letter_pos (char ch)
{
    if (isalpha (ch))
        return (islower (ch) - 'a' + 1);
    else 
        return -1;
}


