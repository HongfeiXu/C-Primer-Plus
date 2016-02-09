// parta.c -- 各种存储类 (gcc -Wall parta.c partb.c)
#include <stdio.h>
void report_count (void);
void accumulate (int k);
int count = 0;          // 文件作用域，外部链接
int main (void)
{
	int value;          // 自动变量
	register int i;     // 寄存器变量

	printf ("Enter a positive integer (0 to quit): ");
	while (scanf ("%d", &value) == 1 && value > 0)
	{
		++count;        // 使用文件作用域变量
		for (i = value; i >= 0; i--)
			accumulate (i);
		printf ("Enter a positive integer (0 to quit): ");
	}
	report_count ();

	return 0;
}

void report_count (void)
{
	printf ("Loop executed %d times\n", count);

}


/*

[alex@EX chapter12]$ ./a.out 
Enter a positive integer (0 to quit): 5
loop cycle: 1
subtotal: 15; total: 15
Enter a positive integer (0 to quit): 10
loop cycle: 2
subtotal: 55; total: 70
Enter a positive integer (0 to quit): 2
loop cycle: 3
subtotal: 3; total: 73
Enter a positive integer (0 to quit): 0
Loop executed 3 times


*/