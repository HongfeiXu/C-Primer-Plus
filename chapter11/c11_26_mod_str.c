/* mod_str.c -- 修改一个字符串 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>				// to use toupper () and ispunct ()
#define LIMIT 80
void ToUpper (char *);			// 将字符串转换为大写
int PunctCount (const char *);	// 计算一个字符串中标点个数

int main (void)
{
	char line[LIMIT];

	puts ("Please enter a line: ");
	gets (line);
	ToUpper (line);
	puts (line);
	printf ("The line has %d punctuation characters.\n",
		PunctCount (line));

	return 0;
}

void ToUpper (char * str)
{
	while (*str)
	{
		*str = toupper (*str);
		str++;
	}
}

int PunctCount (const char * str)
{
	int ct = 0;

	while (*str)		
	{
		if (ispunct (*str))
			ct++;
		str++;
	}

	return ct;
}