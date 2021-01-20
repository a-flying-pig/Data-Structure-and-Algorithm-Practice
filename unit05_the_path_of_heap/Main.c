/*
 * Main.c
 *
 *  Created on: 2020Äê7ÔÂ2ÈÕ
 *      Author: zhuhua
 */
#include <stdio.h>
#include "MinHeap.h"

void printPath(int index, MinHeap H);
int main() {
	setvbuf(stdout, NULL, _IONBF, 0); // set no buffer
			/*	MinHeap heap = createMinHeap(5);
			 printMinHeap(heap);
			 insertMinHeap(5, heap);
			 insertMinHeap(4, heap);
			 insertMinHeap(3, heap);
			 insertMinHeap(2, heap);
			 insertMinHeap(1, heap);
			 insertMinHeap(6, heap);
			 printMinHeap(heap);

			 printf("deleteHeap:1 element: %d \n", deleteMinHeap(heap));
			 printMinHeap(heap);

			 printf("deleteHeap:2 element: %d \n", deleteMinHeap(heap));

			 printf("deleteHeap:3 element: %d \n", deleteMinHeap(heap));
			 printf("deleteHeap:4 element: %d \n", deleteMinHeap(heap));
			 printf("deleteHeap:5 element: %d \n", deleteMinHeap(heap));
			 printf("deleteHeap:6 element: %d \n", deleteMinHeap(heap));
			 printMinHeap(heap);*/

	MinHeap heap = createMinHeap(1000);
	int n1, n2;
	scanf("%d %d", &n1, &n2);
	//printf("n1=%d, n2=%d \n", n1, n2);
	int tmp;
	for(int i = 0; i < n1; i++) {
		scanf("%d", &tmp);
		insertMinHeap(tmp, heap);
		//printf("node %d: %d \n", i + 1, tmp);
	}

	for (int i = 0; i < n2; i++) {
		scanf("%d", &tmp);
		//printf("index %d: %d\n", i + 1, tmp);
		printPath(tmp, heap);
	}
	return 0;
}

void printPath(int index, MinHeap H) {
	for (int i = index; i > 0; i = i / 2 ) {
		printf("%d ", H->data[i]);
	}
	printf("\n");
}

