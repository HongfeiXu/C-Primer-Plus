// name3.c -- 使用指针和 malloc () 函数
#include <stdio.h>
#include <string.h>     // 为了使用 strcpy (), strlen ()
#include <stdlib.h>     // 为了使用 malloc (), free ()

struct namect {
	char *fname;        // 使用指针
	char *lname;
	int letters;
};

void getinfo (struct namect *); // 分配内存
void makeinfo (struct namect *);
void showinfo (struct namect *);
void cleanup (struct namect	*); // 用完后释放内存
    
int main (void)
{
	struct namect person;

	getinfo (&person);
	makeinfo (&person);
	showinfo (&person);
	cleanup	(&person);

	return 0;
}

void getinfo (struct namect *pst)
{
	char temp[81];
	printf ("Please enter your first name.\n");
	gets (temp);
    // 分配用来存放名字的内存
	pst->fname = (char *) malloc (strlen (temp) + 1);
    // 把名字复制到已分配的内存中
	strcpy (pst->fname, temp);
	printf ("Please enter your last name.\n");
	gets (temp);
	pst->lname = (char *) malloc (strlen (temp) + 1);
	strcpy (pst->lname, temp);
}

void makeinfo (struct namect *pst)
{
	pst->letters = strlen (pst->fname) + strlen (pst->lname);
}

void showinfo (struct namect *pst)
{
	printf ("%s %s, your name contains %d letters.\n",
		pst->fname, pst->lname, pst->letters);
}

void cleanup (struct namect *pst)
{
	free (pst->fname);
	free (pst->lname);
}

/*

[alex@EX chapter14]$ ./a.out 
Please enter your first name.
Roger
Please enter your last name.
Alex
Roger Alex, your name contains 9 letters.


*/
