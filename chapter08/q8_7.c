#include <stdio.h>
#define BASE_PAY_1 8.75
#define BASE_PAY_2 9.33
#define BASE_PAY_3 10.00
#define BASE_PAY_4 11.20
#define OVERTIME 1.5
#define LIMIT 40
#define FIRST_300 0.15
#define NEXT_150 0.20
#define EXTRAL 0.25
int main (void)
{
	int level;
	float time;
	float salary;
	float tax;
	float base_pay;
	
	printf ("*****************************************************************\n");
	printf ("Enter the letter corresponding to the desired pay rate or action:\n");
	printf ("a) $%2.2f/hr             ", BASE_PAY_1);
	printf ("b) $%2.2f/hr\n", BASE_PAY_2);
	printf ("c) $%2.2f/hr            ", BASE_PAY_3);
	printf ("d) $%2.2f/hr\n", BASE_PAY_4);
	printf ("e) quit\n");
	printf ("*****************************************************************\n");
    
	while ((level = getchar ()) != 'e')
	{
        while (getchar () != '\n')
            continue;           // consume the '\n'
		switch (level)
		{
			case 'a':
				base_pay = BASE_PAY_1;
				break;
			case 'b':
				base_pay = BASE_PAY_2;
				break;
			case 'c':
				base_pay = BASE_PAY_3;
				break;
			case 'd':
				base_pay = BASE_PAY_4;
				break;
			default:
				printf ("Please enter the right letter!\n");
				printf ("*****************************************************************\n");
				printf ("Enter the letter corresponding to the desired pay rate or action:\n");
				printf ("a) $%2.2f/hr             ", BASE_PAY_1);
				printf ("b) $%2.2f/hr\n", BASE_PAY_2);
				printf ("c) $%2.2f/hr            ", BASE_PAY_3);
				printf ("d) $%2.2f/hr\n", BASE_PAY_4);
				printf ("e) quit\n");
				printf ("*****************************************************************\n");
				continue;				// 跳出本次循环，进行下次循环 
		}

		printf ("Enter your work time in hour:\n");
        while (scanf ("%f", &time) != 1)
		{
            while (getchar () != '\n')
                continue;   // consume the '\n'
			printf ("You should enter a number!\n");
		    printf ("Enter your work time in hour:\n");
		}
        while (getchar () != '\n')
            continue;       // consume the '\n'
		
        if (time > LIMIT)
			time += (time - LIMIT) * OVERTIME;
		salary = base_pay * time;				// 未交税的工资
		if (salary < 300) 
			tax = salary * FIRST_300;
		else if (salary < 450)
			tax =  FIRST_300 * 300 + (salary - 300) * NEXT_150;
		else
			tax = FIRST_300 * 300 + 150 * NEXT_150 + (salary - 450) * EXTRAL;
        printf ("salary = %.2f\ntax = %.2f\nclear_salary = %.2f\n\n", salary, tax, salary - tax);

        printf ("*****************************************************************\n");
		printf ("Enter another letter corresponding to the desired pay rate or action:\n");
		printf ("a) $%2.2f/hr             ", BASE_PAY_1);
		printf ("b) $%2.2f/hr\n", BASE_PAY_2);
		printf ("c) $%2.2f/hr            ", BASE_PAY_3);
		printf ("d) $%2.2f/hr\n", BASE_PAY_4);
		printf ("e) quit\n");
		printf ("*****************************************************************\n");	
	}
    printf ("Bye!\n");

	return 0;
}
