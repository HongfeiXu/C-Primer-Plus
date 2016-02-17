/* ifdef.c -- 使用条件编译 */
#include <stdio.h>
#define JUST_CHECKING
//#undef JUST_CHECKING
#define LIMIT 4
int main (void)
{	
	int i;
	int total = 0;
	for (i = 0; i <= LIMIT; i++)
	{
		total += 2*i*i + 1;
#ifdef JUST_CHECKING
		printf ("i = %d, running total = %d\n", i, total);
#endif
	}
	printf ("Grand total = %d\n", total);

	return 0;
}

/*

[alex@EX chapter16]$ ./a.out 
i = 0, running total = 1
i = 1, running total = 4
i = 2, running total = 13
i = 3, running total = 32
i = 4, running total = 65
Grand total = 65

*/
