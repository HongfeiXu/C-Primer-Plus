/*
 *  编写一个函数，返回int数组中的最大值
 *  并在一个简单的程序中测试这个函数
 *
 * */
#include <stdio.h>
#include <stdlib.h>     // to use rand () srand ()
#include <time.h>       // to use time () 作为 seed
#define SIZE 10
int max (int arr[], int num);
void print_int_array (int arr[], int num);

int main (void)
{
    int arr[SIZE];
    int i;
    srand (time (0));
    for (i = 0; i < SIZE; i++)
    {
       arr[i] = rand() % 100;       // 随机取100以内的数字赋给数组
    }
    print_int_array(arr, SIZE);
    printf ("The max element in the array arr[] is %d\n", max (arr, SIZE));

    return 0;
}

int max (int arr[], int num)
{
    int max;
    int index;

    max = arr[0];     // 开始用 arr[0] 赋值 max
    for (index = 0; index < num; index++)
    {
        if (arr[index] > max)
            max = arr[index];
    }

    return max;
}

void print_int_array (int arr[], int num)
{
    int index;

    for (index = 0; index < num; index++)
        printf ("%d ", arr[index]);
    putchar ('\n');
}
