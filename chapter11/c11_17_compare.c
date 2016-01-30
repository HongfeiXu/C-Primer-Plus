/* compare.c -- 这个程序可以满足要求， 比较两个字符串 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define ANSWER "GRANT"
#define MAX 40
int main (void)
{
	char try[MAX];
	char *ptr = try;

	puts ("Who is buried in GRANT's tomb? ");
	gets (try);
	while (*ptr)		// 转换成大写字母
	{
		*ptr = toupper (*ptr);
		ptr++;
	}
	while (strcmp (try, ANSWER) != 0)
//	while (strcmp (try, ANSWER))
	{
		puts ("No, that's wrong, try again. ");
		gets (try);
		ptr = try;			// ptr 重新指向字符串首
		while (*ptr)		// 转换成大写字母
		{
			*ptr = toupper (*ptr);
			ptr++;
		}

	}
	puts ("That's right! ");

	return 0;
}