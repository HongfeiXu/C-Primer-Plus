/* parrot.c -- 使用 fgets () 和 fputs () 函数*/
#include <stdio.h>
#define MAXLINE 20
int main (void)
{
	char line[MAXLINE];

	while (fgets (line, MAXLINE, stdin) != NULL &&
		line[0] != '\n')
		fputs (line, stdout);

	return 0;
}

/*

[alex@EX chapter13]$ ./a.out 
The silent knight 
The silent knight
strode solemnly down the dank and dark hall
strode solemnly down the dank and dark hall


[alex@EX chapter13]$ ./a.out 
1234567890123456789
1234567890123456789[alex@EX chapter13]$ 


*/