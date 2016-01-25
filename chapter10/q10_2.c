#include <stdio.h>
void copy_arr (double [], double [], int);
void copy_ptr (double [], double [], int);
void print_double_array (double [], int);

int main (void)
{
    double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[5];
    double target2[5];
    copy_arr (source, target1, 5);
    copy_ptr (source, target2, 5);

    printf ("Now target1: \n");
    print_double_array (target1, 5);

    printf ("Now target2: \n");
    print_double_array (target2, 5);

    return 0;
}

void copy_arr (double source[], double target[], int num)
{
    int index;
    
    for (index = 0; index < num; index++)
        target[index] = source[index];
}

void copy_ptr (double source[], double target[], int num)
{
    int index;

    for (index = 0; index < num; index++)
        *(target + index) = *(source + index);
}

void print_double_array (double arr[], int num)
{
    int index;

    for (index = 0; index < num; index++)
        printf ("%.2lf ", arr[index]);
    putchar ('\n');
}
