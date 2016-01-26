// 使用变长数组完成上题
#include <stdio.h>
#define ROWS 3
#define COLS 5
void input_array (int rows, int cols, double arr[rows][cols]);
double average1d (int num, const double arr[num]);
double average2d (int rows, int cols, double arr[rows][cols]);
double max (int rows, int cols, double arr[rows][cols]);
void show_array2d (int rows, int cols, double arr[rows][cols]);

int main (void)
{
	double arr[ROWS][COLS];
	input_array (ROWS, COLS, arr);
	show_array2d (ROWS, COLS, arr);
	printf ("The average of each row is: \n");
	for (int i = 0; i < ROWS; ++i)
	{
		printf ("Row %d's average is %lf\n", i, average1d (COLS, arr[i]));
	}
	printf ("The average of all elem is:\n");
	printf ("%lf\n", average2d (ROWS, COLS, arr));


	return 0;
}

void input_array (int rows, int cols, double arr[rows][cols])
{
	int i, j;

	for (i = 0; i < rows; i++)
	{
		printf ("Please enter %d numbers.\n", cols);
		for (j = 0; j < cols; j++)
			scanf ("%lf", &arr[i][j]);
	}
}

double average1d (int num, const double arr[num])
{
	double total;
	int i;

	for (i = 0, total = 0; i < num; i++)
		total += arr[i];

	return total / num;
}

double average2d (int rows, int cols, double arr[rows][cols])
{
	int i, j;
	double total = 0;

	for (i = 0; i < rows; i++)
		for (j = 0; j < cols; j++)
		{
			total += arr[i][j];
		}
	return total / (rows * cols);
}

void show_array2d (int rows, int cols ,double arr[rows][cols])
{
	for (int i = 0; i < rows; ++i)			// ??? 可行否
	{
		for (int j = 0; j < cols; ++j)
		{
			printf ("%.2lf ", arr[i][j]);
		}
		printf ("\n");
	}
}