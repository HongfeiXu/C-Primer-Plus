#include <stdio.h>
int main (void)
{
    float height;
    char name[15];

//    printf ("Enter your height in feet: \n");
//    scanf ("%f", &height);
    printf ("Enter your height in cm: \n");
    scanf ("%f", &height);
    height = height / 30.48;            // 将cm 转化为 feet
    printf ("Enter your name: \n");
    scanf ("%s", name);
    printf ("%s, you are %1.3f feet tall.\n", name, height);

    return 0;
}
