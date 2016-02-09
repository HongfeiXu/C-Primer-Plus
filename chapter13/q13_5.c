/* 
 *  append.c -- 把多个文件追加到一个文件中
 *  修改程序清单13.6中的程序，使用命令行参数（而不是交互式界面）获得文件名。
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 1024

void append (FILE *dest, FILE *source);

int main (int argc, char *argv[])
{
	FILE *fa, *fs;          // fa 指向被追加的目的文件， fs 指向源文件
	int cnt = argc - 2;		// the number of source file, to control the loop
	int succeed = 0;

	if (cnt <= 0)
	{
		fprintf (stderr, "Usage: %s target_file_name source_file_name [source_file_name]...\n", 
			argv[0]);
		exit (1);
	}
	else
	{
		if ((fa = fopen (argv[1], "a")) == NULL)
		{
			fprintf (stderr, "Can't open file %s.\n", argv[1]);
			exit (1);
		}
		if (setvbuf (fa, NULL, _IOFBF, BUFSIZE) != 0)
		{
			fprintf (stderr, "Can't create output buffer\n");
			exit (2);
		}
		for (int i = 0; i < cnt; ++i)
		{
			if (strcmp (argv [1], argv[i + 2]) == 0)
			{
				fputs ("Can't append file to itself\n", stderr);
				continue;
			}
			if ((fs = fopen (argv[i + 2], "r")) == NULL)
			{
				fprintf (stderr, "Can't open file %s.\n", argv[i + 2]); // 如果不能成功打开文件，则跳到下一个文件
				continue;
			}
			{

			}
			if (setvbuf (fs, NULL, _IOFBF, BUFSIZE) != 0)
			{
				fprintf (stderr, "Can't create input buffer\n");		// 如果不能成功建立，则跳到下一个文件
				continue;
			}
			append (fa, fs);
			if (ferror (fa) != 0)
				fprintf (stderr, "Error in writing file %s\n", argv[1]);
			if (ferror (fs) != 0)
				fprintf (stderr, "Error in reading file %s\n", argv[i + 2]);
			fclose (fs);
			succeed++;
		}
		printf ("Done. %d files appended.\n", succeed);
		fclose (fa);        // 关闭目标文件

	}

	return 0;
}

void append (FILE *dest, FILE *source)
{
	size_t bytes;
	static char temp[BUFSIZE];      // 具有代码块作用域的静态变量，分配一次

	// 每次复制 不多于 1024 个字节，用 bytes 记录读入缓存的字符数
	while ((bytes = fread (temp, sizeof (char), BUFSIZE, source)) > 0)
		fwrite (temp, sizeof (char), bytes, dest);
}
