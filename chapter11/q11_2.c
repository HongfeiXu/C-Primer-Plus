/*
修改并测试练习1中的函数，使得可以在 n 个字符之后，
或第一个空格、制表符、换行符后停止读取输入，由上述情况中最先被满足的那个终止读取。
*/
#include <stdio.h>
#include <string.h>
#define MAX 80

// 用 start 指向字符数组， end 指向字符数组最后一个元素的地址
void get_n_char (char *start, char **end, int n);		

int main (void)
{
	char str[MAX];
	char *start = str;
	char *end = str;		// 此处的 end 为了之后指向数组的最后一个有效元素
	int n;

	puts ("How many characters you want to get?");
	scanf ("%d", &n);
	getchar ();	// consume the 回车
	printf ("Now, Please enter %d characeters: \n", n);
	// 通过传入 实参 &end 到 get_n_char () 函数来修改 end 的值，使其真正指向数组的最后一个有效元素
	get_n_char(start, &end, n);	
	while (start <= end)
		putchar (*start++);

	return 0;
}

void get_n_char (char *p, char **end, int n)		// 使用 getchar () 来接受 n 个字符
{
	int cnt = 0;
	while (cnt < n && (*(p + cnt)  = getchar ()) != ' ' && *(p + cnt) != '\t' && *(p + cnt) != '\n')
		cnt++;
	*end = p + cnt;
}

/*
[alex@EX chapter11]$ ./a.out 
How many characters you want to get?
10
Now, Please enter 10 characeters: 
abcdefg	
abcdefg	[alex@EX chapter11]$ ./a.out 
How many characters you want to get?
5
Now, Please enter 5 characeters: 
asfjklsalf


*/