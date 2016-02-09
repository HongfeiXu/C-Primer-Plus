/*
 *  编写一段程序，依次在屏幕上显示命令行中列出的全部文件。
 *  使用 argc 控制循环。
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#define BUFSIZE 1024
 
int main (int argc, char *argv[])
{
	int i;
	FILE *fp;
	int ch;
	char temp[BUFSIZE];
	size_t bytes;	

	if (argc == 1)
	{
		fprintf (stderr, "Usage: %s filename [filename] ...\n", argv[0]);
		exit (1);
	}
	for (i = 1; i < argc; i++)
	{
		printf ("Flie %s:\n", argv[i]);
		if ((fp = fopen (argv[1], "r")) == NULL)
		{
			fprintf (stderr, "Can't open file %s.\n", argv[i]);
			continue;
		}
		else
		{

			
			while ((ch = getc (fp)) != EOF)
				putchar (ch);
		//	第二种读文件的方式
		//	while ((bytes = fread (temp, sizeof (char), BUFSIZE, fp)) > 0)
		//		fwrite (temp, sizeof (char), bytes, stdout);
		}
	}

	return 0;
}
