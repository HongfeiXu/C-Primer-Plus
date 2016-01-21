/* 编写函数，使其返回3个整型参数中的最大值 */

int max_3 (int a, int b, int c)
{
    int max = a;

    if (max < b)
        max = b;
    else if (max < c)
        max = c;

    return max;
}
