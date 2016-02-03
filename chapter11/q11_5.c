/*
编写一个函数 is_within ()。它接受两个参数，一个是字符，另一个是字符串指针。
其功能是，如果字符在字符串中，就返回一个非0值（真）;如果该字符不在字符串中，就返回0值（假）。
在一个使用循环语句为这个函数提供输入的完整程序中进行测试。
*/
#include <stdio.h>
#include <string.h>
#define SIZE 81
int is_within (char ch, char *str);

int main (void)
{
	char ch;
	char str[SIZE];
	char conti = 'Y';
	while (conti == 'Y')
	{
		puts ("Please enter a character.");
		ch = getchar ();
		// consume the '\n', or the next conti = getchar () will get the '\n', and that's not funny
		getchar ();		
		puts ("Please enter a string.");
		fgets (str, SIZE, stdin);
		if (is_within (ch, str)== 0)
			printf ("character %c is not in the string %s", ch, str);
		else 
			printf ("character %c is in the string %s", ch, str);
		puts ("Do you want to continue?(Y for yes, N for no)");
		conti = getchar ();
		getchar ();		// consume the '\n'
	}
	puts ("Bye.");

	return 0;
}

int is_within (char ch, char *str)
{
	while (*str != '\0')
	{
		if (ch == *str)
			return 1;
		str++;
	}
	return 0;
}