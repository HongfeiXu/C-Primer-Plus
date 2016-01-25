/*
	编写一个函数，返回一个double数组中存储的最大数值的索引，并在一个简单的程序中测试这个函数
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
int pos_max (double arr[], int num);
void print_double_array (double [], int);

int main (void)
{
	double arr[SIZE];
	int i;

	srand (time(0));
	for (i = 0; i < SIZE; i++)
		arr[i] = rand() % 100;
	print_double_array (arr, SIZE);
	printf ("The max elem in array arr[] is the %dth.\n", pos_max (arr, SIZE) + 1);

	return 0;
}

int pos_max (double arr[], int num)
{
	double max;
	int i;
	int pos;

	for (i = 0, max = arr[0], pos = 0; i < num; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			pos = i;
		}
	}

	return pos; // 返回最大元素的下标
}

void print_double_array (double arr[], int num)
{
    int index;

    for (index = 0; index < num; index++)
        printf ("%.2lf ", arr[index]);
    putchar ('\n');
}