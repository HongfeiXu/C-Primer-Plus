#include <stdio.h>
void set_mode (int *mode);
void get_info (const int mode, double *pdistance, double *pfuel);
void show_info (const int mode, const double distance, const double fuel);

int main (void)
{
	int mode;
	double distance, fuel;

	printf ("Enter 0 for metric mode, 1 for US mode: ");
	scanf ("%d", &mode);
	while (mode >= 0)
	{
		set_mode (&mode);
		get_info (mode, &distance, &fuel);
		show_info (mode, distance, fuel);
		printf ("Enter 0 for metric mode, 1 for US mode");
		printf (" (-1 to quit): ");
		scanf ("%d", &mode);
	}

	return 0;
}

void set_mode (int *pmode)
{
	if (*pmode != 0 && *pmode != 1)
	{
		*pmode = *pmode % 2;
		printf ("Invalid mode specified. Mode %d (%s) used.\n", *pmode, *pmode == 0 ? "metric" : "US");
	}
}

void get_info (const int mode, double *pdistance, double *pfuel)
{
	printf ("Enter distance traveled in %s: ", mode == 0 ? "kilometers" : "miles");
	scanf ("%lf", pdistance);
	printf ("Enter fuel consumed in %s: ", mode == 0 ? "liters" : "gallons");
	scanf ("%lf", pfuel);
}

void show_info (const int mode, const double distance, const double fuel)
{
	if (mode == 0)
		printf ("Fuel consumption is %.2lf liters per 100 km.\n", 100 * fuel / distance);
	else
		printf ("Fuel consumption is %.1lf miles per gallon.\n", distance / fuel);

}

/*

[alex@EX chapter12]$ gcc -Wall q12_3.c 
[alex@EX chapter12]$ ./a.out 
Enter 0 for metric mode, 1 for US mode: 0
Enter distance traveled in kilometers: 600
Enter fuel consumed in liters: 78.8
Fuel consumption is 13.13 liters per 100 km.
Enter 0 for metric mode, 1 for US mode (-1 to quit): 1
Enter distance traveled in miles: 434
Enter fuel consumed in gallons: 12.7
Fuel consumption is 34.2 miles per gallon.
Enter 0 for metric mode, 1 for US mode (-1 to quit): 3
Invalid mode specified. Mode 1 (US) used.
Enter distance traveled in miles: 388
Enter fuel consumed in gallons: 15.3
Fuel consumption is 25.4 miles per gallon.
Enter 0 for metric mode, 1 for US mode (-1 to quit): -1

*/