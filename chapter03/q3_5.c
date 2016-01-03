#include <stdio.h>
int main (void)
{
    unsigned int age;

    printf ("Please enter your age:____\b\b\b\b");
    scanf("%u", &age);
    printf ("You have lived %lf seconds\n", 3.156e7 * age);
    

    return 0;
}
