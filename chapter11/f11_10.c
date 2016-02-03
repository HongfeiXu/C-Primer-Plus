#include <stdio.h>
char *search_first_blank (char *str);// 返回一个指向 str 所指位置后的第一个空格字符的指针，如果找不到，就返回空指针

int main (void)
{
	char str[] = "Hello, world!";
	char * first_blank;

	first_blank = search_first_blank (str);
	printf ("%c\n", *first_blank);
	puts (first_blank);

	return 0;
}

char *search_first_blank (char *str)
{
	char *ptr = str;
	while (*ptr++	)
	{
		if (*ptr == ' ')
			return ptr;
	}
	return ptr;
}