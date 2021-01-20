/*
 * Main.c
 *
 *  Created on: 2020Äê4ÔÂ4ÈÕ
 *      Author: zhuhua
 */

#include "LinkedQueue.h"

int main() {
	setvbuf(stdout,NULL,_IONBF,0);
	Queue q = createQueue();
	for (int i = 0; i < 10; i++)
	    enque(q, i);
	printf("after enque:\n");
	printQueue(q);

	for(int i =  0; i < 5; i++)
	    printf("deque %d: %d\n", i, deque(q));
	printf("after deque:\n");
	printQueue(q);

	for (int i = 10; i < 15; i++)
	    enque(q, i);
	printf("after enque again:\n");
	printQueue(q);

	for(int i =  0; i < 20; i++){
		ElementType item = deque(q);
		if(item == NULL)
			break;
		printf("deque %d: %d\n", i, item);
	}
	return 0;
}

