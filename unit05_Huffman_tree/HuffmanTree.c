/*
 * HuffmanTree.c
 *
 *  Created on: 2020年6月25日
 *      Author: zhuhua
 */
#include <stdio.h>
#include "HuffmanTree.h"

//#include "HuffmanTreeNode.h"

HuffmanTree BuildHuffmanTree(DataType* datas, int size) {
	// 把数据转换为一个个HuffmanTree节点，并存储到数组中trees
	HuffmanTree* trees = malloc(size * sizeof(HuffmanTree));
	//HuffmanTree trees[5];

	for (int i = 0; i < size; i++) {
		HuffmanTree tree = malloc(SizeOfHuffmanTree);
		tree->Left = NULL;
		tree->Right = NULL;
		tree->Weight = datas[i].Weight;
		tree->Value = datas[i].Value;
		trees[i] = tree;
	}

	// 将数组trees中的节点用堆排序
	MaxHeap H = CreateHeap(size);
	BuildHeap(trees, size, H);
	PrintHeap(H);

	// 依次从堆中取出2个节点（最小权值）合并，
	// 然后从新的节点与留存的节点中取出2个节点（最小权值）合并，直到最后2个节点合并
	for (int i = 0; i < size - 1; i++) {
		// 取2个权值最小的合并为一棵树
		HuffmanTree tree = malloc(SizeOfHuffmanTree);
		printf("BuildHuffmanTree 1\n");
        tree->Left = DeleteMax(H);
	    tree->Right = DeleteMax(H);
		printf("BuildHuffmanTree 2\n");
		tree->Weight = tree->Left->Weight + tree->Right->Weight;
		InsertHeap(H, tree);
		printf("BuildHuffmanTree 3\n");
	}
	HuffmanTree HT = (HuffmanTree)DeleteMax(H);
    printf("BuildHuffmanTree return HT\n");
    return HT;
}

void PrintHuffmanTree(HuffmanTree HT) {
	if (HT) {
		PrintHuffmanTree(HT->Left);
		printf("weight:%d \n", HT->Weight);
		if (!HT->Left && !HT->Right) { // 左右节点为空，说明为叶节点
			ElementType element= (ElementType) HT;
			printf("This leaf node. {%d, %c} \n", element->Weight, element->Value);
		}
		PrintHuffmanTree(HT->Right);
	}
}

