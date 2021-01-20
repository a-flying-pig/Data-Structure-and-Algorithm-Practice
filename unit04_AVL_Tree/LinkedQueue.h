/*
 * LinkedQueue.h
 *
 *  Created on: 2020Äê4ÔÂ4ÈÕ
 *      Author: zhuhua
 */

#ifndef LINKEDQUEUE_H_
#define LINKEDQUEUE_H_

#include <stdio.h>
#include <stdbool.h>

#include "AVLTree.h"

#define DBG false

typedef AVLTree ElementTypeQ;

typedef struct Node* PNode;
struct Node {
	ElementTypeQ Data;
	struct Node* next;
};

typedef struct LinkedQueue* Queue;
struct LinkedQueue {
	PNode front;
	PNode rear;
};

Queue createQueue();
bool enque(Queue queue, ElementTypeQ item);
ElementTypeQ deque(Queue queue);
void printQueue(Queue queue);
bool isFull(Queue queue);
bool isEmpty(Queue queue);


#endif /* LINKEDQUEUE_H_ */
