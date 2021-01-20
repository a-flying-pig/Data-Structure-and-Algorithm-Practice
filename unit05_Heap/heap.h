/*
 * heap.h
 *
 *  Created on: 2020Äê6ÔÂ17ÈÕ
 *      Author: zhuhua
 */

#ifndef HEAP_H_
#define HEAP_H_

#define DBG false

typedef int boolean;
#define true 1
#define false 0

#define ElementType int
typedef struct HeapStruct* MaxHeap;

struct HeapStruct {
	ElementType* Data;
	int Size;
	int Capacity;
};

MaxHeap CreateHeap(int MaxSize);
void InsertHeap(MaxHeap H, ElementType item);
ElementType DeleteMax(MaxHeap H);
void BuildHeap(ElementType* elements, int size, MaxHeap H);
void PrintHeap(MaxHeap H);
boolean IsEmpty(MaxHeap H);
boolean IsFull(MaxHeap H);

#endif /* HEAP_H_ */
