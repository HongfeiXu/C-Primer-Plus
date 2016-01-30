/* copy1.c -- strcpy () 示例程序 */
#include <stdio.h>
#include <string.h>
#define SIZE 40
#define LIM 5
int main (void)
{
	char qwords[LIM][SIZE];
	char temp[SIZE];
	int i = 0;

	printf("Enter %d words beginning with q: \n", LIM);
	while (i < LIM && gets(temp))
	{
		if (temp[0] == 'q')
	//	if (strncmp (temp, "q", 1) == 0)	// 两者等价
		{
			strcpy (qwords[i], temp);
			i++;
		}
		else
		{
			printf("%s doesn't begin with q!\n", temp);
		}
	}
	printf ("Here are %d words accepted: \n", i);
	for (int j = 0; j < i; j++)
		puts (qwords[j]);

	return 0;
}
