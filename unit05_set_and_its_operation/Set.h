/*
 * Set.h
 *
 *  Created on: 2020��7��7��
 *      Author: zhuhua
 */
#ifndef TEST_H_
#define TEST_H_

#define ElementType int

typedef struct{
	ElementType Data;
	int parent;
} SetType;

 extern int MaxSize;

SetType* CreatSetType(int size);
int Find(SetType S[], ElementType X);
void Union(SetType S[], ElementType X1, ElementType X2);
void PrintSetType(SetType S[]);

#endif /* TEST_H_ */

