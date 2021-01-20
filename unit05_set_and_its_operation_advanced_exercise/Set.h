/*
 * Set.h
 *
 *  Created on: 2020Äê7ÔÂ7ÈÕ
 *      Author: zhuhua
 */
#ifndef TEST_H_
#define TEST_H_

#define ElementType int

typedef int SetType;

 extern int MaxSize;

SetType* CreateSetType(int size);
int Find(SetType S[], ElementType X);
void Union(SetType S[], ElementType X1, ElementType X2);
void PrintSetType(SetType S[]);

#endif /* TEST_H_ */

