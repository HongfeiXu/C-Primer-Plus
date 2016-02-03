/* 
设计并测试一个函数，其功能是搜索由函数的第一个参数指定的字符串，
在其中查找由函数第二个参数指定的字符的第一次出现的位置。如果找到，返回指向这个字符的指针;
如果没有找到，返回空字符。（这种方式和 strchr() 函数的功能一样。）
在一个使用循环语句为这个函数提供的完整程序中进行测试。
*/
#include <stdio.h>
#include <string.h>
#define SIZE 80
char * mystrchr (char *str, char ch);

int main(void)
{
	char str[SIZE];
	char ch;
	char *p;
	char conti = 'Y';
	while (conti == 'Y')
	{
		puts ("Please enter a string.");
		fgets (str, SIZE, stdin);
		puts ("Please enter a character.");
		ch = getchar ();
		// consume the '\n', or the next conti = getchar () will get the '\n', and that's not funny
		getchar ();		
		p = mystrchr (str, ch);
		if (p == NULL)
			printf ("There is not such character %c\n", ch);
		else
			printf ("There is such a character %c, which is %c\n", ch, *p);
		puts ("Do you want to continue?(Y for yes, N for no)");
		conti = getchar ();
		getchar ();		// consume the '\n'
	
	}
	puts ("Bye.");
	
	return 0;
}

char *mystrchr (char *str, char ch)
{
	char *p = str;
	while (*p != ch && *p != '\0')
	{
		p++;
	}
	// 如果要搜索的 ch 不是 '\0' 但是 游标指针搜索到了最后的 '\0'，说明没有找到 ch 
	if (*p == '\0' && ch != '\0')		
		return NULL;
	else
		return p;
}

/*
[alex@EX chapter11]$ ./a.out 
Please enter a string.
Learn C is my happy stuff.
Please enter a character.
C
There is such a character C, which is C
Do you want to continue?(Y for yes, N for no)
Y
Please enter a string.
I can learn it well 
Please enter a character.
l
There is such a character l, which is l
Do you want to continue?(Y for yes, N for no)
Y   
Please enter a string.
and I can use it to learn futher.
Please enter a character.
L
There is not such character L
Do you want to continue?(Y for yes, N for no)
N
Bye.


*/