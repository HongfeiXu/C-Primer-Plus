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
	int count = 0;			// 数组 library 中有效元素数目
	int index;
	char choice;
	FILE *pbooks;
	int size = sizeof (struct book);

	if ((pbooks = fopen ("book.dat", "r+b")) == NULL)
	{
		fputs ("Can't open book.dat file", stderr);
		exit (1);
	}   
	rewind (pbooks);        // 确保文件位置指针处于文件开始部分

// 读取文件中每个记录，允许用户选择删除记录或修改记录的内容。
// 如果删除记录，就把空出来的数组空间留给下一个要读入的记录。
	while (count < MAXBKS && 
		fread (&library[count], size, 1, pbooks) == 1)
	{
		if (count == 0)
			puts ("Current contents of book.dat: ");
		printf ("%s by %s: $%.2f\n", 
			library[count].title, library[count].author, library[count].value);
		printf ("Do you want to remove this item or change it ?\n");
		printf ("'r' for remove, 'c' for change, [enter] to continue.\n");
		if ((choice = getchar ()) == 'r')
		{
			count--;
			printf ("Ok, you just remove the item.\n");
		}
		else if (choice == 'c')
		{	
			while (getchar () != '\n')
				continue; 		// consume '\n'
			puts ("Please enter the book title: ");
			gets (library[count].title);
			puts ("Now enter the author: ");
			gets (library[count].author);
			puts ("Now enter the value: ");
			scanf ("%f", &library[count].value);
			printf ("Ok, you just change this item to: \n");
			printf ("\t%s by %s: $%.2f\n", 
				library[count].title, library[count].author, library[count].value);
		}
		else
			;

		count++;
	}

	if (count == MAXBKS)
	{
		fputs ("The book.dat file is full.", stderr);
		exit (2);
	}

    // 增加新的记录
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

    // 输出所有记录并写入文件
	if (count > 0)
	{
		puts ("Here is the list of your books: ");
		for (index = 0; index < count; index++)
			printf ("%s by %s: $%.2f\n", 
				library[index].title, library[index].author, library[index].value);
		if ((pbooks = fopen ("book.dat", "w")) == NULL)
		{
			fputs ("Can't open book.dat file", stderr);
			exit (1);
		}
		fclose (pbooks);
		if ((pbooks = fopen ("book.dat", "w")) == NULL)
		{
			fputs ("Can't open book.dat file", stderr);
			exit (1);
		}
        // fwrite () 一次写入多个块
		fwrite (&library[0], size, count, pbooks);
	}
	else
	{
		puts ("No books? Too bad.");
		fclose (pbooks);
		if ((pbooks = fopen ("book.dat", "w")) == NULL)
		{
			fputs ("Can't open book.dat file", stderr);
			exit (1);
		}
	}
	puts ("Bye.");

	fclose (pbooks);

	return 0;
}


/*

[alex@EX chapter14]$ ./a.out 
Current contents of book.dat: 
Harry Potter by JK: $109.00
Do you want to remove this item or change it ?
'r' for remove, 'c' for change, [enter] to continue.

The Song of Ice and Fire by Martin: $100.00
Do you want to remove this item or change it ?
'r' for remove, 'c' for change, [enter] to continue.
 
Ring by sdjfalk: $100.00
Do you want to remove this item or change it ?
'r' for remove, 'c' for change, [enter] to continue.
c
Please enter the book title: 
Ring
Now enter the author: 
Slex
Now enter the value: 
200
Ok, you just change this item to: 
	Ring by Slex: $200.00
Please add new book titles.
Press [enter] at the start of a line to stop.
Here is the list of your books: 
Harry Potter by JK: $109.00
The Song of Ice and Fire by Martin: $100.00
Ring by Slex: $200.00
Bye.
[alex@EX chapter14]$ ./a.out 
Current contents of book.dat: 
Harry Potter by JK: $109.00
Do you want to remove this item or change it ?
'r' for remove, 'c' for change, [enter] to continue.

The Song of Ice and Fire by Martin: $100.00
Do you want to remove this item or change it ?
'r' for remove, 'c' for change, [enter] to continue.

Ring by Slex: $200.00
Do you want to remove this item or change it ?
'r' for remove, 'c' for change, [enter] to continue.

Please add new book titles.
Press [enter] at the start of a line to stop.

Here is the list of your books: 
Harry Potter by JK: $109.00
The Song of Ice and Fire by Martin: $100.00
Ring by Slex: $200.00
Bye.



*/