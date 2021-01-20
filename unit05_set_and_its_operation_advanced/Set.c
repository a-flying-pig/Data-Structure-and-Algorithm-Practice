/*
 * Set.c
 *
 *  Created on: 2020��7��7��
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
	return X; // ���ص���������index������Data
}*/

// ����·��ѹ������һ�����findЧ��
int Find(SetType S[], int X) {
	if (X < 0 || X > MaxSize) {
		printf("can not find %d\n", tmp);
		return -1;
	}

	if (S[X] < 0) {
		return X;
	} else {
		return S[X] = Find(S, S[X]); // ���ӽڵ㶼�㼯��һ�����ڵ��ϣ���ߺ���findЧ�ʡ����⣬β�ݹ飬���������Ż�Ϊѭ����
		                             // �������ջ���
	}

	return X; // ���ص���������index������Data
}

void Union(SetType S[], ElementType X1, ElementType X2) {
	int root1 = Find(S, X1 - 1); // ��һ����data��Ӧ��index
	int root2 = Find(S, X2 - 1); // ��һ����data��Ӧ��index
	if (root1 != root2) {
		if (root1 < root2) { // ���ȹ鲢���������˻�����������findЧ�ʽ���(�ȴ�С���ȱȸ߶ȸ��ʺ���·��ѹ��һ����)
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

