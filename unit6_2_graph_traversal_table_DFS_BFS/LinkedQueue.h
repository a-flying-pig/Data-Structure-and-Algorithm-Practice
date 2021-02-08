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
#include "graph_table.h"
#define DBG false

//typedef int ElementType;
typedef Vertex ElementType;

typedef struct Node* PNode;
struct Node {
	ElementType Data;
	struct Node* next;
};

typedef struct LinkedQueue* Queue;
struct LinkedQueue {
	PNode front;
	PNode rear;
};

Queue createQueue();
bool enque(Queue queue, ElementType item);
ElementType deque(Queue queue);
void printQueue(Queue queue);
bool isFull(Queue queue);
bool isEmpty(Queue queue);


#endif /* LINKEDQUEUE_H_ */
