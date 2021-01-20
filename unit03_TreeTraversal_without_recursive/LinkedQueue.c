/*
 * LinkedQueue.c
 *
 *  Created on: 2020Äê4ÔÂ4ÈÕ
 *      Author: zhuhua
 */
#include "LinkedQueue.h"

Queue createQueue() {
    Queue queue = (Queue) malloc(sizeof(struct LinkedQueue));
    if(queue == NULL) {
    	printf("create Queue failed for malloc failed!\n");
    	return NULL;
    }
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

bool enque(Queue queue, ElementType item) {
	PNode node = (PNode) malloc(sizeof(struct Node));
	node->Data = item;
	node->next = NULL;

	if(queue->front == NULL) {// queue is null
		queue->front = node;
	}
	if(queue->rear == NULL) { // queue is null
		queue->rear= node;
	} else {
		queue->rear->next = node;
		queue->rear = node;
	}

	if(DBG) printf("enque item:%d\n", item);
	return true;
}

ElementType deque(Queue queue) {
    if(isEmpty(queue)) {
    	printf("in deque:queue is empty, no element return.\n");
    	return NULL;
    }
    PNode node = queue->front;
    ElementType item = node->Data;
    queue->front = node->next;
    free(node);
	return item;
}

void printQueue(Queue queue) {
    if(isEmpty(queue)) {
    	printf("in printQueue:queue is empty, no element to print.\n");
    	return ;
    }
	PNode node = queue->front;
	printf("printQueue: ");
	if(DBG) printf("printQueue node:%p\n", node);
	while(node != NULL) {
		printf("%d ", node->Data);
		node = node->next;
	}
	printf("\n");
}

bool isFull(Queue queue) {
	return false;// never full,unless can not malloc space
}

bool isEmptyQueue(Queue queue) {
	if(DBG) printf("isEmpty queue->front:%p\n", queue->front);
	return (!queue->front);
}

