#include <stdio.h>

struct month {
	char name[20];  // 月份名
	char abb[4];    // 3个字母月份名缩写
	int day;        // 该月的天数
	int id;			// 月份号
};

struct month year[12] = {
	{"January", "Jan", 31, 1 },
	{"Febrary", "Feb", 28, 2 },
	{"March", "Mar", 31, 3 },
	{"April", "Apr", 30, 4 },
	{"May", "May", 31, 5 }, 
	{"June", "Jun", 30, 6 }, 
	{"July", "Jul", 31, 7 }, 
	{"Augst", "Aug", 31, 8 }, 
	{"September", "Sep", 30, 9 }, 
	{"October", "Oct", 31, 10 }, 
	{"November", "Nov", 30, 11 }, 
	{"December", "Dec", 31, 12 }
};

int main (void)
{
	int day;
	int mon;
	int yea;
	int total = 0;

	puts ("Please enter your date: ");
	scanf ("%d %d %d", &day, &mon, &yea);

	for (int i = 0; i < mon - 1; ++i)
	{
		total += year[i].day;
	}
	total += day;
	if ((yea % 4 == 0 && yea % 100 != 0) || yea % 400 == 0)
	{
		if (mon > 2)
			total += 1;
	}
	printf ("There are %d days from 1.1.%d to %d.%d.%d\n",
		total, yea, day, mon, yea);

	return 0;
}

/*

[alex@EX chapter14]$ ./a.out 
Please enter your date: 
1 3 2000
There are 61 days from 1.1.2000 to 1.3.2000
[alex@EX chapter14]$ ./a.out 
Please enter your date: 
1 2 2000
There are 32 days from 1.1.2000 to 1.2.2000
[alex@EX chapter14]$ ./a.out 
Please enter your date: 
1 2 2001
There are 32 days from 1.1.2001 to 1.2.2001
[alex@EX chapter14]$ ./a.out 
Please enter your date: 
1 3 2001
There are 60 days from 1.1.2001 to 1.3.2001



*/