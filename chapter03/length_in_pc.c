// 数据存储
#include <stdio.h>
int main (void)
{
    printf ("整型数据：\n");
    printf ("字符常量 %lu bits\n", sizeof ('c') * 8);
    printf ("char %lu bits\n", sizeof (char) * 8);    
    printf ("short %lu bits\n", sizeof (short) * 8);
    printf ("int %lu bits\n", sizeof (int) * 8);
    printf ("long %lu bits\n", sizeof (long) * 8);
    printf ("long long %lu bits\n", sizeof (long long) * 8);


// 一些例子
    char c = 'FATE';  // 字符常量'FATE'存储在一个32未单元中，赋值给char变量时，被阶段，最后8位起作用
    printf ("\n\nc = %c\n", c);

    printf ("\n\n浮点型数据：\n");
    printf ("float %lu bits\n", sizeof (float) * 8);
    printf ("double %lu bits\n", sizeof (double) * 8);
    printf ("浮点常量1 %lu bits\n", sizeof (8.) * 8);
    printf ("浮点常量2 %lu bits\n", sizeof (8.F) * 8);
    printf ("%e\n", 0xa.1fp10); 
    printf ("%a\n", 0xa.1fp10); 
    printf ("%f\n", 0xa.1fp10); 
    return 0;
}
