#include <stdio.h>
inline void eatline ()
{
	while (getchar () != '\n')
		continue;
}

int main (void)
{
	eatline ();
	return 0;
}
/*
[alex@EX chapter16]$ gcc -Wall tmp.c 
/tmp/cc6Hl1E8.o：在函数‘main’中：
tmp.c:(.text+0xa)：对‘eatline’未定义的引用
collect2: 错误：ld 返回 1



*/