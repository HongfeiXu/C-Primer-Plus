/* strcnvt.c -- 尝试使用 strtol () 函数 */
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	char number[30];
	char *end;
	long value;

	puts ("Enter a number (empty line to quit):");
	while (gets (number) && number[0] != '\0')		// 控制空行结束
	{
		value = strtol (number, &end, 10);
		printf ("value: %ld, stopped at %s (%d)\n",
			value, end, *end);
		value = strtol (number, &end, 16);
		printf ("value: %ld, stopped at %s (%d)\n",
			value, end, *end);
		puts ("Next number: ");
	}
	puts ("Bye!");

	return 0;
}