/*
 *  编写一个计算乘幂的给予命令行的程序。第一个命令行参数为double类型数，
 *  作为幂的底;第二个参数为整数，作为幂的指数。
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

 int main (int argc, char *argv[])
 {
 	double a = atof (argv[1]);
 	int b = atoi (argv[2]);
 	double ans = pow (a, b);

 	printf ("pow(a, b) = %lf\n", ans);

 	return 0;
 }

 /*

[alex@EX chapter11]$ ./a.out 1.1 9
pow(a, b) = 2.357948
[alex@EX chapter11]$ ./a.out 0.9 9
pow(a, b) = 0.387420
 
 */