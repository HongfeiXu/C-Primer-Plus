/* 什么情况下使用 & */
#include <stdio.h>
int main (void)
{
    int age;
    float assets;
    char pet[30];

    printf("Enter your age, assets, and favorite pet.\n");
    scanf ("%d %f", &age, &assets); //此处需使用 &
    scanf ("%s", pet);              // 对 char 数组不需使用 &
    printf ("%d $%.2f %s\n", age, assets, pet);

    return 0;
}
