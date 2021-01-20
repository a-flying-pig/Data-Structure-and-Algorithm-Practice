/*
 * Main.c
 *
 *  Created on: 2020年6月17日
 *      Author: zhuhua
 */
#include <stdio.h>
#include <stdlib.h>

// 函数指针变量的声明：typedef int (*fun_ptr)(int, int); // 声明一个指向同样参数、返回值的函数指针类型

/*int max1(int x, int y)
{
	return x > y ? x : y;
}

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);// 用于输出缓存
	int (*p) (int, int) = &max1; // can omit &;
	int a = 1, b = 2, c = 3, d, e;
	//printf("please input 3 numbers:");
	//scanf("%d %d %d", &a, &b, &c);

	d = p(p(a, b), c);
    e = max1(max1(a, b), c);
	printf("the max number is :%d\n", d);
	printf("the max number is :%d\n", e);
	return 0;
}*/

void populate_array(int *array, size_t arraySize, int (*getNextValue)(int))
{
	for(size_t i = 0; i < arraySize; i++)
		array[i] = getNextValue(3);
}

int getNextRandomValue(int n) {
	return rand();
}

int printResult(int n) {
	if (n > 0) {
		printf("n is %d\n", n);
		return 0;
	} else {
		printf("n is %d\n", n);
		return -1;
	}
}

void printChar() {
	printf("this is printChar\n");
}

//typedef (int (*Callback)(int)) Callback;

typedef struct methods {
	int (*printR)(int);
	void (*printC)();
} Interfase;

void printTest(int n, Interfase sInterfase) {
	sInterfase.printR(n);
	sInterfase.printC();
}

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);// 用于输出缓存

	int myarray[10];
	populate_array(myarray, 10, getNextRandomValue);
	for (int i = 0; i < 10; i++)
		printf("%d ", myarray[i]);
	printf("\n");
/*
	41 18467 6334 26500 19169 15724 11478 29358 26962 24464
	this is printChar
	n is 5*/

	Interfase sInterfase = {printResult, printChar};
	printTest(5, sInterfase);


	return 0;
}
