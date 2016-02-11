/* manybook.c -- 包含多本数的图书目录 */
#include <stdio.h>
#define MAXTITL 40
#define MAXAUTL	40
#define MAXBKS 100
struct book{
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

int main (void)
{
	struct book library[MAXBKS];    // book 结构数组
	int count = 0;
	int index;

	printf ("Please enter the book title.\n");
	printf ("Please [enter] at the start of a line to stop.\n");
	while (count < MAXBKS && gets (library[count].title) != NULL
		&& library[count].title[0] != '\0')
	{
		printf ("Now enter the author.\n");
		gets (library[count].author);
		printf("Now enter the value.\n");
		scanf ("%f", &library[count++].value);
		while (getchar () != '\n')      // 清空输入行
			continue;
		if (count < MAXBKS)
			printf ("Enter the next title.\n");
	}
	if (count > 0)
	{
		printf ("Here is the list of your books: \n");
		for (index = 0; index < count; index++)
		{
			printf ("%s by %s: $%.2f\n",
				library[index].title, library[index].author, library[index].value);
		}
	}
	else
		printf ("No books? Too bad.\n");

	return 0;
}

/*

[alex@EX chapter14]$ ./a.out 
Please enter the book title.
Please [enter] at the start of a line to stop.
Computer Systems
Now enter the author.
Bryant
Now enter the value.
100
Enter the next title.
Harry Potter
Now enter the author.
JK
Now enter the value.
200
Enter the next title.

Here is the list of your books: 
Computer Systems by Bryant: $100.00
Harry Potter by JK: $200.00

*/
