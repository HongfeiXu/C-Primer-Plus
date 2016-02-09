// pe12-2a.c
#include "pe12-2a.h"
static int smode;
static double distance;
static double fuel;

void set_mode (int mode)
{
	if (mode == 0)
		smode = 0;
	else if (mode == 1)
		smode = 1;
	else
	{
		smode = mode % 2;
		printf ("Invalid mode specified. Mode %d (%s) used.\n",
		 smode, smode == 0 ? "metric" : "US");
	}
}

void get_info (void)
{
	printf ("Enter distance traveled in %s: ", smode == 0 ? "kilometers" : "miles");
	scanf ("%lf", &distance);
	printf ("Enter fuel consumed in %s: ", smode == 0 ? "liters" : "gallons");
	scanf ("%lf", &fuel);
}

void show_info (void)
{
	if (smode == 0)
		printf ("Fuel consumption is %.2lf liters per 100 km.\n", 100 * fuel / distance);
	else
		printf ("Fuel consumption is %.1lf miles per gallon.\n", distance / fuel);
}
