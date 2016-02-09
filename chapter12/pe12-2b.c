//pe12-2b.c
#include "pe12-2a.h"
int main (void)
{
	int mode;

	printf ("Enter 0 for metric mode, 1 for us mode: ");
	scanf ("%d", &mode);
	while (mode >= 0)
	{
		set_mode (mode);
		get_info ();
		show_info ();
		printf ("Enter 0 for metric mode, 1 for us mode");
		printf (" (-1 to quit): ");
		scanf ("%d", &mode);
	}
	printf ("Done.\n");

	return 0;
}

/*

[alex@EX chapter12]$ !g
gcc -Wall pe12-2a.c pe12-2b.c 
[alex@EX chapter12]$ ./a.out 
Enter 0 for metric mode, 1 for us mode: 0
Enter distance traveled in kilometers: 600
Enter fuel consumed in liters: 78.8
Fuel consumption is 13.13 liters per 100 km.
Enter 0 for metric mode, 1 for us mode (-1 to quit): 1
Enter distance traveled in miles: 434
Enter fuel consumed in gallons: 12.7
Fuel consumption is 34.2 miles per gallon.
Enter 0 for metric mode, 1 for us mode (-1 to quit): 3
Invalid mode specified. Mode 1 (US) used.
Enter distance traveled in miles: 388
Enter fuel consumed in gallons: 15.3
Fuel consumption is 25.4 miles per gallon.
Enter 0 for metric mode, 1 for us mode (-1 to quit): -1
Done.

*/