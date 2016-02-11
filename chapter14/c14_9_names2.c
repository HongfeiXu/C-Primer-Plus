/*
 *  程序要求您输入名和姓，然后告诉您姓名中的字母总数
 *  names2.c -- 传递和返回结构
 *
 * */
#include <stdio.h>
#include <string.h>

struct namect {
	char fname[20];
	char lname[20];
	int letters;
};

struct namect getinfo (void);
struct namect makeinfo (struct namect);
void showinfo (struct namect);

int main (void)
{
	struct namect person;

	person = getinfo ();
	person = makeinfo (person);
	showinfo (person);

	return 0;
}

struct namect getinfo (void)
{
	struct namect temp;

	printf ("Please enter your first name.\n");
	gets (temp.fname);
	printf ("Please enter your last name.\n");
	gets (temp.lname);

	return temp;
}

struct namect makeinfo (struct namect info)
{
	info.letters = strlen (info.fname) + strlen (info.lname);
	return info;
}

void showinfo (struct namect info)
{
	printf ("%s %s, your name contains %d letters.\n",
		info.fname, info.lname, info.letters);
}

/*

[alex@EX chapter14]$ ./a.out 
Please enter your first name.
Roger
Please enter your last name.
Alex
Roger Alex, your name contains 9 letters.


*/