#include <stdio.h>
#define ROWS 3
#define COLS 5
void show_arr (const double arr[][COLS], int rows);
void double_arr (double arr[][COLS], int rows);

int main (void)
{
	double arr[ROWS][COLS] = {
		{1, 2, 3, 4, 5},
		{6, 7, 8, 9, 10},
		{10, 11, 12, 13 ,14}
	};

	show_arr (arr, ROWS);
	double_arr (arr, ROWS);
	show_arr (arr, ROWS);

	return 0;
}

void show_arr (const double arr[][COLS], int rows)
{
	int i, j;

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < COLS; j++)
			printf ("%.2lf ", arr[i][j]);
		printf("\n");
	}
}

void double_arr (double arr[][COLS], int rows)
{
	int i, j;

	for (i = 0; i < rows; i++)
		for (j = 0; j < COLS; j++)
			arr[i][j] *= 2;
}