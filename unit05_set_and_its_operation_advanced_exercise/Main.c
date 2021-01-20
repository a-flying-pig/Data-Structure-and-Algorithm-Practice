/*
 * Main.c
 *
 *  Created on: 2020年7月7日
 *      Author: zhuhua
 */
#include <stdio.h>
#include "Set.h"

void checkConnection(SetType* S);
void inputConnect(SetType* S);
void checkNetworks(SetType* S);

int main() {
	setvbuf(stdout, NULL, _IONBF, 0); // 用于输出缓存
	// 初始化集合
	int n;
	scanf("%d", &n);
	SetType* S = CreateSetType(n);
	//PrintSetType(S);
	char c;
	do {
		// 处理操作
		scanf("%c", &c);
		//printf("char is %c\n", c);
		switch (c) {
		case 'I': // 将两台计算机进行连接
			inputConnect(S);
			//PrintSetType(S);
			break;
		case 'C': // 检查是否连接
			checkConnection(S);
			break;
		case 'S': // 检查局域网数量
			checkNetworks(S);
			break;
		}

	} while (c != 'S'); // 判断是否结束

	return 0;
}

void inputConnect(SetType* S) {
	int a, b;
	scanf("%d %d", &a, &b);
	Union(S, a, b);
}

void checkConnection(SetType* S) {
	int a, b;
	scanf("%d %d", &a, &b);
	int root1 = Find(S, a - 1); // 减1才是对应的index
	int root2 = Find(S, b - 1);
	if (root1 == root2) {
		printf("they are connected, yes\n");
	} else {
		printf("they are connected, no\n");
	}
}


void checkNetworks(SetType* S) {
    int count = 0;
    for (int i = 0; i < MaxSize; i++) {
    	if (S[i] < 0) count++;
    }
    printf("the networks is : %d\n", count);
}
