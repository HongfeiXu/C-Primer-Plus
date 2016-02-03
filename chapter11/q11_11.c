/*  编写一个程序。功能是读取输入，直到遇到EOF，并报告单词数、大写字母数、
 *  小写字母数、标点符号数和数字字符数。使用ctype.h系列函数
 * */
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
int main (void)
{
	char ch;
	bool inword;
	int word_cnt, upper_cnt, lower_cnt, punct_cnt, digit_cnt;
	inword = false;
	word_cnt = upper_cnt= lower_cnt = punct_cnt = digit_cnt = 0;

	while ((ch = getchar ()) != EOF)
	{
		// word count
		if (!isspace (ch) && !inword)
		{
			inword = true;				// 开始一个新单词
			word_cnt++;
		}
		if (isspace (ch) && inword)
		{
			inword = false;				// 到达单词的尾部
		}

		if (isupper (ch))
			upper_cnt++;
		else if (islower (ch))
			lower_cnt++;
		else if (ispunct (ch))
			punct_cnt++;
		else if (isdigit (ch))
			digit_cnt++;
	}
	printf ("There are %d words, %d upper characters, %d lower characters, %d punctions and %d digits.\n",
		word_cnt, upper_cnt, lower_cnt, punct_cnt, digit_cnt);

	return 0;
}

