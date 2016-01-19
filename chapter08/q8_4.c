/*
 *  需要统计字母总数
 *  需要统计单词总数
 *
 * */

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main (void)
{
    int ch;
    int cnt_letter, cnt_word;
    bool in_word;

    cnt_letter = cnt_word = 0;
    in_word = false;

    while ((ch = getchar ()) != EOF)
    {
        if (isalpha (ch))       // 新单词
        {
            cnt_letter++;
            if (!in_word)
            {
                cnt_word++;
                in_word = true;
            }
        }
        if (!isalpha (ch) && in_word)
        {
            in_word = false;
        }
    }
    printf ("There are %d letters and %d words.\n", cnt_letter, cnt_word);
    printf ("Each word has %f letters.\n", (float) cnt_letter / (float) cnt_word);

    return 0;
}
