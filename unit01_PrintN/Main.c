/*
 * Main.c
 *
 *  Created on: 2020Äê3ÔÂ12ÈÕ
 *      Author: zhuhua
 */
#include <stdio.h>

void printN(int n);
void printN1(int n);

int main(){
	int N = 0;
	scanf("%d",&N);
 	printN1(N);
	return 0;
}
void printN(int n){

	if(n >0){

	    printN(n - 1);
	    printf("%d \n",n);
	}
}

void printN2(int n){

	if(n < 1){
		return;
	}
	printN(n - 1);
	printf("%d \n",n);
}

void printN1(int n) {
	for(int i = 1; i <= n; i++) {
		printf("%d\n", i);
	}
}

