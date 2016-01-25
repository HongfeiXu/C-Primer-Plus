#include <stdio.h>
void copy_arr (double source[], double target[], int num);
void print_double_array (double arr[], int num);

int main (void)
{
	double source[7] = {1, 2, 3, 4, 5, 6, 7};
	double target[3];
	printf ("source array:\n");
	print_double_array (source, 7);
	copy_arr (source + 2, target, 3);
	printf ("target array:\n");
	print_double_array (target, 3);

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