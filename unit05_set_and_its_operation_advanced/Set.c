/*
 * Set.c
 *
 *  Created on: 2020年7月7日
 *      Author: zhuhua
 */
#include <stdlib.h>
#include <stdio.h>
#include "Set.h"

int MaxSize;

int tmp;

SetType* CreateSetType(int size) {
	MaxSize = size;
	SetType* Set = malloc(sizeof(SetType) * MaxSize);
	for (int i = 0; i < MaxSize; i++) {
		Set[i] = -1;
	}
	return Set;
}

/*int Find(SetType S[], int X) {
	if (X < 0 || X > MaxSize) {
		printf("can not find %d\n", tmp);
		return -1;
	}

	for ( ;S[X] >= 0; X = S[X]);
	return X; // 返回的是树根的index，不是Data
}*/

// 采用路径压缩，进一步提高find效率
int Find(SetType S[], int X) {
	if (X < 0 || X > MaxSize) {
		printf("can not find %d\n", tmp);
		return -1;
	}

	if (S[X] < 0) {
		return X;
	} else {
		return S[X] = Find(S, S[X]); // 将子节点都汇集到一个父节点上，提高后续find效率。另外，尾递归，编译器会优化为循环，
		                             // 不会造成栈溢出
	}

	return X; // 返回的是树根的index，不是Data
}

void Union(SetType S[], ElementType X1, ElementType X2) {
	int root1 = Find(S, X1 - 1); // 减一才是data对应的index
	int root2 = Find(S, X2 - 1); // 减一才是data对应的index
	if (root1 != root2) {
		if (root1 < root2) { // 按秩归并，避免树退化成链表，导致find效率降低(比大小，比比高度更适合与路径压缩一起用)
			S[root1] += S[root2];
			S[root2] = root1;
		} else {
			S[root2] += S[root1];
			S[root1] = root2;
		}
	}

}

void PrintSetType(SetType S[]) {
	printf("printSetType:\n");
	for (int i = 0; i < MaxSize; i++) {
		printf("index:%d, Data:%d, parent:%d\n", i, i  + 1, S[i]);
	}
}

