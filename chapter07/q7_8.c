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
    _Bool suc_in;       // 是否成功输入
	
	printf ("*****************************************************************\n");
	printf ("Enter the number corresponding to the desired pay rate or action:\n");
	printf ("1) $%2.2f/hr             ", BASE_PAY_1);
	printf ("2) $%2.2f/hr\n", BASE_PAY_2);
	printf ("3) $%2.2f/hr            ", BASE_PAY_3);
	printf ("4) $%2.2f/hr\n", BASE_PAY_4);
	printf ("5) quit\n");
	printf ("*****************************************************************\n");
    
	while (1)	
	{
        suc_in = (scanf ("%d", &level) ==  1);
        if (!suc_in)        // 若未能成功输入，（输入的不是数字）则提示输入，进行下次循环
        {
            while (getchar () != '\n')
                continue;           // consume the left input
	        printf ("*****************************************************************\n");
        	printf ("Enter the number corresponding to the desired pay rate or action!\n");
        	printf ("1) $%2.2f/hr             ", BASE_PAY_1);
        	printf ("2) $%2.2f/hr\n", BASE_PAY_2);
        	printf ("3) $%2.2f/hr            ", BASE_PAY_3);
        	printf ("4) $%2.2f/hr\n", BASE_PAY_4);
        	printf ("5) quit\n");
	        printf ("*****************************************************************\n");
            continue;       // 跳过本次循环剩余部分，开始下次循环
        }
		if (level == 5)
		{
			printf ("Bye!\n");
			break;	
		} 			
		switch (level)
		{
			case 1:
				base_pay = BASE_PAY_1;
				break;
			case 2:
				base_pay = BASE_PAY_2;
				break;
			case 3:
				base_pay = BASE_PAY_3;
				break;
			case 4:
				base_pay = BASE_PAY_4;
				break;
			default:
				printf ("Please enter the right number!\n");
				printf ("*****************************************************************\n");
				printf ("Enter the number corresponding to the desired pay rate or action:\n");
				printf ("1) $%2.2f/hr             ", BASE_PAY_1);
				printf ("2) $%2.2f/hr\n", BASE_PAY_2);
				printf ("3) $%2.2f/hr            ", BASE_PAY_3);
				printf ("4) $%2.2f/hr\n", BASE_PAY_4);
				printf ("5) quit\n");
				printf ("*****************************************************************\n");
				continue;				// 跳出本次循环，进行下次循环 
		}
		printf ("Enter your work time in hour:\n");
        while (scanf ("%f", &time) != 1)
        {
            while (getchar () != '\n')
                continue;
            printf ("You should enter a number!\n");
        }
        while (getchar () != '\n')
            continue;       // consume the left input
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
		printf ("Enter another number corresponding to the desired pay rate or action:\n");
		printf ("1) $%2.2f/hr             ", BASE_PAY_1);
		printf ("2) $%2.2f/hr\n", BASE_PAY_2);
		printf ("3) $%2.2f/hr            ", BASE_PAY_3);
		printf ("4) $%2.2f/hr\n", BASE_PAY_4);
		printf ("5) quit\n");
		printf ("*****************************************************************\n");	
	}

	return 0;
}
