/*
 *	reducto.c -- 把您的文件压缩为原来的三分之一
 *  重写程序清单 13.2 中的程序，不使用命令行参数，而是提示用户键入所需的信息。
 *
 * */
 // 
 #include <stdio.h>
 #include <stdlib.h>     // 为了调用 exit ()
 #include <string.h>     // 为 strcpy () 和 strcat () 函数提供原型
 #define LEN 40
 int main (void)
 {
 	FILE *in, *out;
 	char name[LEN];
 	int ch;
 	int count = 0;

 	puts ("Enter name of input file: ");
 	gets (name);
 	if ((in = fopen (name, "r")) == NULL)
 	{
 		fprintf (stderr, "Can't open file %s.\n", name);
 		exit (EXIT_FAILURE);
 	}
	strcat (name, ".red");
	if ((out = fopen (name, "w")) == NULL)
	{
		fprintf(stderr, "Can't open file %s.\n", name);
		exit (EXIT_FAILURE);
	}
	while((ch = getc (in)) != EOF)
	{
		if (count++ % 3 == 0)
			putc (ch, out);
	}
	if (fclose (in) != 0 || fclose (out) != 0)
		fprintf(stderr, "Error in closing files.\n");

 	return 0;
 }