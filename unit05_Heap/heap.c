/*
 * heap.c
 *
 *  Created on: 2020Äê6ÔÂ17ÈÕ
 *      Author: zhuhua
 */
#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

MaxHeap CreateHeap(int MaxSize) {
	MaxHeap H = (MaxHeap) malloc(sizeof(struct HeapStruct));
	H->Data = malloc((MaxSize + 1) * sizeof(ElementType));
	H->Data[0] = 10000;
	H->Size = 0;
	H->Capacity = MaxSize;
	return H;
}

void PercDown(MaxHeap H, int i) {
	int parent = i;
	int child = parent * 2;
	ElementType parentItem = H->Data[i];
	while (child <= H->Size) { // find the position of the parent
		// find out the largest child
		if ((child + 1) <= H->Size && H->Data[child + 1] > H->Data[child]) {
			child++;
		}
		if (parentItem < H->Data[child]) {
			H->Data[parent] = H->Data[child];
			parent = child;
			child = parent * 2;
		} else {
			break; // find the position
		}
	}
	H->Data[parent] = parentItem; // set the value to the find position
}

void BuildHeap(ElementType* elements, int size, MaxHeap H) {
#if defined DBG && DBG == true
    printf("BuildHeap size:%d  Heap Capacity:%d\n", size, H->Capacity);
#endif
	if (size > H->Capacity) {
		printf("The size of the elements is larger than Heap's Capacity, build failed!!!\n");
		return;
	}
	// 1.copy the elements into H, ensure it is a perfect tree
	for (int i = 0; i < size; i++) {
		H->Data[i + 1] = elements[i];
	}
	H->Size = size;
	// 2.from the last Parent node, downward  filtering the tree; ensure it is a sorted tree
	for (int i = (size / 2); i > 0; i--) {
		PercDown(H, i);
	}
}

void InsertHeap(MaxHeap H, ElementType item) {
	if (IsFull(H)) {
		printf("Heap is Full, can not insert more element!");
		return;
	}
	// set the item to the last of the tree, to ensure the heap is a perfect tree
	H->Data[++H->Size] = item;
	// change the position of item, to ensue the order of the tree
	int parent, child;
	child = H->Size;
	parent = child / 2;
	for (parent; H->Data[parent] < item; parent = child / 2) {
		H->Data[child] = H->Data[parent];
		child = parent;
	}
	H->Data[child] = item;
}

ElementType DeleteMax(MaxHeap H) {
	if (IsEmpty(H)) {
		printf("Heap is Empty, no element to Delete! return -1\n");
		return -1;
	}
	ElementType maxItem = H->Data[1]; // get the max element, in Data[1], Data[0] is a guard
	H->Data[1] = H->Data[H->Size--]; // move the last element to the first, to contain tree a perfect tree

	// downward filtering to contain tree a sorted tree
	int position = 1;
	int child = 2 * position;
	ElementType itemTop = H->Data[1];

	while (child <= H->Size) {
#if defined DBG && (DBG == true)
		printf("DeleteMax child:%d, (child + 1):%d, Data[child]:%d, Data[child + 1]:%d H->Size:%d\n", \
				child, child + 1, H->Data[child], H->Data[child + 1], H->Size);
#endif
		// find the larger one of the child
		if ((child + 1) <= H->Size && H->Data[child + 1] > H->Data[child]) { // has right child, and the right child id larger than child
#if defined DBG && DBG == true
		printf("DeleteMax child++\n");
#endif
			child++;
		}
		if (itemTop < H->Data[child]) {
			H->Data[position] = H->Data[child];
			position = child;
			child = 2 * position;
		} else { // find the proper position
			break;
		}
	}
	H->Data[position] = itemTop;
    return maxItem;
}

boolean IsEmpty(MaxHeap H) {
	if (H->Size == 0) {
		return true;
	} else {
		return false;
	}
}

boolean IsFull(MaxHeap H) {
	if (H->Size == H->Capacity) {
		return true;
	} else {
		return false;
	}
}

void PrintHeap(MaxHeap H) {
	printf("print Heap:");
	if (IsEmpty(H)) {
		printf("Heap is Empty!\n");
		return;
	}
	for (int i = 1; i <= H->Size; i++) {
		printf("%d ", H->Data[i]);
	}
	printf("\n");
}

