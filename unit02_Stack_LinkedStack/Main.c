/*
 * Main.c
 *
 *  Created on: 2020Äê5ÔÂ15ÈÕ
 *      Author: zhuhua
 */
#include <stdio.h>
#include "LinkedStack.h"

int main() {
	Stack stack = createStack();
	for(int i = 0; i < 6; i++)
		push(stack, i);
	printStack(stack);
	for(int i = 0; i < 3; i++) {
		ElementType item = pop(stack);
		if(item != NULL)
			printf("pop stack:%d\n", item);
	}
	printStack(stack);
}
