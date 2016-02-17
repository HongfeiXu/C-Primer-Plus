/*
 *  题目见课本
 *
 * */
#include <stdio.h>
#define LEN 20

struct names {
	char fname[LEN];
	char mname[LEN];
	char lname[LEN];
};

struct  social {
	int id;
	struct names name;
};

struct social arr[5] = {
	{
		1,
		{ "Roger", .lname = "Alex" }
	},
	{
		2,
		{ "Lebron", .lname = "James" }
	},
	{
		3,
		{ "Kobe", "James", "Bryant" }
	},
	{
		4,
		{ "Antoney", .lname = "Carmon" }
	},
	{
		5,
		{ "Denny", "James", "Green" }
	}
};

void show (struct social array[], int n);
void show2 (struct social s);

int main (void)
{
	int i;
//	show (arr, 5);
	for (i = 0; i < 5; i++)
		show2 (arr[i]);

	return 0;
}

void show (struct social array[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (array[i].name.mname[0] != '\0')
			printf ("%s, %s %c. - %d\n", 
				array[i].name.fname, array[i].name.lname, array[i].name.mname[0], array[i].id);
		else
			printf ("%s, %s - %d\n",
				array[i].name.fname, array[i].name.lname, array[i].id);
	}
}

void show2 (struct social s)
{
	if (s.name.mname[0] != '\0')
		printf ("%s, %s %c. - %d\n",
			s.name.fname, s.name.lname, s.name.mname[0], s.id);
	else
		printf ("%s, %s - %d\n",
			s.name.fname, s.name.lname, s.id);
}

/*

[alex@EX chapter14]$ !g
gcc -Wall q14_4.c 
[alex@EX chapter14]$ ./a.out 
Roger, Alex - 1
Lebron, James - 2
Kobe, Bryant J. - 3
Antoney, Carmon - 4
Denny, Green J. - 5





*/
