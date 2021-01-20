/*
 * MinHeap.c
 *
 *  Created on: 2020Äê7ÔÂ2ÈÕ
 *      Author: zhuhua
 */
#include <stdio.h>
#include <stdlib.h>
#include "MinHeap.h"

MinHeap createMinHeap(int MaxSize) {
	MinHeap heap = (MinHeap) malloc(sizeof(struct sMinHeap));
	heap->data = malloc(sizeof(ElementType) * (MaxSize + 1));
	heap->size = 0;
	heap->capacity = MaxSize;
	heap->data[0] = -1000; /* this is guard element */
	return heap;
}
void insertMinHeap(ElementType e, MinHeap heap) {
	if (isFull(heap)) {
		printf("The heap is full, can not insert\n");
		return;
	}
	heap->size++;
	heap->data[heap->size] = e; /* insert the element to the last */
	int i = heap->size; /* change the position of elements */
	for (; e < heap->data[i / 2]; i = i / 2) {
		heap->data[i] = heap->data[i / 2];
	}
	heap->data[i] = e;
}
ElementType deleteMinHeap(MinHeap heap) {
	if (isEmpty(heap)) {
		printf("The heap it empty, no element to delete\n");
		return (ElementType)NULL;
	}
	//printf("deleteMinHeap: heap->size = %d \n", heap->size);
	ElementType item = heap->data[1]; /* get the smallest element */
	heap->data[1] = heap->data[heap->size]; /* set the last one to the first element */
	heap->size--;
	ElementType firstItem = heap->data[1];
	int i = 1;
	while (2 * i <= heap->size) {
		int child = 2 * i;
		/* get the largest child */
		if ((child + 1) <= heap->size
				&& heap->data[child + 1] < heap->data[child]) {
			child = child + 1;
		}
		//printf("deleteMinHeap:i=%d child=%d heap->size = %d \n", i, child, heap->size);
		/* swap the child to the parent */
		if (heap->data[child] < firstItem) {
			heap->data[i] = heap->data[child];
			i = child;
			//printf("deleteMinHeap: swap child: i=%d child=%d\n", i, child);
		} else {
			//printf("deleteMinHeap: break: i=%d child=%d\n", i, child);
			break;
		}
	}
	heap->data[i] = firstItem;

	return item;
}
int isEmpty(MinHeap heap) {
	if (!heap) {
		printf("isEmpty:the heap is null!!!\n");
		return 0;
	}
	if (heap->size == 0) {
		return 1;
	} else {
		return 0;
	}
}
int isFull(MinHeap heap) {
	if (!heap) {
		printf("isFull:the heap is null!!!\n");
		return 0;
	}
	if (heap->size == heap->capacity) {
		return 1;
	} else {
		return 0;
	}
}
void printMinHeap(MinHeap heap) {
	printf("printMinHeap:\n");
	if (!heap) {
		printf("printMinHeap:the heap is null!!!\n");
	}
	for (int i = 0; i < heap->size; i++) {
		printf("%d ", heap->data[i + 1]);
	}
	printf("\n");
}
