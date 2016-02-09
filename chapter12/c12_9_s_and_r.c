/* s_and_r.c -- 包含函数 rand1() 和 srand1() 的文件 */
/* 使用 ANSI C 的可移植算法 */
static unsigned long int next = 1;  // 种子，next是一个具有内部链接的文件作用域变量
int rand1 (void)
{
    /* 产生伪随机数的魔术般的公式 */
    next = next * 1103515245 + 12345;
    return (unsigned int) (next / 65536) % 32768;
}

void srand1 (unsigned int seed)		// reset next
{
    next = seed;
}
