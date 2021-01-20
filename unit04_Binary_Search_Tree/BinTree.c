/*
 * BinTree.c
 *
 *  Created on: 2020年5月29日
 *      Author: zhuhua
 */
#include <stdio.h>
#include <stdlib.h>
#include "BinTree.h"

BinTree Insert(ElementType X, BinTree BST) {
	if (!BST) {
		BST = (BinTree) malloc(sizeof(struct TreeNode));
		BST->Data = X;
		BST->Left = NULL;
		BST->Right = NULL;
	} else if (X < BST->Data) {
		//printf("X < BST->Data %d \n", BST->Data);
		BST->Left = Insert(X, BST->Left); // 做了插入的动作
	} else if (X > BST->Data) {
		//printf("X > BST->Data %d \n", BST->Data);
		//return BST->Right = Insert(X, BST->Right);
		BST->Right = Insert(X, BST->Right); // 做了插入的动作
	} else { // X 已经存在，什么都不做
		printf("The %d is already exist\n", X);
	}
	return BST;
}

void printBinTree(BinTree BST) {
	if (BST) {
		printBinTree(BST->Left);
		printf("%d ", BST->Data);
		printBinTree(BST->Right);
	}

}
BinTree Find(ElementType X, BinTree BST) {
	if (!BST) {
		printf("There is no X in BST!");
		return NULL;
	}
	if (X < BST->Data) {
		return Find(X, BST->Left);
	} else if (X > BST->Data) {
		return Find(X, BST->Right);
	} else {
		return BST;
	}
}
BinTree FindMax(BinTree BST) {
	if(!BST) return BST;
	if (BST->Right) {
		return FindMax(BST->Right);
	} else {
		return BST;
	}
}
BinTree FindMin(BinTree BST) {
	if(!BST) return BST;
	while (BST->Left) {
		BST = BST->Left;
	}
	return BST;
}
BinTree Delete(ElementType X, BinTree BST) {
	Position temp;
	if (!BST) {
		printf("There is no %d in BST!\n", X);
		return NULL;
	}
	if (X < BST->Data) {
		BST->Left = Delete(X, BST->Left);
	} else if (X > BST->Data) {
		BST->Right = Delete(X, BST->Right);
	} else {
		if (BST->Left && BST->Right) {
			BinTree leftMax = FindMax(BST->Left);
			BST->Data = leftMax->Data;
			BST->Left = Delete(BST->Data, BST->Left);
		}
		temp = BST;
		if (!BST->Left) {
			BST = BST->Right;
			free(temp);
		} else if (!BST->Right) {
			BST = BST->Left;
			free(temp);
		}
	}
	return BST;
}

