/*
 * MinHeap.h
 *
 *  Created on: 2020Äê7ÔÂ2ÈÕ
 *      Author: zhuhua
 */

#ifndef MINHEAP_H_
#define MINHEAP_H_

#define ElementType int
typedef struct sMinHeap* MinHeap;
struct sMinHeap {
	ElementType* data;
    int size;
    int capacity;
};

MinHeap createMinHeap(int MaxSize);
void insertMinHeap(ElementType e, MinHeap heap);
ElementType deleteMinHeap(MinHeap heap);
int isEmpty(MinHeap heap);
int isFull(MinHeap heap);
void printMinHeap(MinHeap heap);

#endif /* MINHEAP_H_ */
