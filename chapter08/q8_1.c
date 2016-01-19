#include <stdio.h>
int main (void)
{
	int cnt = 0;

	while (getchar ( ) != EOF)
		cnt++;

	printf ("there are %d characters in the input file.\n", cnt);

	return 0;
}