#include <stdio.h>
void copy_vla (int rows, int cols, double source[rows][cols], double target[rows][cols]);
void print_vla (int rows, int cols, double arr[rows][cols]);

int main (void)
{
	double arr[3][5] = {
		{1, 2, 3, 4, 5},
		{6, 7, 8, 9, 10},
		{10, 11, 12, 13 ,14}
	};
	double target[3][5];

	printf ("arr :\n");
	print_vla (3, 5, arr);
	copy_vla (3, 5, arr, target);
	printf ("target:\n");
	print_vla (3, 5 ,target);

	return 0;
}

void copy_vla (int rows, int cols, double source[rows][cols], double target[rows][cols])
{	
	int i, j;
	for (i = 0; i < rows; i++)
		for (j = 0; j < cols; j++)
			target[i][j] = source[i][j];
}

void print_vla (int rows, int cols, double arr[rows][cols])
{
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
			printf ("%.2lf ", arr[i][j]);
		putchar ('\n');
	}
}