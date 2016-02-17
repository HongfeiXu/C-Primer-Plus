// doubincl.c -- 两次包含同一头文件
#include <stdio.h>
#include "names_st.h"
#include "names_st.h"   // 不小心包含同一文件

int main (void)
{
	names winner = {"Less", "Ismoor"};
	printf ("The winner is %s %s.\n", winner.first, winner.last);

	return 0;
}
/*

[alex@EX c16_10]$ cc doubincl.c names_st.h 
[alex@EX c16_10]$ ./a.out 
The winner is Less Ismoor.


*/
