/*  编写一个函数 string_in () ，它接受两个字符串指针参数。
 *  如果第二个字符串被包含在第一个字符串中，函数就返回被包含的字符串开始的地址。
 *  否则，就返回空指针。
 *  在一个使用循环语句为这个函数提供输入的完整程序中进行测试。
 * */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define SIZE 30
char * string_in (char *s1, char *s2);

int main (void)
{
	char s1[SIZE];
	char s2[SIZE];
	char *p;
	int i = 0;

	while (i++ < 5)
	{
		printf ("Please enter string s1:\n");
		gets (s1);
		printf ("Please enter string s2:\n");
		gets (s2);
		p = string_in (s1, s2);
		if (p != NULL)
		{
			printf ("there is such a strig \"%s\" in string \"%s\"\n", s2, s1);
			puts (p);
		}
		else 
			printf ("not such a string \"%s\" in string \"%s\"	\n", s2, s1);
	}
	
	return 0;
}

char * string_in (char *s1, char *s2)
{
	int i, j;
	bool in;
	for (i = 0; s1[i] != '\0'; i++)
	{
		in = true;
		for (j = 0; s2[j] != '\0'; j++)
		{
			if (s1[i+j] != s2[j])
			{
				in = false;
				break;
			}
		}
		if (in == true)		// find s2 in s1
		{
			return s1 + i;
		}

	}
	return NULL;
}

/*
[alex@EX chapter11]$ ./a.out 
Please enter string s1:
Hello world
Please enter string s2:
w
there is such a strig "w" in string "Hello world"
world
Please enter string s1:
hi girl
Please enter string s2:
girl
there is such a strig "girl" in string "hi girl"
girl
Please enter string s1:
fuguang jianpai .
Please enter string s2:
.
there is such a strig "." in string "fuguang jianpai ."
.
Please enter string s1:
alex roger
Please enter string s2:
ro
there is such a strig "ro" in string "alex roger"
roger
Please enter string s1:
alex
Please enter string s2:
b
not such a string "b" in string "alex"	



*/