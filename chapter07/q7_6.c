/* 报告输入序列中 ei 出现的次数 
 *
 * 感觉解法不是很好。
 *
 *
 * */
#include <stdio.h>
int main (void)
{
    int cnt_ei = 0;
    char ch;
    char s[100];
    int i;
    
    for (i = 0; (ch = getchar ()) != '#'; i++) 
    {
        s[i] = ch;
    }
    for (i = 0; s[i]; i++)
    {
        if (s[i] == 'e' && s[i+1] == 'i')
            cnt_ei++;
    }
    printf ("cnt_ei = %d\n", cnt_ei);

    return 0;
}
