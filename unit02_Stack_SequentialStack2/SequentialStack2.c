/*
 * SequentialStack.c
 *
 *  Created on: 2020年4月1日
 *      Author: zhuhua
 */

#include <stdbool.h>
#define MaxSize 5
typedef char ElementType;
typedef struct SNode *Stack;
Stack CreateStack();
bool Push(Stack PtrS, ElementType item, int tag); // 0代表stack1，1代表stack2
ElementType Pop(Stack PtrS, int tag);
void PrintStack(Stack PtrS, int tag);

int main() {

	Stack stack = CreateStack();
	Push(stack, 'A', 0);
	Push(stack, 'B', 0);
	Push(stack, 'C', 0);
	PrintStack(stack, 0);
	Push(stack, 'A', 1);
	Push(stack, 'B', 1);
	Push(stack, 'C', 1);
	PrintStack(stack, 1);
	printf("pop  :%c\n", Pop(stack, 0));
	printf("pop  :%c\n", Pop(stack, 0));
	printf("pop  :%c\n", Pop(stack, 0));
	printf("pop  :%c\n", Pop(stack, 0));
	return 0;
}

struct SNode{
    ElementType Data[MaxSize];
    int Top1;
    int Top2;
};

Stack CreateStack() {
	Stack S = (Stack)malloc(sizeof(struct SNode));
	S->Top1 = -1;
	S->Top2 = MaxSize;
	return S;
}

bool Push(Stack PtrS, ElementType item, int tag) {
	if((PtrS->Top2 - PtrS->Top1) == 1) {
		printf("stack is packed\n");
		return false;
	} else {
		if (tag == 0) {
			PtrS->Data[++(PtrS->Top1)] = item;
			return true;
		} else {
			PtrS->Data[--(PtrS->Top2)] = item;
			return true;
		}

	}
}

#define ERROR -1;
ElementType Pop(Stack PtrS, int tag) {
	//printf("in pop\n");
	if (tag == 0) {
		if(PtrS->Top1 == -1) {
			printf("in pop, stack1 is empty\n");
			return ERROR;
		} else {
			ElementType tmp;
			tmp = PtrS->Data[(PtrS->Top1)--];
			//printf("in pop tmp:%c\n", tmp);
			return tmp;
		}
	} else {
		if(PtrS->Top2 == MaxSize) {
			printf("in pop, stack2 is empty\n");
			return ERROR;
		} else {
			ElementType tmp;
			tmp = PtrS->Data[(PtrS->Top1)++];
			//printf("in pop tmp:%c\n", tmp);
			return tmp;
		}
	}

}

void PrintStack(Stack PtrS, int tag) {
	if (tag == 0) {
		printf("Stack1:");
		for(int i = 0; i <= PtrS->Top1; i++) {
			printf("%c ", PtrS->Data[i]);
		}
		printf("\n");
	} else {
		printf("Stack2:");
		for(int i = MaxSize - 1; i >= PtrS->Top2; i--) {
			printf("%c ", PtrS->Data[i]);
		}
		printf("\n");
	}

}


