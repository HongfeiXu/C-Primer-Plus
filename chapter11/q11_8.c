// reverse the string you input
#include <stdio.h>
#include <string.h>
#define SIZE 81
#define LIM 100
void reverse_string (char *str);
int main (void)
{
	char input[LIM][SIZE];
	int ct = 0;
	int i;

	printf ("Enter up to %d lines, and I will reverse string in each lines.\n", LIM);
	printf ("To stop, press the Enter key at a line's start.\n");
	while (ct < LIM && gets (input[ct]) != NULL && input[ct][0] != '\0')
	{

		reverse_string (input[ct]);
		ct++;
	}
	puts ("After reverse_string:");
	for (i = 0; i < ct; i++)
		puts (input[i]);

	return 0;
}

void reverse_string (char *str)
{
	int len = strlen (str);
	char temp;
	int start = 0;
	int end = len - 1;

	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

/*
[alex@EX chapter11]$ ./a.out 
Enter up to 100 lines, and I will reverse string in each lines.
To stop, press the Enter key at a line's start.
Hello world!
What are you doing? Man

After reverse_string:
!dlrow olleH
naM ?gniod uoy era tahW


*/