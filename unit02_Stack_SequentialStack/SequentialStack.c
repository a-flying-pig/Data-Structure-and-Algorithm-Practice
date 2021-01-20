/*
 * SequentialStack.c
 *
 *  Created on: 2020Äê4ÔÂ1ÈÕ
 *      Author: zhuhua
 */

#include <stdbool.h>
#define MaxSize 16
typedef char ElementType;
typedef struct SNode *Stack;
Stack CreateStack();
bool Push(Stack PtrS, ElementType item);
ElementType Pop(Stack PtrS);
void PrintStack(Stack PtrS);

int main() {

	Stack stack = CreateStack();
	Push(stack, 'A');
	Push(stack, 'B');
	Push(stack, 'C');
	PrintStack(stack);
	printf("pop  :%c\n", Pop(stack));
	printf("pop  :%c\n", Pop(stack));
	printf("pop  :%c\n", Pop(stack));
	printf("pop  :%c\n", Pop(stack));
	return 0;
}

struct SNode{
    ElementType Data[MaxSize];
    int Top;
};

Stack CreateStack() {
	Stack S = (Stack)malloc(sizeof(struct SNode));
	S->Top = -1;
	return S;
}

bool Push(Stack PtrS, ElementType item) {
	if(PtrS->Top == MaxSize - 1) {
		printf("stack is packed");
		return false;
	} else {
		PtrS->Data[++(PtrS->Top)] = item;
		return true;
	}
}

#define ERROR -1;
ElementType Pop(Stack PtrS) {
	//printf("in pop\n");
	if(PtrS->Top == -1) {
		printf("in pop, stack is empty\n");
		return ERROR;
	} else {
		ElementType tmp;
		tmp = PtrS->Data[(PtrS->Top)--];
		//printf("in pop tmp:%c\n", tmp);
		return tmp;
	}
}

void PrintStack(Stack PtrS) {
	printf("Stack:");
	for(int i = PtrS->Top; i >= 0; i--) {
		printf("%c ", PtrS->Data[i]);
	}
	printf("\n");
}


