/*
 * HuffmanTree.c
 *
 *  Created on: 2020��6��25��
 *      Author: zhuhua
 */
#include <stdio.h>
#include "HuffmanTree.h"

//#include "HuffmanTreeNode.h"

HuffmanTree BuildHuffmanTree(DataType* datas, int size) {
	// ������ת��Ϊһ����HuffmanTree�ڵ㣬���洢��������trees
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

	// ������trees�еĽڵ��ö�����
	MaxHeap H = CreateHeap(size);
	BuildHeap(trees, size, H);
	PrintHeap(H);

	// ���δӶ���ȡ��2���ڵ㣨��СȨֵ���ϲ���
	// Ȼ����µĽڵ�������Ľڵ���ȡ��2���ڵ㣨��СȨֵ���ϲ���ֱ�����2���ڵ�ϲ�
	for (int i = 0; i < size - 1; i++) {
		// ȡ2��Ȩֵ��С�ĺϲ�Ϊһ����
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
		if (!HT->Left && !HT->Right) { // ���ҽڵ�Ϊ�գ�˵��ΪҶ�ڵ�
			ElementType element= (ElementType) HT;
			printf("This leaf node. {%d, %c} \n", element->Weight, element->Value);
		}
		PrintHuffmanTree(HT->Right);
	}
}

