// 编写一个函数，返回一个double数组中最大和最小的数之间的差值。
#include <stdio.h>
#define SIZE 10
double max_dif (double arr[], int len);
void print_double_array (double arr[], int num);

int main (void)
{
	double arr[SIZE] = {1.2, 3.4, -12, 12, 0.9, 100, -90, 99, -70, 0};
	print_double_array (arr, SIZE);
	printf ("The max dif is %lf\n", max_dif (arr, SIZE));

	return 0;
}

double max_dif (double arr[], int len)
{
	double max, min;
	int index;

	for (index = 0, max = arr[0], min = arr[0]; index < len; index++)
	{
		if (max < arr[index])
			max = arr[index];
		if (min > arr[index])
			min  = arr[index];
	}

	return max - min;
}

void print_double_array (double arr[], int num)
{
    int index;

    for (index = 0; index < num; index++)
        printf ("%.2lf ", arr[index]);
    putchar ('\n');
}