/*
设计并测试一个函数，可以输入读取 n 个字符（包括空格、制表符和换行符），
把结果存放在一个数组中，这个数组的地址通过参数来传递。
*/
#include <stdio.h>
#include <string.h>
#define MAX 80
void get_n_char (char *p, int n);

int main (void)
{
	char str[MAX];
	int n;

	puts ("How many characters you want to get?");
	scanf ("%d", &n);
	getchar ();	// consume the 回车
	printf ("Now, Please enter %d characeters: \n", n);
	get_n_char(str, n);
	for (int i = 0; i < n; ++i)
	{
		putchar (*(str+i));
	}

	return 0;
}

void get_n_char (char *p, int n)		// 使用 getchar () 来接受 n 个字符
{
	for (int i = 0; i < n; ++i)
	{
		*(p+i) = getchar();
	}
}