#include <stdio.h>
#include <string.h>
int main (void)
{
    char word[20];
    int length; //字符串长度
    int i;      
    
    printf ("Please enter a word: ");
    scanf ("%s", word);
    printf ("Your word is: %s\n", word);
    length = strlen(word);
    printf ("Reverse of your word: ");
    for (i = length - 1; i >= 0; i--)
    {
        printf ("%c", word[i]);
    }
    printf ("\n");

    return 0;
}
