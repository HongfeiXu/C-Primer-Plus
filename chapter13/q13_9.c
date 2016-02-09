/*
 *  修改程序清单 13.3 中的程序，从 1 开始，根据加入列表的顺序为每个单词编号。
 *  当再次运行程序时，确保新的单词编号接着前面的编号。
 *
 * */
 #include <stdio.h>
 #include <stdlib.h>
 #define MAX 40
 int main (void)
 {
 	FILE *fp;
 	char words[MAX];
 	char temp[MAX + 3];
 	int i = 0;

 	if ((fp = fopen ("words", "a+")) == NULL)
 	{
 		fprintf(stderr, "Can't open file \"words\"\n");
 		exit (1);
 	}
 	while (fscanf (fp, "%s", temp) == 1)    // 每次读取一个单词（包括编号）
 	{
 		sscanf (temp, "%d.%s", &i, words);  // 从字符串中读取格式化输入，取得编号值。
 	}
 	i++;	// 确保新的单词编号接着前面的编号。
 	puts ("Enter words you want to add to the file (ctrl + D to quit)");
 	while (fscanf (stdin, "%s", words) == 1)
 	{
 		sprintf (temp, "%d.%s", i, words);
 		fprintf(fp, "%s ", temp);
 		i++;
 	}
 	
 	puts ("File contents: ");
 	rewind (fp);
 	while (fscanf (fp, "%s", temp) == 1)
 	{
 		puts (temp);
 	}

 	return 0;
 }

/*

[alex@EX chapter13]$ ./a.out 
Enter words you want to add to the file (ctrl + D to quit)
Hello world
What are you doing
File contents: 
1.Hello
2.world
3.What
4.are
5.you
6.doing
[alex@EX chapter13]$ ./a.out 
Enter words you want to add to the file (ctrl + D to quit)
The new beginning
Oh yeah
File contents: 
1.Hello
2.world
3.What
4.are
5.you
6.doing
7.The
8.new
9.beginning
10.Oh
11.yeah


*/