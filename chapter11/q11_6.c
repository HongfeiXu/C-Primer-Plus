/*
 *  strncpy (s1, s2, n)函数从s2复制n个字符给s1，
 *  并在必要时截断s2或为其填充额外的空字符。
 *  函数返回s1。编写这个函数，
 *  并在一个使用循环语句为这个函数提供输入的完整程序中进行测试。
 * */
#include <stdio.h>
#include <string.h>
#define SIZE 20
#define LIM 5
void mystrncpy (char *s1, char *s2, int n);

 int main (void)
 {
 	char target[LIM][SIZE];
 	char temp[SIZE];
 	int num;
 	int i = 0;

 	while (i < LIM)
 	{
	 	puts ("Please enter the source string:");
 		gets (temp)
 		printf ("How many characters you want to copy from?\n");
 		scanf ("%d", &num);
 		getchar ();		// consume the '\n'
 		strncpy (target[i], temp, num);
 		target[i][num] = '\0';		
 		printf ("Now the target string you copy to is:\n%s\n", target[i]);
 		i++;
 	}



 	return 0;
 }

 void mystrncpy (char *s1, char *s2, int n)
 {
 	int i;

 	for (i = 0; i < n; i++)
 	{
 		*(s1 + i) = *(s2 + i);
 		if (*(s2 + i) == '\0')
 			break;
 	}
 	for (; i < n; i++)
 		*(s1 + i) = '\0';

 }