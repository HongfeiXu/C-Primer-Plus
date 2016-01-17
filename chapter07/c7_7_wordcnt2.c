// wordcnt.c -- 统计字符、单词和行
#include <stdio.h>
#include <stdbool.h>        // 为 isspace () 提供函数原型
#include <ctype.h>          // 为 bool、true 和 false 提供定义
int main (void)
{
    int c;
    char prev;
    long n_chars = 0L;
    int n_lines = 0;
    int n_words = 0;
    int p_lines = 0;
    bool inword = false;

    prev = '\n';                        // 用于识别完整的行
    printf ("Enter text to be analyzed (| to terminate): \n");
    while ((c = getchar ()) != EOF)
    {
        n_chars++;
        if (c == '\n')
            n_lines++;
        if (!isspace (c) && !inword)        
        {
            inword = true;              // 开始一个新单词
            n_words++;
        }
        if (isspace (c) && inword)
            inword = false;             // 到达单词的尾部
        prev = c;

    }
    if (prev != '\n')                   // 文件结尾出现之前所读入的最后一个字符不是换行符，计为不完整的行
        p_lines = 1;
    printf ("characters = %ld, words = %d, lines = %d, ", 
            n_chars, n_words, n_lines);
    printf ("partial lines = %d\n", p_lines);

    return 0;
}
