/*
 * heap.h
 *
 *  Created on: 2020Äê6ÔÂ17ÈÕ
 *      Author: zhuhua
 */

#ifndef HEAP_H_
#define HEAP_H_

#include "HuffmanTreeNode.h"
//#include "HuffmanTree.h"

#define DBG false

typedef int boolean;
#define true 1
#define false 0

// get the data type info(including type, size, printData function), and the data must has comparable element named Weight
#define ElementType HuffmanTree // given by the TreeNode.h
#define SizeOfElement SizeOfHuffmanTree // given by the TreeNode.h
#define pPrintElementValue printTreeNode; // given by the TreeNode.h

typedef void (*pPrintElementFunc)(ElementType); // declare the print function pointer
//void (*pPrintElementFunc2)(ElementType); // this is a define, define a function pointer

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
