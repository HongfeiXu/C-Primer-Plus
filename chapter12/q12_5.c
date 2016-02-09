/*
 *  编写一个产生 100 个 1 到 10 范围内的随机数程序，并且以降序排序。
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100

void show_int_array (int arr[], int len);
void sort_int_array (int arr[], int len);

int main (void)
{
	int arr[SIZE];

	srand ((unsigned int) time (0));
	for (int i = 0; i < SIZE; ++i)
	{
		arr[i] = rand() % 10 + 1;
	}
	printf ("Original random number:\n");
	show_int_array (arr, SIZE);
	sort_int_array (arr, SIZE);
	printf ("\nAfter sort:\n");
	show_int_array (arr, SIZE);
	printf ("\n");

	return 0;
}

void show_int_array (int arr[], int len)
{
	for (int i = 0; i < len; ++i)
	{
		printf ("%3d", arr[i]);
		if ((i + 1) % 15 == 0)
			printf ("\n");
	}
}

void sort_int_array (int arr[], int len)
{
	int i, j;
	int temp;

	for (i = 0; i < len - 1; i++)
		for (j = i + 1; j < len; j++)
		{
			if (arr[i] < arr[j])
			{
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
}

/*

[alex@EX chapter12]$ ./a.out 
Original random number:
  5  3  2  4  9  5  4 10  1  4  3  4  8  3 10
  9  2  6  5  5  4  6  1  8  6  5 10  6  5  6
  9  1 10 10  5 10  6 10  9  7  3  2  2 10  6
  3 10  8  9  4  2  2  9  2  9  5  9 10  2  5
  7  2  5  8  1  9  7  9  8  6  5  2  9  8  1
  4  1 10  1  1  3  5  2  4  8  2 10  6  4  3
 10 10  4  5  8  6  5  6  4  5
After sort:
 10 10 10 10 10 10 10 10 10 10 10 10 10 10  9
  9  9  9  9  9  9  9  9  9  9  8  8  8  8  8
  8  8  8  7  7  7  6  6  6  6  6  6  6  6  6
  6  6  5  5  5  5  5  5  5  5  5  5  5  5  5
  5  5  4  4  4  4  4  4  4  4  4  4  4  3  3
  3  3  3  3  3  2  2  2  2  2  2  2  2  2  2
  2  2  1  1  1  1  1  1  1  1


*/