/*
 * Main.c
 *
 *  Created on: 1980年1月4日
 *      Author: zhuhua
 */
#include <stdio.h>
#include <stdlib.h>
#include "HuffmanTree.h"
#include "heap.h"

int main() {
	setvbuf(stdout, NULL, _IONBF, 0);// 用于输出缓存

	struct DataStruct nodes[5] = {{1, 'A'}, {2, 'B'}, {3, 'C'}, {4, 'D'}, {5, 'E'}};
	// 将权重取负值，最大堆实际就变成了最小堆
	for (int i = 0; i < sizeof(nodes)/sizeof(nodes[0]); i++) {
		nodes[i].Weight = -nodes[i].Weight;
	}
	printf("nodes[0]'s weight:%d value:%c\n", nodes[0].Weight, nodes[0].Value);

/*	HuffmanTree elements[5];
	for (int i = 0; i < 5; i++) {
		HuffmanTree huffmantree = malloc(sizeof(struct TreeNode));
		huffmantree->Left = NULL;
		huffmantree->Right = NULL;
        huffmantree->Weight = nodes[i].Weight;
        huffmantree->Value = nodes[i].Value;
        elements[i] = huffmantree;
	}
	printf("elements[0]'s weight:%d value:%c\n", elements[0]->Weight, elements[0]->Value);

	MaxHeap H = CreateHeap(5);
	BuildHeap(elements, sizeof(elements)/sizeof(elements[0]), H);
	PrintHeap(H);*/

	HuffmanTree HT = BuildHuffmanTree(nodes, sizeof(nodes)/sizeof(nodes[0]));
	PrintHuffmanTree(HT);

	return 0;
}

