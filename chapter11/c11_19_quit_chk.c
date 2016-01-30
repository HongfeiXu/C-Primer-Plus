/* quit_chk.c -- 某程序的开始 */
#include <stdio.h>
#include <string.h>
#define SIZE 81
#define LIM 100
#define STOP "quit"
int main (void)
{
	char input[LIM][SIZE];
	int ct = 0;

	printf("Enter up to %d lines (type quit to quit): \n", LIM);
	// 输入单词 quit 或者达到 LIM 的限制时，程序就推出对输入的读取
	while (ct < LIM && gets (input[ct]) != NULL &&				
		strcmp (input[ct], STOP) != 0)
	// 输入一个空行来终止输入
//	while (ct < LIM && gets (input[ct]) != NULL && input[ct][0] != '\0')
	{
		ct++;
	}
	printf("%d strings entered.\n", ct);

	return 0;
}