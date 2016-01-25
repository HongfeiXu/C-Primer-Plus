#include <stdio.h>
#define SIZE 10
void addto (const int [], const int [], int [], int num);
void print_double_array (int arr[], int num);

int main (void)
{
	int source[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int source2[SIZE] = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	int target [SIZE];

	print_double_array (source, SIZE);
	print_double_array (source2, SIZE);
	addto (source, source2, target, SIZE);
	print_double_array (target, SIZE);


	return 0;
}

void addto (const int source[], const int source2[], int target[], int num)
{
	int i;

	for (i = 0; i < num; i++)
	{
		target[i] = source[i] + source2[i];
	}

}

void print_double_array (int arr[], int num)
{
    int index;

    for (index = 0; index < num; index++)
        printf ("%d ", arr[index]);
    putchar ('\n');
}
