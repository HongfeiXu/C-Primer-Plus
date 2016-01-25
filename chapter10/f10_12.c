/*
 *  double trots[20];
 *  short clops[10][30];
 *  long shots[5][10][15];
 *
 *  以传统的void函数方式，写出处理这三个数组的函数原型和函数调用;
 *  然后以变长数组方式，写出处理这三个数组的函数原型和函数调用。
 *
 * */

void fun(double trots[], int rows);
void fun2(short clops[][30], int rows);
void fun3(long shots[][10][15], int rows);

void fun_vla(int rows, double trots[rows]);
void fun2_vla(int rows, int cols, short clops[rows][cols]);
void fun3_vla(int a, int b, int c, long shots[a][b][c]);

fun (trots, 20);
fun2 (clops, 10);
fun3 (shots, 5);

fun_vla (20, trots);
fun2_vla (10, 30, clops);
fun3_vla (5, 10, 15, shots);
