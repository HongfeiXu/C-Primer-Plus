/*
 *  编写一个文件复制程序。程序需要从命令行获得源文件名和目的文件名。
 *  尽可能使用标准 I/O 和二进制模式。
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 1024

int main (int argc, char *argv[])
{
	FILE *src, *tgt;
	char temp[BUFSIZE];
	size_t bytes;

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
		if ((src = fopen (argv[1], "rb")) == NULL)
		{
			fprintf (stderr, "Can't open file %s.\n", argv[1]);
			exit (2);
		}
		if ((tgt = fopen (argv[2], "wb")) == NULL)
		{
			fprintf(stderr, "Can't open file %s.\n", argv[2]);
			exit (2);
		}
		// 练习使用 setvbuf...........
		if (setvbuf (src, NULL, _IOFBF, BUFSIZE) != 0)
		{
			fputs ("Can't create input buffer.\n", stderr);
			exit (3);
		}
		if (setvbuf (tgt, NULL, _IOFBF, BUFSIZE) != 0)
		{
			fputs ("Can't create output buffer.\n", stderr);
			exit (3);
		}
		// ...........

		while ((bytes = fread (temp, sizeof (char), BUFSIZE, src)) > 0)
			fwrite (temp, sizeof (char), bytes, tgt);

		if (ferror (src) != 0)
			fprintf(stderr, "Error in reading file %s.\n", argv[1]);
		if (ferror (tgt) != 0)
			fprintf(stderr, "Error in writing file %s.\n", argv[2]);
		
		fclose (src);
		fclose (tgt);
	}

	return 0;
}
