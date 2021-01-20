/*
 * Main.c
 *
 *  Created on: 2020年3月17日
 *      Author: zhuhua
 */
#include <math.h>
#include <time.h>
#include <stdio.h>
#define MAXN 10 // 多项式最大橡树，即多项式阶数+1
#define MAXK 1e8 // 被测函数最大重复调用次数

clock_t start, stop;
double duration;
double f1(int n, double[], double x);
double f2(int n, double[], double x);

typedef double (*fun_t)(int, double[], double);
void testFunction(int n, double a[], double x, fun_t fun);
int main() {
	printf("MAXK = %f\n", MAXK);
    int i;
    double a[MAXN]; // 	存储多项式的系数
    for (i = 0; i < MAXN; i++) a[i] = (double) i;
    /*    start = (long)clock();
        //printf("start = %f\n", (double)start);
    for (i = 0; i < MAXK; i++) // 重复调用以获得充分多的时钟打点数
    	f1(MAXN-1, a, 1.1);
    stop = (long)clock();
   // printf("stop = %f\n", (double)stop);
    duration = ((double)(stop - start)) / CLK_TCK / MAXK ; // 计算函数单次运行的时间
    printf("ticks1 = %f\n", (double) (stop - start));
    printf("duration1 = %6.2e\n", duration);

    start = (long)clock;
    for (i = 0; i < MAXK; i++) // 重复调用以获得充分多的时钟打点数
    	f2(MAXN-1, a, 1.1);
    stop = (long)clock;
    duration = ((double)(stop - start)) / CLK_TCK;
    printf("ticks2 = %f\n", (double) (stop - start));
    printf("duration2 = %6.2e\n", duration);*/
	testFunction(MAXN - 1, a, 1.1, f1);
	testFunction(MAXN - 1, a, 1.1, f2);

	return 0;
}

void testFunction(int n, double a[], double x, fun_t fun) {
    start = (long)clock();
    //printf("start = %f\n", (double)start);
    for (int i = 0; i < MAXK; i++) // 重复调用以获得充分多的时钟打点数
    	fun(n, a, x);
    stop = (long)clock();
   // printf("stop = %f\n", (double)stop);
    duration = ((double)(stop - start)) / CLK_TCK / MAXK ; // 计算函数单次运行的时间
    printf("ticks1 = %f\n", (double) (stop - start));
    printf("duration1 = %6.2e\n	", duration);
    printf("----------------------------------\n");
}

double f1(int n, double a[], double x) {  // f(x) = ∑i=0 9 i*x^i
	int i;
	double p = a[0];
	for (i = 1; i <= n; i++)
		p += (a[i] * pow(x, i));
	return p;
}

double f2(int n, double a[], double x) {
	int i;
	double p = a[n];
	for (i = n; i > 0; i--)
		p = a[i - 1] + x * p;
	return p;
}

