/*
 * LinkedStack.h
 *
 *  Created on: 2020Äê5ÔÂ15ÈÕ
 *      Author: zhuhua
 */

#ifndef LINKEDSTACK_H_
#define LINKEDSTACK_H_

#include <stdio.h>
#include <stdbool.h>

typedef struct SNode* Stack;
typedef int ElementType;

struct SNode {
	ElementType Data;
    struct SNode* Next;
};

Stack createStack();
bool push(Stack s, ElementType item);
ElementType pop(Stack s);
void printStack(Stack s);


#endif /* LINKEDSTACK_H_ */
