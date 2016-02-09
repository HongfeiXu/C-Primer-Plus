#include <stdio.h>
#include <stdlib.h>

int *make_array (int size, int val);
void show_array (const int ar[], int n);

int main (void)
{
	int *pa;
	int size;
	int value;

	printf ("Enter the number of elements: ");
	scanf ("%d", &size);
	while (size > 0)
	{
		printf ("Enter the initialization value: ");
		scanf ("%d", &value);
		pa = make_array (size, value);
		if (pa)
		{
			show_array (pa, size);
			free (pa);
		}
		printf ("Enter the number of elements (<1 to quit): ");
		scanf ("%d", &size);
	}
	printf ("Done.\n");

	return 0;
}

int *make_array (int size, int val)
{
	int *pa;
	pa = (int *) malloc (size * sizeof (int));
	for (int i = 0; i < size; ++i)
	{
		pa[i] = val;
	}
	return pa;
}

void show_array (const int ar[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf ("%d ", ar[i]);
		if ((i + 1) % 8 == 0)
			printf ("\n");
	}
	if (n % 8 != 0)		// 在需要加 '\n' 的时候添加
		printf ("\n");
}

/*

[alex@EX chapter12]$ ./a.out 
Enter the number of elements: 10
Enter the initialization value: 13
13 13 13 13 13 13 13 13 
13 13 
Enter the number of elements (<1 to quit): 16
Enter the initialization value: 13
13 13 13 13 13 13 13 13 
13 13 13 13 13 13 13 13 
Enter the number of elements (<1 to quit): 8
Enter the initialization value: 0
0 0 0 0 0 0 0 0 
Enter the number of elements (<1 to quit): 24
Enter the initialization value: -9
-9 -9 -9 -9 -9 -9 -9 -9 
-9 -9 -9 -9 -9 -9 -9 -9 
-9 -9 -9 -9 -9 -9 -9 -9 
Enter the number of elements (<1 to quit): 0
Done.

*/
