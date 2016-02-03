/* mystrlen.c */
#include <stdio.h>
int mystrlen (const char *str);

int main (void)
{
	char str[] = "Hello, World!";

	printf ("The string \"%s\" has %d characters.\n",
		str, mystrlen (str));

	return 0;
}

int mystrlen (const char *str)
{
	int cnt = 0;

	while (*str++)
	{
		cnt++;
	}

	return cnt;
}