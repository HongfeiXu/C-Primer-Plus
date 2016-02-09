/* append.c -- 把多个文件追加到一个文件中 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 1024
#define SLEN 81

void append (FILE *source, FILE *dest);

int main (void)
{
	FILE *fa, *fs;          // fa 指向被追加的目的文件， fs 指向源文件
	int files = 0;          // 追加文件的个数
	char file_app[SLEN];    // 被追加文件的名称
	char file_src[SLEN];    // 源文件的名称
	puts ("Enter name of destination file: ");
	gets (file_app);
	if ((fa = fopen (file_app, "a")) == NULL) // 以追加模式打开目的文件
	{
		fprintf (stderr, "Can't open %s\n", file_app);  // 如果不能成功打开则退出
		exit (2);
	}
	if (setvbuf (fa, NULL, _IOFBF, BUFSIZE) != 0)       // 为这个文件建立一个 1024 字节的缓冲区
	{
		fputs ("Can't create output buffer\n", stderr); // 如果不能成功建立，则退出
		exit (3);
	}
	puts ("Enter name of first source file (empty line to quit): ");
	while (gets (file_src) && file_src[0] != '\0')
	{
		if (strcmp (file_src, file_app) == 0)           // 如果源文件名与目的文件相同，则跳到下一个文件
			fputs ("Can't append file to itself\n", stderr);
		else if ((fs = fopen (file_src, "r")) == NULL)    // 如果不能以读取模式打开文件，则跳到下一个文件
			fprintf (stderr, "Can't open %s\n", file_src);
		else
		{
			if (setvbuf (fs, NULL, _IOFBF, BUFSIZE) != 0)   // 为这个文件建立一个 1024 字节的缓冲区
			{
				fputs ("Can't create input buffer\n", stderr);      // 如果不能成功建立，则跳到下一个文件
				continue;
			}
			append (fs, fa);
			if (ferror (fs) != 0)
				fprintf (stderr, "Error in reading file %s.\n",
					file_src);
			if (ferror (fa) != 0)
				fprintf (stderr, "Error in writing file %s.\n",
					file_app);
			fclose (fs);									// 关闭当前源文件
			files++;
			printf ("File %s appended.\n", file_src);
			puts ("Next file (empty to quit): ");
		}
	}
	printf ("Done. %d files appended.\n", files);
	fclose (fa);        // 关闭目标文件

	return 0;
}

void append (FILE *source, FILE *dest)
{
	size_t bytes;
	static char temp[BUFSIZE];      // 具有代码块作用域的静态变量，分配一次

	// 每次复制 不多于 1024 个字节，用 bytes 记录读入缓存的字符数
	while ((bytes = fread (temp, sizeof (char), BUFSIZE, source)) > 0)
		fwrite (temp, sizeof (char), bytes, dest);
}
