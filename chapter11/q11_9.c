#include <stdio.h>
#include <string.h>
#define SIZE 81
#define LIM 100
void delete_blank (char *str);

int main (void)
{
	char input[LIM][SIZE];
	int ct = 0;
	int i = 0;

	printf ("Enter up to %d lines, and I will delete the blank in the input string.\n", LIM);
	printf ("To stop, press the Enter key at a line's start.\n");
	while (ct < LIM && gets (input[ct]) != NULL && input[ct][0] != '\0')
	{
		delete_blank (input[ct]);
		ct++;
	}
	puts ("After delete_blank:");
	for (; i < ct; i++)
		puts (input[i]);

	return 0;
}

void delete_blank (char *str)
{
	int i, j;
	int len = strlen (str);
	for (i = 0, j = 0; j < len; j++)
	{
		if (str[j] != ' ')      // 跳过 ' '
		{
			str[i] = str[j];    
			i++;
		}
	}
	str[i] = '\0';
}
