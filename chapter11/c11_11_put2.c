/* put2.c -- 打印一个字符串，并统计其字符的个数 */
#include <stdio.h>
int put2 (const char *string);

int main (void)
{
	int count;

	count = put2 ("pizza");
	printf ("There are %d characters in this string.\n", count);

	return 0;
}

int put2 (const char * string)
{
	int count = 0;

	while (*string)
	{
		count++;
		putchar (*string++);
	}
	printf ("\n");	 // 换行符不统计在内

	return count;
}