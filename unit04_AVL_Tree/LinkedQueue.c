/*
 * LinkedQueue.c
 *
 *  Created on: 2020年4月4日
 *      Author: zhuhua
 */
#include <stdlib.h>
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

bool enque(Queue queue, ElementTypeQ item) {
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

	if(DBG) printf("enque item:%d\n", item->Data);
	return true;
}

ElementTypeQ deque(Queue queue) {
    if(isEmpty(queue)) {
    	printf("in deque:queue is empty, no element return.\n");
    	return NULL;
    }
    //printf("in deque: 1 \n");
    PNode node = queue->front;
    //printf("in deque:2  %x  \n", node);
    ElementTypeQ item = node->Data;
    //printf("in deque:3  %x  \n", item);
    queue->front = node->next;
   // printf("in deque:4  %x  \n", queue->front);
    free(node); // 这里不知为什么有时会失败，卡死在这里
    //printf("in deque:4.2  %x  \n", node);
    node = NULL;
   // printf("in deque:5   \n");
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
		printf("%d ", node->Data->Data);
		node = node->next;
	}
	printf("\n");
}

bool isFull(Queue queue) {
	return false;// never full,unless can not malloc space
}

bool isEmpty(Queue queue) {
	if(DBG) printf("isEmpty queue->front:%p\n", queue->front);
	return (!queue->front);
}

