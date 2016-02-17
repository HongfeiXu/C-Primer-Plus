// predef.c -- 预定义标识符
#include <stdio.h>
void why_me (void);

int main (void)
{
	printf ("The file is %s.\n", __FILE__);
	printf ("The date is %s.\n", __DATE__);
	printf ("The time is %s.\n", __TIME__);
	printf ("The version is %ld.\n", __STDC_VERSION__);
	printf ("This is line %d.\n", __LINE__);
	printf ("This function is %s.\n", __func__);
	why_me ();

	return 0;
}

void why_me (void)
{
	printf ("This function is %s.\n", __func__);
	printf ("This is line %d.\n", __LINE__);
}

/*

[alex@EX chapter16]$ ./a.out 
The file is c16_12_predef.c.
The date is Feb 16 2016.
The time is 15:12:50.
The version is 201112.
This is line 11.
This function is main.
This function is why_me.
This is line 21.

[alex@EX chapter16]$ cc -std=c99 c16_12_predef.c 
[alex@EX chapter16]$ ./a.out 
The file is c16_12_predef.c.
The date is Feb 16 2016.
The time is 15:14:10.
The version is 199901.
This is line 11.
This function is main.
This function is why_me.
This is line 21.


*/
