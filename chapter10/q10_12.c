#include <stdio.h>
#define ROWS 3
#define COLS 5

void input_array (double arr[][COLS], int rows);
double average1d (double arr[], int num);
double average2d (double arr[][COLS], int rows);
double max (double arr[][COLS], int rows);
void show_array2d (double arr[][COLS], int rows);

int main (void)
{
	double arr[ROWS][COLS];
	int i;

	input_array (arr, ROWS);
	for (i = 0; i < ROWS; i++)
	{
		printf ("The aveage of %dth row is %.2lf\n", i, average1d (arr[i], COLS));
	}
	printf ("The 2d array is:\n");
	show_array2d (arr, ROWS);
	printf ("The average of the 2d array is %.2lf\n", average2d (arr, ROWS));
	printf("The max of the 2d array is %.2lf\n", max (arr, ROWS));

	return 0;
}

void input_array (double arr[][COLS], int rows)
{
	int i, j;

	for (i = 0; i < rows; i++)
	{
		printf("please enter 5 numbers:\n");
		for (j = 0; j < COLS; j++)
			scanf ("%lf", &arr[i][j]);
	}
}

double average1d (double arr[], int num)
{
	int i;
	double sum;
	for (i = 0; i < num; i++)
		sum += arr[i];
	return sum / num;
}

double average2d (double arr[][COLS], int rows)
{
	int i, j;
	double sum;

	for (i = 0, sum = 0.0; i < rows; i++)
		for (j = 0; j < COLS; j++)
			sum += arr[i][j];
	return sum / (COLS * rows);
}

double max (double arr[][COLS], int rows)
{
	int i, j;
	double max;

	for (i = 0, max = arr[0][0]; i < rows; i++)
	{
		for (j = 0; j < COLS; j++)
			if (arr[i][j] > max)
				max = arr[i][j];
	}

	return max;
}

void show_array2d (double arr[][COLS], int rows)
{
	int i, j;

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < COLS; j++)
			printf("%.2f ", arr[i][j]);
		putchar ('\n');
	}
}