// put_put.c -- 用户自定义的输出函数
#include <stdio.h>
void put1 (const char * string);
int put2 (const char * string);

int main (void)
{
	put1 ("If I'd as much money");
	put1 (" as I could spend.\n ");
	printf ("I count %d characters.\n",
		put2 ("I never would cry old chairs to mend. "));

	return 0;
}

void put1 (const char *string)
{
	while (*string)
		putchar (*string++);
}

int put2 (const char *string)
{
	int count = 0;
	while (*string)
	{
		count++;
		putchar (*string++);
	}
	putchar ('\n');
}

/*

[alex@EX chapter11]$ ./a.out 
If I'd as much money as I could spend.
 I never would cry old chairs to mend. 
I count 10 characters.

*/