/*
 *  编写一个函数。当给出月份号后，程序返回一年中到该月为止（包括该月）
 *  总共的天数。假定在外部声明了第2题中的结构模板和一个该结构的数组
 *
 * */

#include <stdio.h>
int count_day (int);

struct month {
	char name[20];  // 月份名
	char abb[4];    // 3个字母月份名缩写
	int day;        // 该月的天数
	int id;         // 月份号
};

struct month year[12] = {
	{
		"January",
		"Jan",
		31,
		1
	},
	{
		"Febrary",
		"Feb",
		28,
		2
	},
	{
		"March",
		"Mar",
		31,
		3
	},
	{
		"April",
		"Apr",
		30,
		4
	},
	{
		"May",
		"May",
		31,
		5
	},
	{
		"June",
		"Jun",
		30,
		6
	},
	{
		"July",
		"Jul",
		31,
		7
	},
	{
		"Augst",
		"Aug",
		31,
		8
	},
	{
		"September",
		"Sep",
		30,
		9
	},
	{
		"October",
		"Oct",
		31,
		10
	},
	{
		"November",
		"Nov",
		30,
		11
	},
	{
		"December",
		"Dec",
		31,
		12
	}
};

int main (void)
{
	int month;
	printf ("Enter your month: ");
	scanf ("%d", &month);
	printf ("There are %d days.\n", count_day (month));

	return 0;
}

int count_day (int month)
{
	int i;
	int total = 0;
	if (month < 1 || month > 12)
		return -1;
	for (i = 0; i < month; i++)
		total += year[i].day;
	return total;
}

/*

[alex@EX chapter14]$ ./a.out 
Enter your month: 12
There are 365 days.


*/
