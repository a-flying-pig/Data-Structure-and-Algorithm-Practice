/*
 * Main.c
 *
 *  Created on: 2020年5月29日
 *      Author: zhuhua
 */
#include <stdio.h>
#include <stdlib.h>
#include "BinTree.h"
int main() {
	setvbuf(stdout, NULL, _IONBF, 0);// 用于输出缓存
	BinTree BT = (BinTree) malloc(sizeof(struct TreeNode));
	BT->Data = 5;
	BT->Left = NULL;
	BT->Right = NULL;
	BinTree a = (BinTree) malloc(sizeof(struct TreeNode));
	a->Data = 3;
	a->Left = NULL;
	a->Right = NULL;
	BinTree b = (BinTree) malloc(sizeof(struct TreeNode));
	b->Data = 6;
	b->Left = NULL;
	b->Right = NULL;
/*	BinTree c = (BinTree) malloc(sizeof(struct TreeNode));
	c->Data = 8;
	c->Left = NULL;
	c->Right = NULL;*/
	BT->Left = a;
	BT->Right = b;
	printBinTree(BT);
	printf("\n");
/*
	BinTree Insert(ElementType X, BinTree BST);
	void printBinTree(BinTree BST);
	BinTree Find(ElementType X, BinTree BST);
	BinTree FindMax(BinTree BST);
	BinTree FindMin(BinTree BST);
	BinTree Delete(ElementType X, BinTree BST);
*/
	BT = Insert(4, BT);
	BT = Insert(8, BT);
	BT = Insert(9, BT);
	BT = Insert(10, BT);
	printf("print BT after Insert:\n");
	printBinTree(BT);
	printf("\n");
	printf("print Find(8, BT):\n");
	printf("%d", Find(8, BT)->Data);
	printf("\n");
	printf("print FindMax(BT):\n");
	printf("%d", FindMax(BT)->Data);
	printf("\n");
	printf("print FindMin(BT):\n");
	printf("%d", FindMin(BT)->Data);
	printf("\n");

	printf("print Delete(8, BT):\n");
	printBinTree(Delete(8, BT));
	printf("\n");
	printf("print Delete(3, BT):\n");
	printBinTree(Delete(3, BT));
	printf("\n");
	printf("print Delete(10, BT):\n");
	printBinTree(Delete(10, BT));
	printf("\n");

	printf("print Delete(1, BT):\n");
	printBinTree(Delete(1, BT));
	printf("\n");

	return 0;
}

