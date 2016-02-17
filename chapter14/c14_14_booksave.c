/* booksave.c -- 把结构内容保存到文件中 */
#include <stdio.h>
#include <stdlib.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10
struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

int main (void)
{
	struct book library[MAXBKS];
	int count = 0;
	int index, filecount;
	FILE *pbooks;
	int size = sizeof (struct book);

	if ((pbooks = fopen ("book.dat", "a+b")) == NULL)
	{
		fputs ("Can't open book.dat file", stderr);
		exit (1);
	}   
	rewind (pbooks);        // 确保文件位置指针处于文件开始部分
	while (count < MAXBKS && 
		fread (&library[count], size, 1, pbooks) == 1)
	{
		if (count == 0)
			puts ("Current contents of book.dat: ");
		printf ("%s by %s: $%.2f\n", 
			library[count].title, library[count].author, library[count].value);
		count++;
	}

	filecount = count;		// 保存已读结构的数目
	if (count == MAXBKS)
	{
		fputs ("The book.dat file is full.", stderr);
		exit (2);
	}

	puts ("Please add new book titles.");
	puts ("Press [enter] at the start of a line to stop.");
	while (count < MAXBKS && gets (library[count].title) != NULL 
		&& library[count].title[0] != '\0')
	{
		puts ("Now enter the author.");
		gets (library[count].author);
		puts ("Now enter the value.");
		scanf ("%f", &library[count++].value);
		while (getchar () != '\n')
			continue;
		if (count < MAXBKS)
			puts ("Enter the next title.");
	}

	if (count > 0)
	{
		puts ("Here is the list of your books: ");
		for (index = 0; index < count; index++)
			printf ("%s by %s: $%.2f\n", 
				library[index].title, library[index].author, library[index].value);
        // fwrite () 一次写入多个块
		fwrite (&library[filecount], size, count - filecount, pbooks);
	}
	else
		puts ("No books? Too bad.");
	puts ("Bye.");

	fclose (pbooks);

	return 0;
}

/*

[alex@EX chapter14]$ ./a.out 
Please add new book titles.
Press [enter] at the start of a line to stop.
Metric Merriment
Now enter the author.
Polly Poetica
Now enter the value.
18.99
Enter the next title.
Deadly Farce
Now enter the author.
Dudley Forse
Now enter the value.
15.99
Enter the next title.

Here is the list of your books: 
Metric Merriment by Polly Poetica: $18.99
Deadly Farce by Dudley Forse: $15.99
Bye.
[alex@EX chapter14]$ ./a.out 
Current contents of book.dat: 
Metric Merriment by Polly Poetica: $18.99
Deadly Farce by Dudley Forse: $15.99
Please add new book titles.
Press [enter] at the start of a line to stop.
The Third Jar
Now enter the author.
Nellie Nostrum
Now enter the value.
22.99
Enter the next title.

Here is the list of your books: 
Metric Merriment by Polly Poetica: $18.99
Deadly Farce by Dudley Forse: $15.99
The Third Jar by Nellie Nostrum: $22.99
Bye.



*/
