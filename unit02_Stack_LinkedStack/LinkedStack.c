#include <stdio.h>
#include <stdbool.h>
#include "LinkedStack.h"

Stack createStack() {
	Stack s;
	s = (Stack) malloc(sizeof(struct SNode));
	s->Data = NULL;
	s->Next = NULL;
	return s;
}
bool push(Stack s, ElementType item) {
	Stack node;
	node = (Stack) malloc(sizeof(struct SNode));
	if (node == NULL)
		return false;
	node->Data = item;
	node->Next = s->Next;
	s->Next = node;
	return true;
}
ElementType pop(Stack s) {
	Stack tmp = s->Next;
	if(tmp == NULL) {
		printf("stack is empty!\n");
		return NULL;
	}
	s->Next =tmp->Next;
	ElementType item = tmp->Data;
	free(tmp);
	return item;
}

void printStack(Stack s) {
	printf("Stack:");
	if(s->Next == NULL)
		printf("Stack is empty");
	while(s->Next != NULL) {
		printf("%d ", s->Next->Data);
		s = s->Next;
	}
	printf("\n");
}
