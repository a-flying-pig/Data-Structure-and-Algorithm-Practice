/*
 * Main.c
 *
 *  Created on: 2020Äê6ÔÂ17ÈÕ
 *      Author: zhuhua
 */
#include <stdio.h>
#include "heap.h"

int main()
{

/*	MaxHeap H = CreateHeap(5);
	PrintHeap(H);
	InsertHeap(H, 1);
	InsertHeap(H, 2);
	InsertHeap(H, 3);
	InsertHeap(H, 5);
	InsertHeap(H, 4);
	InsertHeap(H, 6);
	PrintHeap(H);
	int item = DeleteMax(H);
	printf("get max1: %d\n", item);
	int item2 = DeleteMax(H);
	printf("get max2: %d\n", item2);
	int item3 = DeleteMax(H);
	printf("get max3: %d\n", item3);
	InsertHeap(H, 6);
	printf("get max: %d\n", DeleteMax(H));
	printf("get max: %d\n", DeleteMax(H));
	printf("get max: %d\n", DeleteMax(H));*/

	printf("Test buildHeap method:\n");
	MaxHeap H1 = CreateHeap(5);
	int nums[4] = {1, 2, 3, 4};
    BuildHeap(nums, sizeof(nums) / sizeof(nums[0]), H1);
    PrintHeap(H1);
	printf("get H1 max: %d\n", DeleteMax(H1));
	PrintHeap(H1);
	printf("get H1 max: %d\n", DeleteMax(H1));
	PrintHeap(H1);
	printf("get H1 max: %d\n", DeleteMax(H1));
	PrintHeap(H1);
	printf("get H1 max: %d\n", DeleteMax(H1));
	PrintHeap(H1);
	return 0;
}


