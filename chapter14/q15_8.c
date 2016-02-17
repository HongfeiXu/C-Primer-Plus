#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define LEN 20
struct seat {
	int id;
	bool alct;
	char fname[LEN];
	char lname[LEN];
};

// 默认情况下的 seats[] 情况，如果文件中无数据，直接处理此数组，若文件中有数据，则从文件中读取数据到数组中。
struct seat seats[12] = {
	{ 1, false }, { 2, false }, { 3, false }, { 4, false }, { 5, false }, { 6, false }, 
	{ 7, false }, { 8, false }, { 9, false }, { 10, false }, { 11, false }, { 12, false }, 
};

char showmenu (void);
void show_num_seats (struct seat array[], int n);
void show_list_seats (struct seat array[], int n);
void show_alph_seats (struct seat array[], int n);
void assign_a_seat (struct seat array[], int n);
void delete_a_seat (struct seat array[], int n);

int main (void)
{
	FILE *pseat;
	int count = 0;
	void (* pf) (struct seat *, int);
	char choice;

	if ((pseat = fopen ("seat.dat", "r+b")) == NULL)
	{
		fprintf (stderr, "Can't open file seat.dat");
		exit (1);
	}

    // 首先从文件中载入数据
	rewind (pseat);
	while (count < 12 && fread (&seats[count], sizeof (struct seat), 1, pseat) == 1)
	{
		if (count == 0)
			printf ("Current contents in file seat.dat: \n");
		if (seats[count].alct == true)
			printf ("%s %s is seating on seat %d\n", 
				seats[count].fname, seats[count].lname, seats[count].id);
		else
			printf ("seat %d is empty.\n", seats[count].id);

		count++;
	}

	choice = showmenu ();
	while (choice != 'f')
	{
		switch (choice)
		{
			case 'a': pf = show_num_seats; break;
			case 'b': pf = show_list_seats; break;
			case 'c': pf = show_alph_seats; break;
			case 'd': pf = assign_a_seat; break;
			case 'e': pf = delete_a_seat; break;
		}
		pf (seats, 12);
		choice = showmenu ();
	}
    // 处理完结构数组之后，将结构数组内容写入文件。
	rewind (pseat);
	// fclose (pseat);
	// if ((pseat = fopen ("seat.dat", "w+b")) == NULL)
	// {
	// 	fprintf (stderr, "Can't open file seat.dat");
	// 	exit (1);
	// }
	fwrite (&seats[0], sizeof (struct seat), 12, pseat);
	fclose (pseat);

	printf ("Bye!\n");

	return 0;
}

char showmenu (void)
{
	char ans;
	puts ("To choose a function, enter its letter label: ");
	puts ("a) Show number of empty seats");
	puts ("b) Show list of empty seats");
	puts ("c) Show alphabetical list of seats");
	puts ("d) Assign a customer to a seat assingment");
	puts ("e) Delete a seat assignment");
	puts ("f) Quit");
	ans = getchar ();
	ans = tolower (ans);
	while (getchar () != '\n')
		continue;
	while (strchr ("abcdef", ans) == NULL)
	{
		puts ("Please enter a a~f letter: ");
		ans = tolower (getchar ());
		while (getchar () != '\n')
			continue;
	}
	return ans;
}

void show_num_seats (struct seat array[], int n)
{
	int ans = 0;
	int i;
	for (i = 0; i < n; i++)
		if (array[i].alct == false)
			ans++;
	printf ("There are %d empty seats.\n", ans);
}

void show_list_seats (struct seat array[], int n)
{
	for (int i = 0; i < n; ++i)
		if (array[i].alct == false)
			printf ("seat %d is empty.\n", array[i].id);
}

void show_alph_seats (struct seat array[], int n)
{
	int i, j;
	struct seat arr[n];
	struct seat temp;
	for (i = 0; i < n; i++)	
		arr[i] = array[i];
	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			if (arr[i].id > arr[j].id)
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
	for (i = 0; i < n; i++)
	{
		if (arr[i].alct == true)
			printf ("%s %s is seating on seat %d\n", 
				arr[i].fname, arr[i].lname, arr[i].id);
		else
			printf ("seat %d is empty.\n", arr[i].id);
	}
}

void assign_a_seat (struct seat array[], int n)
{
	int i = 0;
	while (i < n && array[i].alct == true)
		i++;
	if (i == n)
		printf ("Sorry, there is no empty seat.\n");
	else
	{
		printf ("OK, seat %d is empyt.\nWhat's your first name?\n", array[i].id);
		scanf ("%s", array[i].fname);
		printf ("Now, enter your last name.\n");
		scanf ("%s", array[i].lname);
		while (getchar () != '\n')
			continue;
		array[i].alct = true;
		printf ("%s %s is seating on seat %d\n", 
			array[i].fname, array[i].lname, array[i].id);
	}
}

void delete_a_seat (struct seat array[], int n)
{
	int i = 0;
	while (i < n && array[i].alct == false)
		i++;
	if (i == n)
		printf ("There is nobody on this plane, no need to delete.\n");
	array[i].fname[0] = '\0';
	array[i].lname[0] = '\0';
	array[i].alct = false;
	printf ("seat %d is empty now.\n", array[i].id);
}
