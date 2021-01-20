/*
 * TestAVLTree.c
 *
 *  Created on: 2020年6月5日
 *      Author: zhuhua
 */
#include <stdio.h>
#include <stdlib.h>
#include "AVLTree.h"

int main() {
	setvbuf(stdout, NULL, _IONBF, 0); // 用于输出缓存
	/*	AVLTree avl = (AVLTree) malloc(sizeof(struct AVLNode));
	 avl->Data = 3;
	 avl->Left = avl->Right = NULL;

	 printf("height %d \n", GetHeight(avl));

	 AVLTree avlL = (AVLTree) malloc(sizeof(struct AVLNode));
	 avlL->Data = 2;
	 avlL->Left = avlL->Right = NULL;
	 avl->Left = avlL;

	 printf("height %d\n", GetHeight(avl));

	 AVLTree avlR = (AVLTree) malloc(sizeof(struct AVLNode));
	 avlR->Data = 4;
	 avlR->Left = avlR->Right = NULL;
	 avl->Right = avlR;
	 printf("height %d\n", GetHeight(avl));

	 AVLTree avlRR = (AVLTree) malloc(sizeof(struct AVLNode));
	 avlRR->Data = 5;
	 avlRR->Left = avlRR->Right = NULL;
	 avlR->Right = avlRR;
	 printf("height %d\n", GetHeight(avl));*/

	AVLTree T = NULL;
	T = Insert(T, 6);
	printf("printTree: \n");
	printTree(T);
	printf("\n");


	T = Insert(T, 5);
	printf("printTree: \n");
	printTree(T);
	printf("\n");

	T = Insert(T, 4);
	printf("printTree : \n");
	printTree(T);
	printf("\n");

	T = Insert(T, 3);
	printf("printTree: \n");
	printTree(T);
	printf("\n");

	T = Insert(T, 2);
	T = Insert(T, 1);
	T = Insert(T, 0);

	T = Insert(T, 8);
	T = Insert(T, 9);
	T = Insert(T, 10);

	printf("printTree T: \n");
	printTree(T);
	printf("\n");

	printf("height T's Data: %d\n", T->Data);
	printf("height T %d\n", GetHeight(T));

	return 0;
}
