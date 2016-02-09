#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_n_dice (int dice, int sides);

int main (void)
{
	int sets, sides, dice;
	srand ((unsigned int) time(0));

	printf ("Enter the number of sets: enter q to stop.\n");
	while (scanf ("%d", &sets) == 1)
	{
		printf ("How many sides and how many dice?\n");
		scanf ("%d %d", &sides, &dice);
		printf ("Here are %d sets of %d %d-sides throws.\n",
			sets, dice, sides);
		for (int i = 0; i < sets; ++i)
			printf ("%d ", roll_n_dice (dice, sides));

		printf ("\nHow many sets? Enter q to stop.\n");
	}

	return 0;
}

int roll_n_dice (int dice, int sides)
{
	int total = 0;
	if (sides < 2)
	{
		printf ("Need at least 2 sides.\n");
		return -2;
	}
	if (dice < 1)
	{
		printf ("Need at least 1 die.\n");
		return -1;
	}
	for (int i = 0; i < dice; ++i)
		total += rand() % sides + 1;

	return total;
}

/*

[alex@EX chapter12]$ ./a.out 
Enter the number of sets: enter q to stop.
18
How many sides and how many dice?
6 3
Here are 18 sets of 3 6-sides throws.
10 9 12 10 11 7 9 8 10 14 10 12 13 9 13 8 11 15 
How many sets? Enter q to stop.
q


*/