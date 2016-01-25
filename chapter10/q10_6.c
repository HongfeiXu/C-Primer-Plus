#include <stdio.h>
#define ROWS 3
#define COLS 2
void copy_arr (double [], double [], int );
void print_double_array (double [], int );

int main (void)
{
	double source[ROWS][COLS] = {
		{1.2, 32.1},
		{-1, 0.2},
		{10.0, 9.2}
	};
	double target[ROWS][COLS];
	int row;

	for (row = 0; row < ROWS; row++)
	{
		copy_arr (source[row], target[row], COLS); // 一次拷贝一行
	}
	printf ("source array:\n");
	for (row = 0; row < ROWS; row++)
		print_double_array (source[row], COLS);
	printf ("target array:\n");
	for (row = 0; row < ROWS; row++)
		print_double_array (target[row], COLS);

	return 0;
}


void copy_arr (double source[], double target[], int num)
{
    int index;
    
    for (index = 0; index < num; index++)
        target[index] = source[index];
}

void print_double_array (double arr[], int num)
{
    int index;

    for (index = 0; index < num; index++)
        printf ("%.2lf ", arr[index]);
    putchar ('\n');
}