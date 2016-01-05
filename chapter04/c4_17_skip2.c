/* 在scanf() 中使用 * 跳过输入的头两个整数 
 *
 * 如果一个程序需要读取一个文件中某个特定的列（该文件的数据以统一的列排列），
 * 则此功能将非常有用！    
 *
 * */
#include <stdio.h>
int main (void)
{
    int n;

    printf ("Please enter three integersa: \n");
    scanf ("%*d %*d %d", &n);                           // aha
    printf ("The last integer was %d\n", n);

    return 0;
}
