#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main (void)
{
	int arr[10];
	int ran;

	for (int i = 0; i < 10; ++i)
	{
		for (int ii = 0; ii < 10; ++ii) // 置数组为全0
		{
			arr[ii] = 0;
		}
		srand ((unsigned int) time (0));// 改种子
		for (int j = 0; j < 1000; ++j)
		{
			ran = rand() % 10 + 1;
			++arr[ran - 1];             // 计数
		}
		printf ("There are :\n");
		for (int k = 0; k < 10; ++k)
		{
			printf ("%4d times %2d\n", arr[k], k + 1);
		}
		printf ("\n");
	}


	return 0;
}
/*

[alex@EX chapter12]$ ./a.out 
There are :
  89 times  1
 102 times  2
 110 times  3
 103 times  4
  98 times  5
  98 times  6
  95 times  7
  98 times  8
 111 times  9
  96 times 10

There are :
  89 times  1
 102 times  2
 110 times  3
 103 times  4
  98 times  5
  98 times  6
  95 times  7
  98 times  8
 111 times  9
  96 times 10

There are :
  89 times  1
 102 times  2
 110 times  3
 103 times  4
  98 times  5
  98 times  6
  95 times  7
  98 times  8
 111 times  9
  96 times 10

There are :
  89 times  1
 102 times  2
 110 times  3
 103 times  4
  98 times  5
  98 times  6
  95 times  7
  98 times  8
 111 times  9
  96 times 10

There are :
  89 times  1
 102 times  2
 110 times  3
 103 times  4
  98 times  5
  98 times  6
  95 times  7
  98 times  8
 111 times  9
  96 times 10

There are :
  89 times  1
 102 times  2
 110 times  3
 103 times  4
  98 times  5
  98 times  6
  95 times  7
  98 times  8
 111 times  9
  96 times 10

There are :
  89 times  1
 102 times  2
 110 times  3
 103 times  4
  98 times  5
  98 times  6
  95 times  7
  98 times  8
 111 times  9
  96 times 10

There are :
  89 times  1
 102 times  2
 110 times  3
 103 times  4
  98 times  5
  98 times  6
  95 times  7
  98 times  8
 111 times  9
  96 times 10

There are :
  89 times  1
 102 times  2
 110 times  3
 103 times  4
  98 times  5
  98 times  6
  95 times  7
  98 times  8
 111 times  9
  96 times 10

There are :
  89 times  1
 102 times  2
 110 times  3
 103 times  4
  98 times  5
  98 times  6
  95 times  7
  98 times  8
 111 times  9
  96 times 10


*/