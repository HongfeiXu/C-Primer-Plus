/* addaword.c -- 使用 fprintf () fscanf () 和 rewind () 函数 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 40
int main (void)
{
	FILE *fp;
	char words[MAX];

	if ((fp = fopen ("words", "a+")) == NULL)
	{
		fprintf (stdout, "Can't open \"words\" file.\n");
		exit (1);
	}
	puts ("Enter words to add to the file; press the Enter");
	puts ("key at the beginning of a line to terminate.");
	while (gets (words) != NULL && words[0] != '\0')
	{
		fprintf (fp, "%s ", words);
	}
	puts ("File contents: ");
	rewind (fp);    // 回到文件的开始处
	while (fscanf (fp ,"%s", words) == 1)
		puts (words);
	if (fclose (fp) != 0)
		fprintf (stderr, "Error closing file\n");


	return 0;
}

/*

[alex@EX chapter13]$ ./a.out 
Enter words to add to the file; press the Enter
key at the beginning of a line to terminate.
The fabulous programmer

File contents: 
The
fabulous
programmer
[alex@EX chapter13]$ ./a.out 
Enter words to add to the file; press the Enter
key at the beginning of a line to terminate.
enchanted the
large

File contents: 
The
fabulous
programmer
enchanted
the
large


*/
