#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
int main (void)
{
    char ch;
    char prev;
    int n_chars = 0;
    int n_words = 0;
    int n_lines = 0;
    int p_lines = 0;
    bool inword = false;   

    prev = '\n';
    while ((ch = getchar ()) != '|')
    {
        n_chars++;
        if (ch == '\n')
            n_lines++;
        if (!isspace (ch) && !inword)
        {
            inword = true;
            n_words++;
        }
        if (isspace (ch) && inword)
            inword = false;
        prev = ch;
    }
    if (prev != '\n')
        p_lines = 1;
    printf ("n_chars = %d, n_words = %d, n_lines = %d", n_chars, n_words, n_lines);
    printf ("p_lines = %d", p_lines);
    

    return 0;
}
