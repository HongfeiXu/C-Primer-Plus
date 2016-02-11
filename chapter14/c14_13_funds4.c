/* funds4.c -- 向函数传递一个结构数组 */
#include <stdio.h>
#define FUNDLEN 50
#define N 2

struct funds {
	char bank[FUNDLEN];
	double bankfund;
	char save[FUNDLEN];
	double savefund;
};
double sum (const struct funds money[], int n);

int main (void)
{
	struct funds jones[N] = {
		{
			"Garlic-Melon Bank",
			3024.72,
			"Lucky's Savings and Loan",
			9237.11
		},
		{
			"Honest Jack's Bank",
			3534.28,
			"Party Time Savings",
			3203.89
		}
	};

	printf ("The Joneses have a total money of $%.2f.\n",
		sum (jones, N));

	return 0;
}

double sum (const struct funds money[], int n)
{
	double total;
	int i;

	for (i = 0; i < n; i++)
		total += money[i].bankfund + money[i].savefund;

	return (total);
}

/*

[alex@EX chapter14]$ ./a.out 
The Joneses have a total money of $19000.00.

*/