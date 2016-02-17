#include <stdio.h>
#define LEN 20
#define CSIZE 4
struct name {
	char fname[LEN];
	char lname[LEN];
};
struct student {
	struct name s_name;
	float grade[3];
	float avg;
};
void get_grade (struct student array[], int n); // 获得学生的成绩
void set_avg (struct student array[], int n);   // 计算每个结构的平均分，并赋值给结构成员
void show (const struct student s); // 输出每个结构的信息
void show_sub_avg (struct student array[], int n);  // 输出结构的每个数值成员的班级平均分
int main (void)
{
	struct student arr[CSIZE] = {
		{
			{ "Roger", "Alex" }
		},
		{
			{ "Kobe", "Byrant" }
		},
		{
			{ "Lebron", "James" }
		},
		{
			{ "Dwyane", "Wade"}
		}
	};
	
	get_grade (arr, CSIZE);
	set_avg (arr, CSIZE);
	for (int i = 0; i < CSIZE; ++i)
		show (arr[i]);
	show_sub_avg (arr, CSIZE);

	return 0;
}

void get_grade (struct student array[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf ("Enter %s %s's scores of 3 subjects: "
			"(math, chinese, english)\n", 
			array[i].s_name.fname, array[i].s_name.lname);
		scanf ("%f %f %f", &array[i].grade[0], 
			&array[i].grade[1], &array[i].grade[2]);
	}
}

void set_avg (struct student array[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		array[i].avg = (array[i].grade[0] + 
			array[i].grade[1] + array[i].grade[2]) / 3;
}

void show (const struct student s)
{
	printf ("%s %s, scores: %.2f %.2f %.2f, avg: %.2f\n",
		s.s_name.fname, s.s_name.lname, s.grade[0], s.grade[1], s.grade[2], s.avg);
}

void show_sub_avg (struct student array[], int n)
{
	float total;
	int i, j;
	for (i = 0; i < 3; i++)
	{
		total = 0;
		for (j = 0; j < n; j++)
			total += array[j].grade[i];
		printf ("subject %d's avg: %.2f\n", i, total / n);
	}
}

/*

[alex@EX chapter14]$ ./a.out 
Enter Roger Alex's scores of 3 subjects: (math, chinese, english)
99 99 99
Enter Kobe Byrant's scores of 3 subjects: (math, chinese, english)
90 90 100
Enter Lebron James's scores of 3 subjects: (math, chinese, english)
95 95 95
Enter Dwyane Wade's scores of 3 subjects: (math, chinese, english)
100 90 90
Roger Alex, scores: 99.00 99.00 99.00, avg: 99.00
Kobe Byrant, scores: 90.00 90.00 100.00, avg: 93.33
Lebron James, scores: 95.00 95.00 95.00, avg: 95.00
Dwyane Wade, scores: 100.00 90.00 90.00, avg: 93.33
subject 0's avg: 96.00
subject 1's avg: 93.50
subject 2's avg: 96.00




*/
