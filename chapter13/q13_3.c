/*
 *  编写一个文件复制程序，提示用户输入源文件名和输出文件名。
 *  在向输出文件写入时，程序应当使用 ctype.h 中定义的 toupper () 函数
 *  将所有的文本转换成大写。
 *  使用标准I/O和文本模式。
 *
 * */
#include <stdio.h>
#include <string.h>		// to use strcmp ()
#include <ctype.h>		// to use toupper ()
#include <stdlib.h>		// to use exit ()
int main (int argc, char *argv[])
{
	FILE *src, *tgt;
	char temp;

	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s sourcefilename targetfilename\n", argv[0]);
		exit (1);
	}
	else if (strcmp (argv[1], argv[2]) == 0)
	{
		fprintf (stderr, "Can't copy file to itself.\n");
	}
	else
	{
		if ((src = fopen (argv[1], "r")) == NULL)
		{
			fprintf (stderr, "Can't open file %s.\n", argv[1]);
			exit (2);
		}
		if ((tgt = fopen (argv[2], "w")) == NULL)
		{
			fprintf(stderr, "Can't open file %s.\n", argv[2]);
			exit (2);
		}
		
		while (fscanf (src, "%c", &temp) == 1)
			putc (toupper (temp), tgt);

		if (ferror (src) != 0)
			fprintf(stderr, "Error in reading file %s.\n", argv[1]);
		if (ferror (tgt) != 0)
			fprintf(stderr, "Error in writing file %s.\n", argv[2]);
		
		fclose (src);
		fclose (tgt);
	}

	return 0;
}