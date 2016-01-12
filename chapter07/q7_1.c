#include <stdio.h>
int main (void)
{
    char ch;
    int blank_cnt, line_feed_cnt, oth_cnt; // 空格， 换行， 其它 字符的数目
    blank_cnt = line_feed_cnt = oth_cnt = 0;

    while ((ch = getchar ()) != '#')
    {
        if (ch == '\n')        
            line_feed_cnt++;
        else if (ch == ' ')
            blank_cnt++;
        else
            oth_cnt++;
    }
    printf ("There are %d %s , %d line feed, %d other symbols.\n",
            blank_cnt, blank_cnt > 1 ? "blanks" : "blank", line_feed_cnt, oth_cnt);

    return 0;
}
