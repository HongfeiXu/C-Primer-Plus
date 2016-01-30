/* 	nogo.c -- 这个程序能满足要求吗？
	希望把用户的响应与一个已有的字符串进行比较。
*/
#include <stdio.h>
#define ANSWER "Grant"
int main (void)
{
	char try[40];

	puts ("Who is buried in Grant's tomb?");
	gets (try);
	while (try != ANSWER)
	{
		puts ("No, that's wrong. Try again. ");
		gets (try);
	}
	puts ("That's right! ");

	return 0;
}

/*
[alex@EX chapter11]$ ./a.out 
Who is buried in Grant's tomb?
Grant
No, that's wrong. Try again. 
jklsa
No, that's wrong. Try again. 
asjfajslfja
No, that's wrong. Try again. 
asa
No, that's wrong. Try again. 
asjafljda
No, that's wrong. Try again. 

No, that's wrong. Try again. 
asfaj'
No, that's wrong. Try again. 
^C


*/