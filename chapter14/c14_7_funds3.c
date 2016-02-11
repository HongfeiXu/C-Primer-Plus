/* fund3.c -- 把结构作为参数传递 */
#include <stdio.h>
#define FUNDLEN 50

struct funds {
	char bank[FUNDLEN];
	double bankfund;
	char save[FUNDLEN];
	double savefund;
};

double sum (struct funds moolah);   // 参数是一个结构

int main (void)
{	
	struct funds stan = {
		"Galic-Melon Bank",
		3024.72,
		"Lucky's Savings and Loan",
		9237.11
	};

	printf ("Stan has a total of $%.2f.\n", sum (stan));

	struct funds alex = stan;		// 把一个结构赋值给另一个结构
	
	printf ("Alex has a total of $%.2f.\n", sum (alex));

	return 0;
}

double sum (struct funds moolah)
{
	return (moolah.bankfund + moolah.savefund);
}

/*

[alex@EX chapter14]$ ./a.out 
Stan has a total of $12261.83.

*/
