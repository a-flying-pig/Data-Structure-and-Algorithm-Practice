/*
 * LinkedQueue.h
 *
 *  Created on: 2020年4月4日
 *      Author: zhuhua
 */

#ifndef LINKEDQUEUE_H_
#define LINKEDQUEUE_H_

#include <stdio.h>
#include <stdbool.h>
#include "Tree.h"
#define DBG false

typedef Tree ElementType; // 设置Queue元素类型为tree

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
bool isEmptyQueue(Queue queue);


#endif /* LINKEDQUEUE_H_ */
