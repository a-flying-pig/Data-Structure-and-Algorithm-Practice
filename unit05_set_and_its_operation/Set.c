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

SetType* CreatSetType(int size) {
	MaxSize = size;
	SetType* Set = malloc(sizeof(SetType) * MaxSize);
	for (int i = 0; i < MaxSize; i++) {
		Set[i].Data = i + 1;
		Set[i].parent = -1;
	}
	return Set;
}
int Find(SetType S[], ElementType X) {
	int i;
	for (i = 0; i < MaxSize && S[i].Data != X; i++);
	if (i == MaxSize) {
		printf("can not find %d\n", X);
		return -1;
	}

	for (; S[i].parent >= 0; i = S[i].parent);
	return i;
}
void Union(SetType S[], ElementType X1, ElementType X2) {
	int root1 = Find(S, X1);
	int root2 = Find(S, X2);
	if (root1 != root2) {
		if (root1 < root2) { // 按秩归并，避免树退化成链表，导致find效率降低
			S[root1].parent += S[root2].parent;
			S[root2].parent = root1;
		} else {
			S[root2].parent += S[root1].parent;
			S[root1].parent = root2;
		}
	}

}

void PrintSetType(SetType S[]) {
	printf("printSetType:\n");
	for (int i = 0; i < MaxSize; i++) {
		printf("index:%d, Data:%d, parent:%d\n", i, S[i].Data, S[i].parent);
	}
}

