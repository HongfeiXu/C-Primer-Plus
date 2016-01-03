/* 输出类型的大小 */
#include <stdio.h>
int main (void)
{ 
    // C99为 sizeof() 返回值提供了 %zd 说明符
    printf ("Type int has a size of %zd bytes.\n", sizeof (int));  
    printf ("Type char has a size of %zd bytes.\n", sizeof (char));
    printf ("Type long has a size of %zd bytes.\n", sizeof (long));
    printf ("Type double has a size of %zd bytes.\n", 
    sizeof (double));

    return 0;
}

