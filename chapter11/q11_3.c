#include <stdio.h>
#include <string.h>

void get_word (char word[]);
#define SIZE 20
int main (void)
{
	char word[SIZE];
	get_word (word);
	puts (word);
	return 0;
}

void get_word (char word[])
{
	int index = 0;
	while ((word[index] = getchar ()) && word[index] != ' ' 
		&& word[index] != '\t' && word[index] != '\n')
	{
		index++;
	}
	word[index] = '\0';		// 处理这个 单词 字符串的结尾，用 '\0' 覆盖 ' ', '\t', '\n'
}

/*
[alex@EX chapter11]$ ./a.out 
hellosd slkajflka
hellosd
[alex@EX chapter11]$ ./a.out 
lkjas
lkjas
[alex@EX chapter11]$ ./a.out 
sdjflk	dslkjlkf	
sdjflk
[alex@EX chapter11]$ ./a.out 
dfjlajlfkjds jfasjfl
dfjlajlfkjds


*/