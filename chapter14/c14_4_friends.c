/* friends.c -- 使用指向结构的指针 */
#include <stdio.h>
#define LEN 20
struct names {
	char first[LEN];
	char last[LEN];
};
struct guy {
	struct names handle;
	char favfood[LEN];
	char job[LEN];
	float income;
};

int main (void)
{
	struct guy fellow[2] = {
		{
			{ "Ewen", "Villard" },
			"grilled salmon",
			"personality coach",
			58112.00
		},
		{
			{ "Rodney", "Swillbelly" },
			"triple",
			"tabloid editor",
			2324.00
		}
	};
	struct guy * him;           // 这是一个指向结构的指针
	printf("address #1: %p #2: %p\n", &fellow[0], &fellow[1]);
	him = &fellow[0];           // 告诉指针它要指向的地址
	printf ("pointer #1: %p #2: %p\n", him, him + 1);
	printf ("him->income is $%.2f; (*him).income is $%.2f\n",
		him->income, (*him).income);
	him++;                      // 指向下一个结构
	printf ("him->favfood is %s; him->handle.last is %s\n",
		him->favfood, him->handle.last);

	return 0;
}

/*

[alex@EX chapter14]$ ./a.out 
address #1: 0x7ffd67565d70 #2: 0x7ffd67565dc4
pointer #1: 0x7ffd67565d70 #2: 0x7ffd67565dc4
him->income is $58112.00; (*him).income is $58112.00
him->favfood is triple; him->handle.last is Swillbelly


*/
