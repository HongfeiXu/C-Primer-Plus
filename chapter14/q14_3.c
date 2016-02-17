/*
 *  修改程序清单 14.2 中的数目列表程序，
 *  使它首先按照输入的顺序输出图书的描述，
 *  然后按照标题的字母升序输出图书的描述，
 *  最后按照 value 值的升序输出图书的描述。
 *
 *  这里我使用了 14.14 生成的文件 book.dat 
 *  通过读取文件内容来给 library[] 赋值。
 *  当然也可以直接通过标准输入来赋值 library[]
 *
 *
 * */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXTITL 40
#define MAXAUTL	40
#define MAXBKS 100

struct book{
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};
void showbooks (const struct book library[], int n);
void showbooks_by_title (const struct book library[], int n);
void showbooks_by_value (const struct book library[], int n);



int main (void)
{
	struct book library[MAXBKS];    // book 结构数组
	int count = 0;
	FILE *pbooks;

	if ((pbooks = fopen ("book.dat", "a+b")) == NULL)
	{
		fputs ("Can't open book.dat file", stderr);
		exit (1);
	}
	while (count < MAXBKS && 
		fread (&library[count], sizeof (struct book), 1, pbooks) == 1)
		count++;

/*	printf ("Please enter the book title.\n");
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
	}*/

	if (count > 0)
	{
		printf ("showbooks:\n");
		showbooks (library, count);
		printf ("showbooks_by_title:\n");
		showbooks_by_title (library, count);
		printf ("showbooks_by_value:\n");
		showbooks_by_value (library, count);

	}
	else
		printf ("No books? Too bad.\n");

	return 0;
}

void showbooks (const struct book library[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf ("%s by %s: $%.2f\n",
			library[i].title, library[i].author, library[i].value);
}

void showbooks_by_title (const struct book library[], int n)
{
	struct book lib[n];
	struct book temp;
	int i, j;

	for (i = 0; i < n; i++)
		lib[i] = library[i];
	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			if (strcmp (lib[i].title, lib[j].title) > 0)
			{
				temp = lib[i];
				lib[i] = lib[j];
				lib[j] = temp;
			}
	for (i = 0; i < n; i++)
		printf ("%s by %s: $%.2f\n",
			lib[i].title, lib[i].author, lib[i].value);
}

void showbooks_by_value (const struct book library[], int n)
{
	int i, j;
	struct book lib[n];
	struct book temp;
	for (i = 0; i < n; i++)
		lib[i] = library[i];
	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			if (lib[i].value > lib[j].value)
			{
				temp = lib[i];
				lib[i] = lib[j];
				lib[j] = temp;
			}
	for (i = 0; i < n; i++)
		printf ("%s by %s: $%.2f\n",
			lib[i].title, lib[i].author, lib[i].value);
}


/*
// 通过读文件
[alex@EX chapter14]$ ./a.out 
showbooks:
Metric Merriment by Polly Poetica: $18.99
Deadly Farce by Dudley Forse: $15.99
The Third Jar by Nellie Nostrum: $22.99
harry potter by jk rollin: $100.00
The song of ice and fire by Martiin: $200.00
showbooks_by_title:
Deadly Farce by Dudley Forse: $15.99
Metric Merriment by Polly Poetica: $18.99
The Third Jar by Nellie Nostrum: $22.99
The song of ice and fire by Martiin: $200.00
harry potter by jk rollin: $100.00
showbooks_by_value:
Deadly Farce by Dudley Forse: $15.99
Metric Merriment by Polly Poetica: $18.99
The Third Jar by Nellie Nostrum: $22.99
harry potter by jk rollin: $100.00
The song of ice and fire by Martiin: $200.00

*/


/*
// 通过标准输入
[alex@EX chapter14]$ ./a.out 
Please enter the book title.
Please [enter] at the start of a line to stop.
ice and fire
Now enter the author.
Alex
Now enter the value.
100.0
Enter the next title.
Harry
Now enter the author.
Potter
Now enter the value.
89
Enter the next title.
NICE 
Now enter the author.
hoho
Now enter the value.
102
Enter the next title.

showbooks:
ice and fire by Alex: $100.00
Harry by Potter: $89.00
NICE  by hoho: $102.00
showbooks_by_title:
Harry by Potter: $89.00
NICE  by hoho: $102.00
ice and fire by Alex: $100.00
showbooks_by_value:
Harry by Potter: $89.00
ice and fire by Alex: $100.00
NICE  by hoho: $102.00





*/
