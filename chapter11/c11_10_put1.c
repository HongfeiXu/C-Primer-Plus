/* put1.c -- 不添加换行符，打印一个字符串 */
#include <stdio.h>
#define MAX 8
void put1 (const char * string);
int main (void)
{	
	char name[MAX];
	gets (name);
	put1 (name);
	return 0;
}

void put1 (const char * string)		// 不会改变这个字符串
{
	while (*string != '\0')
		putchar (*string++);		// ++(后缀) 优先级高于 *
}
