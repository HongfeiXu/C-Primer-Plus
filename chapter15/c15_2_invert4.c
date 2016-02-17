/* invert4.c -- */
#include <stdio.h>
char * itobs (int, char *);
void show_bstr (const char *);
int invert_end (int num, int bits);

int main (void)
{
	char bin_str[8 * sizeof (int) + 1];
	int number;

	puts ("Enter integers and see them in binary.");
	puts ("Non-numeric input ternimates program.");
	while (scanf ("%d", &number) == 1)
	{
		itobs (number, bin_str);
		printf ("%d is \n", number);
		show_bstr (bin_str);
		putchar ('\n');
		number = invert_end (number, 4);
		printf ("Inverting the last 4 bits gives\n");
		show_bstr (itobs (number, bin_str));
		putchar ('\n');
	}
	puts ("Bye!");

	return 0;
}

char * itobs (int n, char * ps)
{
	int i;
	static int size = 8 * sizeof (int);

	for (i = size - 1; i >= 0; i--, n >>= 1)
		ps[i] = (01 & n) + '0';
	ps[size] = '\0';

	return ps;
}
/* 4位一组显示二进制字符串 */
void show_bstr (const char * str)
{
	int i = 0;
	while (str[i])
	{
		putchar (str[i]);
		if (++i % 4 == 0 && str[i])
			putchar (' ');
	}
}
// 反转一个值num的最后bits位
int invert_end (int num, int bits)
{
	int mask = 0;
	int bitval = 1;
	while (bits-- > 0)
	{
		mask |= bitval;
		bitval <<= 1;
	}
	return num ^ mask;
}


/*

[alex@EX chapter15]$ ./a.out 
Enter integers and see them in binary.
Non-numeric input ternimates program.
100
100 is 
0000 0000 0000 0000 0000 0000 0110 0100
Inverting the last 4 bits gives
0000 0000 0000 0000 0000 0000 0110 1011
1024
1024 is 
0000 0000 0000 0000 0000 0100 0000 0000
Inverting the last 4 bits gives
0000 0000 0000 0000 0000 0100 0000 1111
q
Bye!



*/
